#include <../../nrnconf.h>

#include "../nrnpython/nrnpython_config.h"
#include "hoc.h"
#include "hocstr.h"
#include "equation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include "parse.h"
#include "nrnmpi.h"
#include "nrnrt.h"
#if defined(__GO32__)
#include <dos.h>
#include <go32.h>
#endif

//#include "neurospaces/neurospaces.h"

#if defined(USE_PYTHON)
int use_python_interpreter = 0;
void (*p_nrnpython_start)();
#endif
int (*p_nrnpy_pyrun)(char* fname);

#if carbon
#include <pthread.h>
#endif

#define NRN_FLOAT_EXCEPTION (defined(SUN4)||defined(linux)) && 0
#if NRN_FLOAT_EXCEPTION
#if defined(SUN4)
#include <ieeefp.h>
nrn_fpsetmask() {
printf("fpsetmask\n");
	fpsetmask(FP_X_INV | FP_X_OFL | FP_X_DZ);
}
int matherr(exc) struct exception *exc; {
	fprintf(stderr, "type=%d name=%s arg1=%g arg2=%g retval=%g\n",
	 exc->type, exc->name, exc->arg1, exc->arg2, exc->retval);
	abort();
}
#endif
#if defined(linux)
#include <fenv.h>
#define FEEXCEPT (FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW )
nrn_fpsetmask() {
	feenableexcept(FEEXCEPT);
}
int matherr1() {
	/* above gives the signal but for some reason fegetexcept returns 0 */
	switch(fegetexcept()) {
	case FE_DIVBYZERO:
		fprintf(stderr, "Floating exception: Divide by zero\n");
		break;
	case FE_INVALID:
		fprintf(stderr, "Floating exception: Invalid (no well defined result\n");
		break;
	case FE_OVERFLOW:
		fprintf(stderr, "Floating exception: Overflow\n");
		break;
	}
}
#endif
#endif

#if 0
/* performance debugging when gprof is inadequate */
#include <sys/time.h>
static unsigned long usec[30];
static unsigned long oldusec[30];
static struct timeval tp;
void start_profile(int i){
	gettimeofday(&tp, 0);
	oldusec[i] = tp.tv_usec;
}
void add_profile(int i) {
	gettimeofday(&tp, 0);
	if (tp.tv_usec > oldusec[i]) {
		usec[i] += tp.tv_usec - oldusec[i];
	}
}
void pr_profile() {
	int i;
	for (i=0; i < 30; ++i) {
		if (usec[i]) {
			printf("sec[%d]=%g\n", i, ((double)usec[i])/1000000.);
		}
	}
}
#else
void start_profile(i) int i; {}
void add_profile(i) int i; {}
void pr_profile() {}
#endif

#ifdef MAC
	#define READLINE 0
#endif

#if defined(WITHOUT_MEMACS)
#undef READLINE
#define READLINE 0
#endif

#if OCSMALL
#define READLINE 0
#endif

#ifndef READLINE
#define READLINE 1
#endif

int nrn_nobanner_;
int pipeflag;
int hoc_usegui;
#if 1
/* no longer necessary to distinguish signed from unsigned since EOF
  never stored in a buffer.
 */
#define CHAR char
#else
#if -1 == '\377'
#define CHAR char
#else
#define CHAR signed char
#endif
#endif
/* buffers will grow automatically if an input line exceeds the following*/
#define TMPBUFSIZE 512
#define CBUFSIZE 512
HocStr* hoc_tmpbuf;
HocStr* hoc_cbufstr;
char* hoc_promptstr;
static CHAR	*cbuf;
CHAR	*ctp;
int hoc_ictp;
extern Symlist *symlist;	/* This list is permanent */
extern Symlist *p_symlist; /* Constants, strings, auto variables */
extern char *RCS_hoc_version;
extern char *RCS_hoc_date;
extern char* neuron_home;
extern int hoc_print_first_instance;

#define EPS hoc_epsilon
extern double EPS;
extern arayinstal();
FILE	*fin;				/* input file pointer */

#include <ctype.h>
char	*progname;	/* for error messages */
int	lineno;

#include <signal.h>
#include <setjmp.h>
static int control_jmpbuf = 0; /* don't change jmp_buf if being controlled */
jmp_buf begin;
static int hoc_oc_jmpbuf;
static jmp_buf hoc_oc_begin;
int	intset;		/* safer interrupt handling */
int	indef;
char	*infile;	/* input file name */
extern char hoc_xopen_file_[];
extern stoprun;
char	**gargv;	/* global argument list */
int	gargc;
static int c = '\n';	/* global for use by warning() */

#if defined(WIN32) || MAC
set_intset() {
	intset++;
}
#endif

void nrn_exit(i) int i; {
#if defined(WIN32)
	printf("NEURON exiting abnormally, press return to quit\n");
	fgetc(stdin);
#endif
	exit(i);
}

#if LINDA

int hoc_retreat_flag;
#define RETREAT_SIGNAL SIGHUP

static
RETSIGTYPE
retreat_handler(sig) int sig;	/* catch interrupt */
{
	/*ARGSUSED*/
	if (hoc_retreat_flag++) {
		/* never managed the first one properly */
		nrn_exit(1);
	}
	if (!lookup("linda_retreat")) {
		hoc_retreat_flag = 0;
		/* user did not give us a safe retreat so it would be nice */
		/* to take up later exactly at this point */
		nrn_exit(1);
	}
	IGNORE(signal(RETREAT_SIGNAL, retreat_handler));
}

hoc_retreat() {
	hoc_obj_run("linda_retreat()\n", (Object*)0);
	exit(0);
}

#endif

#if defined(WIN32) || defined(MAC)
#define HAS_SIGPIPE 0
#else
#define HAS_SIGPIPE 1
#endif
#if HAS_SIGPIPE
/*ARGSUSED*/
static
RETSIGTYPE
sigpipe_handler(sig) int sig; {
	fprintf(stderr, "writing to a broken pipe\n");
	signal(SIGPIPE, sigpipe_handler);
}
#endif

int
getnb()	/* get next non-white character */
{
	int c;

	/*EMPTY*/
	while ((c=Getc(fin)) == ' ' || c == '\t') {
		;
	}
	return c;
}

/* yylex modified to return -3 when at end of cbuf. The parser can
   return and take up where it left off later. Supported by modification
   of bison.simple to allow event driven programming.
*/
#define YYNEEDMORE	-3
/* for now we say comments or strings that span lines on stdin are in error */
#if 0
#define INCOMMENT	1;
#define INSTRING	2;
static int lexstate = 0;
#endif
/* sometimes is... doesn't work with -3. Hence Getc returns null and look
   at eos to see if true.*/
static int eos;

yylex()			/* hoc6 */
{
   restart:	/* when no token in between comments */
	eos = 0;
#if 0 /* do we really want to have several states? */
	switch (lexstate) {

	case INCOMMENT:
		goto incomment;
	case INSTRING:
		goto instring;
	}
#endif

	if ((c=getnb()) == EOF) {
		return 0;
	}
	if (c == '/' && follow('*', 1, 0))	/* comment */
	{
		while ((c=Getc(fin)) != '*' || follow('/', 0, 1)) {
			if (c == EOF)
				return(0);
/*			if (c == YYNEEDMORE) {*/
			if (eos) {
				acterror("comment not complete", " in cbuf");
			}
		}
		goto restart;
	}
	if (c == '.' || isdigit(c))	/* number */
	{
		char *npt;
		double d;
		IGNORE(unGetc(c, fin));
		npt = (char *)ctp;
		/*EMPTY*/
		while (isdigit(c = Getc(fin))) {
			;
		}
		if (c == '.') {
			/*EMPTY*/
			while(isdigit(c = Getc(fin))) {
				;
			}
		}
		if (*npt == '.' && !isdigit(npt[1])) {
			IGNORE(unGetc(c, fin));
			return  (int)(*npt);
		}
		if (c == 'E' || c == 'e') {
			if (isdigit(c = Getc(fin)) || c == '+' || c == '-') {
				/*EMPTY*/
				while (isdigit(c = Getc(fin))) {
					;
				}
			}
		}
		IGNORE(unGetc(c, fin));
		IGNORE(sscanf(npt, "%lf", &d));
		if (d == 0.)
			return NUMZERO;
		yylval.sym = install("", NUMBER, d, &p_symlist);
		return NUMBER;
	}
	if (isalpha(c) || c == '_')
	{
		Symbol *s;
		char sbuf[256], *p = sbuf;
		do
		{
			*p++ = c;
		} while ((c=Getc(fin)) != EOF && (isalnum(c) || c == '_'));
		IGNORE(unGetc(c, fin));
		*p = '\0';
		if ((s=lookup(sbuf)) == 0)
			s = install(sbuf, UNDEF, 0.0, &symlist);
		yylval.sym = s;
		return s->type == UNDEF ? VAR : s->type;
	}
	if (c == '$') {	/* argument? */
		int ith;
		int n = 0;
		int retval = follow('o', OBJECTARG, ARG);
		if (retval == ARG) retval = follow('s', STRINGARG, ARG);
		if (retval == ARG) retval = follow('&', ARGREF, ARG);
		ith = follow('i', 1, 0);
		if (ith) {
			yylval.narg = 0;
			return retval;
		}
		while (isdigit(c=Getc(fin)))
			n = 10 * n + c - '0';
		IGNORE(unGetc(c, fin));
		if (n == 0)
			acterror("strange $...", (char *)0);
		yylval.narg = n;
		return retval;
	}
	if (c == '"')	/* quoted string */
	{
		static HocStr* sbuf;
		char *p;
		int n;
		if (!sbuf) { sbuf = hocstr_create(256); }
		for (p = sbuf->buf; (c=Getc(fin)) != '"'; p++)
		{
			if (c == '\n' || c == EOF || c == YYNEEDMORE)
				acterror("missing quote", "");
			n = p - sbuf->buf;
			if (n >=  sbuf->size - 1)
			{
				hocstr_resize(sbuf, n + 200);
				p = sbuf->buf + n;
			}
			*p = backslash(c);
		}
		*p = 0;
		yylval.sym = install("", CSTRING, 0.0, &p_symlist);

		(yylval.sym)->u.cstr = (char *)emalloc((unsigned)(strlen(sbuf->buf)+1));
		Strcpy((yylval.sym)->u.cstr, sbuf->buf);
		return CSTRING;
	}
	switch (c)
	{
	case 0:		{if (eos) return YYNEEDMORE; else return 0;}
	case '>':	return follow('=', GE, GT);
	case '<':	return follow('=', LE, LT);
	case '!':	return follow('=', NE, NOT);

	case '+':
	case '-':
	case '*':
		{	if (follow('=', 1, 0)) {
				yylval.narg = c;
				return ROP;
			}else{
				return c;
			}
		}
	case '=':
		{
			if (follow('=', EQ, '=') == EQ) {
				return EQ;
			}
			if (do_equation) {
				return EQNEQ;
			}
			yylval.narg = 0;
			return ROP;
		}
	case '|':	return follow('|', OR, '|');
	case '&':	return follow('&', AND, '&');
	case '\\':
		{	int i;	/* continuation line if last char in line is \ */
			i = follow('\n', 1000, '\\');
			if (i == 1000) {
				return yylex();
			}
			return i;
	}
	case '\r':	return follow('\n', '\n', '\n');
	case '\n':	return '\n';
	case '/':	if (follow('/', 1, 0)) {
				while(*ctp) {
					++ctp;
				}
				return '\n';
			}else if (follow('=', 1, 0)) {
				yylval.narg = c;
				return ROP;
			}else{
				return '/';
			}
	default:	return c;
	}
}

backslash(c)	/* get next char with \'s interpreted */
	int c;
{
	static char transtab[] = "b\bf\fn\nr\rt\t";
	if (c != '\\')
		return c;
	c = Getc(fin);
	if (islower(c) && strchr(transtab, c))
		return strchr(transtab, c)[1];
	return c;
}

follow(expect, ifyes, ifno)	/* look ahead for >=, etc. */
{
	int c = Getc(fin);

	if (c == expect)
		return ifyes;
	IGNORE(unGetc(c, fin));
	return ifno;
}

arayinstal()	/* allocate storage for arrays */
{
	int i, nsub;
	Symbol * sp;
#if	defined(__TURBOC__)
	Inst *pcc;	/* sometimes pop messes up pc */
#endif

	nsub = (pc++)->i;
#if	defined(__TURBOC__)
	pcc = pc;
#endif
	sp = spop();

	hoc_freearay(sp);
	sp->type = VAR;
	sp->s_varn = 0;
	i = hoc_arayinfo_install(sp, nsub);
	if ((OPVAL(sp) = (double *) hoc_Ecalloc((unsigned)i, sizeof(double)))
	== (double *) 0) {
		hoc_freearay(sp);
		Fprintf(stderr, "Not enough space for array %s\n", sp->name);
		hoc_malchk();
		hoc_execerror("", (char *)0);
	}
#if	defined(__TURBOC__)
	pc = pcc;
#endif
}

int
hoc_arayinfo_install(sp, nsub)
	Symbol *sp; int nsub;
{
	double total, subscpt;
	int i;
	free_arrayinfo(sp->arayinfo);
	sp->arayinfo = (Arrayinfo *) emalloc((unsigned)(
			sizeof(Arrayinfo)+nsub*sizeof(int)));
/*printf("emalloc arrayinfo at %lx\n", sp->arayinfo);*/
	sp->arayinfo->a_varn = (unsigned *) 0;
	sp->arayinfo->nsub = nsub;
	sp->arayinfo->refcount = 1;
	total = 1.;
	while (nsub)
	{
		subscpt = floor(xpop() + EPS);
		if (subscpt <= 0.)
			execerror("subscript < 1", sp->name);
		total = total*subscpt;
		sp->arayinfo->sub[--nsub] = (int)subscpt;
	}
	if (total > 2e9) {
/*
following gives purify uninitialized memory read and cannot work
around it with anything involving i. Must be a bug in purify because
the i=(int)total gives the UMR  when it is just above this if statement.
but no UMR if in present location just above return.
	if ( (double)(i = (int)total) != total) {
*/
		free((char *)sp->arayinfo);
		sp->arayinfo = (Arrayinfo *)0;
		execerror(sp->name, ":total subscript too large");
	}
	if (OPARINFO(sp)) {
/* probably never get here */
		free_arrayinfo(OPARINFO(sp));
	}
	OPARINFO(sp) = sp->arayinfo;
	++sp->arayinfo->refcount;
	i = (int)total;
	return i;
}

hoc_freearay(sp)
	Symbol *sp;
{
	Arrayinfo** pa = &(OPARINFO(sp));
	if (sp->type == VAR)
	{
		hoc_free_val_array(OPVAL(sp), hoc_total_array(sp));
		sp->type = UNDEF;
	}
	free_arrayinfo(*pa);
	free_arrayinfo(sp->arayinfo);
	sp->arayinfo = (Arrayinfo *)0;
	*pa = (Arrayinfo *)0;
}

free_arrayinfo(a)
	Arrayinfo* a;
{
	if (a != (Arrayinfo *) 0)
	{
	    if ((--a->refcount) <= 0) {
		if (a->a_varn != (unsigned *) 0)
			free((char *)(a->a_varn));
		free((char *)a);
/*		printf("free arrayinfo at %lx\n", a);*/
	    }
	}
}

defnonly(s)	/* warn if illegal definition */
	char *s;
{
	if (!indef)
		acterror(s, "used outside definition");
}

/* messages can turned off but the user had better check the return
value of oc_run()
*/
static int debug_message_;
hoc_show_errmess_always() {
	double x, chkarg();
	x = chkarg(1, 0., 1.);
	debug_message_ = (int)x;
	ret();
	pushx(x);
}

int hoc_execerror_messages;

/* this is possibly non-portable since it is based on the declaration in
	setjmp.h of
	typedef int jmp_buf[_JBLEN];
*/
void (*oc_jump_target_)();	/* see ivoc/SRC/ocjump.c */


int yystart;

execerror(s, t)	/* recover from run-time error */
	char *s, *t;
{
	extern int hoc_in_yyparse;
	hoc_in_yyparse = 0;
	yystart = 1;
	hoc_menu_cleanup();
	hoc_errno_check();
#if 0
	hoc_xmenu_cleanup();
#endif
	if (debug_message_ || hoc_execerror_messages) {
		warning(s, t);
		frame_debug();
#if defined(__GO32__)
		{extern int egagrph;
		if (egagrph) {
			hoc_outtext("Error:");
			hoc_outtext(s);
			if (t) {
				hoc_outtext(" ");
				hoc_outtext(t);
			}
			hoc_outtext("\n");
		}}
#endif
	}
	if (oc_jump_target_) {
		(*oc_jump_target_)();
	}
	if (nrnmpi_numprocs_world > 1) {
		nrnmpi_abort(-1);
	}
	hoc_execerror_messages = 1;
	if (pipeflag == 0)
		IGNORE(fseek(fin, 0L, 2));	/* flush rest of file */
	hoc_oop_initaftererror();
#if defined(WIN32) && !defined(CYGWIN)
		hoc_win_normal_cursor();
#endif
	if (hoc_oc_jmpbuf) {
		longjmp(hoc_oc_begin, 1);
	}
	longjmp(begin, 1);
}

RETSIGTYPE
onintr(sig) int sig;	/* catch interrupt */
{
	/*ARGSUSED*/
	stoprun = 1;
	if (intset++)
		execerror("interrupted", (char *) 0);
	IGNORE(signal(SIGINT, onintr));
}

#if DOS
#include <float.h>
#endif

static int coredump;

hoc_coredump_on_error() {
	coredump = 1;
	ret();
	pushx(1.);
}

RETSIGTYPE
fpecatch(sig) int sig;	/* catch floating point exceptions */
{
	/*ARGSUSED*/
#if DOS
_fpreset();
#endif
#if NRN_FLOAT_EXCEPTION && linux
	matherr1();
#endif
	if (coredump) {
		abort();
	}
	signal(SIGFPE, fpecatch);
	execerror("floating point exception", (char *) 0);
}

#if HAVE_SIGSEGV
RETSIGTYPE
sigsegvcatch(sig) int sig;	/* segmentation violation probably due to arg type error */
{
	/*ARGSUSED*/
	if (coredump) {
		abort();
	}
	execerror("Segmentation violation", (char*)0);
}
#endif

#if HAVE_SIGBUS
RETSIGTYPE
sigbuscatch(sig) int sig;
{
	/*ARGSUSED*/
	if (coredump) {
		abort();
	}
	execerror("Bus error", "See $NEURONHOME/lib/help/oc.help");
}
#endif

int hoc_pid() { return (int)getpid();} /* useful for making unique temporary file names */

/* readline should be avoided if stdin is not a terminal */
int nrn_istty_;

/* has got to be called first. oc can only be event driven after this returns */
hoc_main1_init(pname, envp)
	char *pname, **envp;
{
	extern FILE	*frin;
	extern FILE	*fout;
	static int inited = 0;
	
	hoc_promptstr = "oc>";
	yystart = 1;
	lineno = 0;
	if (inited) {
		return;
	}
	inited = 1;

	/* could have been forced with the -isatty option */
	if (nrn_istty_ == 0) { /* if not set then */
#ifdef HAVE_ISATTY
		nrn_istty_ = isatty(0);
#else
	/* if we do not know, then assume so */
		nrn_istty_ = 1;
#endif
	}
	if (nrn_istty_ == -1) {
		nrn_istty_ = 0;
	}
	hoc_tmpbuf = hocstr_create(TMPBUFSIZE);
	hoc_cbufstr = hocstr_create(CBUFSIZE);
	cbuf = hoc_cbufstr->buf;
	ctp = cbuf;
	frin = stdin;
	fout = stdout;
	if (!parallel_sub) {
	    if (!nrn_is_cable()) {
	      Fprintf(stderr, "OC INTERPRETER   %s   %s\n",
		    RCS_hoc_version, RCS_hoc_date);
	      Fprintf(stderr,
"Copyright 1992 -  Michael Hines, Neurobiology Dept., DUMC, Durham, NC.  27710\n");
	    }
	}
	progname = pname;
	if (setjmp(begin)) {
		nrn_exit(1);
	}

	save_parallel_envp();

	init();
	initplot();
#if defined(__GO32__)
	setcbrk(0);
#endif
#if NRN_FLOAT_EXCEPTION
nrn_fpsetmask();
#endif
}

HocStr* hocstr_create(size) int size; {
	HocStr* hs;
	hs = (HocStr*)emalloc(sizeof(HocStr));
	hs->size = size;
	hs->buf = emalloc(size + 1);
	return hs;
}

static CHAR* fgets_unlimited_nltrans();

char* fgets_unlimited(HocStr* s, FILE* f) {
#if 1
	return fgets_unlimited_nltrans(s, f, 0);
#else
	int c, i, n;
	i = 0;
	n = s->size - 1;
	while ((c = getc(f)) != EOF) {
#if MAC
		if (c == '\r') {
			c = getc(f);
			if (c != '\n') {
				ungetc(c, f);
				c = '\n';
			}
		}
#endif
		s->buf[i++] = c;
		if (i == n) {
			n = (n+1)*2 - 1;
/*printf("fgets_unlimited resize to %d\n", n+1);*/
			hocstr_resize(s, n+1);
		}
		if (c == '\n') {
			break;
			s->buf[i] = '\0';
			return s->buf;
		}
	}
	if (i == 0) {
		return (char*)0;
	}
	s->buf[i] = '\n';
	s->buf[i++] = '\0';
	return s->buf;
#endif
}

void hocstr_delete(hs) HocStr* hs; {
	free(hs->buf);
	free(hs);
}

hocstr_resize(hs, n) HocStr* hs; int n; {
	if (hs->size < n) {
/*printf("hocstr_resize to %d\n", n);*/
		hs->buf = erealloc(hs->buf, n+1);
		hs->size = n;
	}
}
	
hocstr_copy(hs, buf) HocStr* hs; char* buf; {
	hocstr_resize(hs, strlen(buf)+1);
	strcpy(hs->buf, buf);
}

//struct Neurospaces;

struct Neurospaces *pneuroGlobal = NULL;

int NSNeuronInitialize(void)
{
    if (!pneuroGlobal)
    {
	//- create one with an empty model

	char *ppvArgs[] =
	    {
		"genesis-neurospaces-bridge",
		"/usr/local/neurospaces/models/library/utilities/empty_model.ndf",
		"empty_model.ndf",
		NULL,
		NULL,
	    };

	pneuroGlobal = NeurospacesNewFromCmdLine(2, &ppvArgs[0]);
	printf("Print the empty, just created, neurospaces container\n");
	if (!pneuroGlobal)
	{
	    fprintf(stderr, "Error initializing neurospaces model container\n");

	    return -1;
	}
	printf("Lets see if we are going to have a segmentation fault4\n");
	char arg[]="export no ndf STDOUT /**";
	QueryMachineHandle(pneuroGlobal,&arg);
	//QueryMachineHandle(pneuroGlobal,"export;no;ndf;STDOUT;/**");
    }

    return pneuroGlobal;
}


#if defined(CYGWIN)
static int cygonce; /* does not need the '-' after a list of hoc files */
#endif

static hoc_run1();

hoc_main1(argc, argv, envp)	/* hoc6 */
	char *argv[], *envp[];
{
#ifdef WIN32
	hoc_set_unhandled_exception_filter();
#endif
#if 0
	int controlled;
#endif
#if PVM
        init_parallel(&argc,argv);
#endif
	save_parallel_argv(argc, argv);

	hoc_audit_from_hoc_main1(argc, argv, envp);
	hoc_main1_init(argv[0], envp);
#if LINDA
	signal(RETREAT_SIGNAL, retreat_handler);
#endif
#if HAS_SIGPIPE
	signal(SIGPIPE, sigpipe_handler);
#endif	
#if 0
	controlled = control_jmpbuf;
	if (!controlled) {
		control_jmpbuf = 1;
		if (setjmp(begin)) {
			control_jmpbuf = 0;
			return 1;
		}
	}
	if (!controlled) {
		control_jmpbuf = 0;
	}
#endif

	if (NSNeuronInitialize() < 0 )
	{
	    fprintf(stderr, "Error initializing the Neurospaces model container.\n"); 

	    return;
	}
	else
	{
	    fprintf(stdout, "The Neurospaces model container initialized.\n");
	}

	gargv = argv;
	gargc = argc;
	if ( argc > 2 && strcmp(argv[1], "-bbs_nhost") == 0) {
		/* if IV not running this may still be here */
		gargv += 2;
		gargc -= 2;
	}
	if (argc > 1 && argv[1][0] != '-') {
		/* first file may be a checkpoint file */
		extern int hoc_readcheckpoint();
		switch (hoc_readcheckpoint(argv[1])) {
		case 1:
			++gargv;
			--gargc;
			break;
		case 2:
			nrn_exit(1);
			break;
		default:
			break;
		}			

	}

	if (gargc == 1)	/* fake an argument list */
	{
#if 0
		/* who knows why this ancient code no longer works under cygwin
		when the @@ to ' ' was introduced in moreinput*/
		static char *stdinonly[] = { "-" };
#else
		static char *stdinonly[1];
		stdinonly[0] = (char*)emalloc(2*sizeof(char));
		strcpy(stdinonly[0], "-");		
#endif

#if defined(CYGWIN)
		cygonce = 1;
#endif
		gargv = stdinonly;
		gargc = 1;
	}
	else
	{
		++gargv;
		--gargc;
	}
	while (moreinput())
		hoc_run1();
	return 0;
}
#if defined(WIN32) && HAVE_IV
extern void ivcleanup();
#endif

#if carbon
#include <sys/select.h>
static pthread_t* inputReady_;
static pthread_mutex_t inputMutex_;
static pthread_cond_t inputCond_;
static int inputReadyFlag_;

void* inputReadyThread(void*  input);
void* inputReadyThread(void* input) {
	fd_set readfds;
	int i, j;
	extern int stdin_event_ready();
	char c;
//	printf("inputReadyThread started\n");
//	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &j);
	FD_ZERO(&readfds);
	FD_SET(fileno(stdin), &readfds);
	for (;;) {
		i = select(1, &readfds, 0, 0, 0);
		pthread_testcancel();
		if (FD_ISSET(fileno(stdin), &readfds)) {
			if (!stdin_event_ready()) {
				// dialog is open. cannot accept input now.
printf("Discarding input til Dialog is closed.\n");
				read(fileno(stdin), &c, 1);
				continue;
			}
		}
		pthread_mutex_lock(&inputMutex_);
		pthread_cond_wait(&inputCond_, &inputMutex_);
		pthread_mutex_unlock(&inputMutex_);
	}
	printf("inputReadyThread done\n");
}
#endif

hoc_final_exit() {
	char buf[256];
#if defined(USE_PYTHON)
	if (p_nrnpython_start) { (*p_nrnpython_start)(0);}
#endif
	bbs_done();
	hoc_audit_from_final_exit();
	hoc_edit_quit();
	
	/* Don't close the plots for the sub-processes when they finish,
	   by default they are then closed when the master process ends */
	NOT_PARALLEL_SUB(hoc_close_plot();)
#if defined(WIN32) && HAVE_IV
	ivcleanup();
#ifndef CYGWIN
	if (winio_exists()) {
		winio_closeall();
	}
#endif
#endif
#if READLINE && (!defined(WIN32) || defined(CYGWIN)) && !defined(MAC)
	rl_deprep_terminal();
#endif
	ivoc_cleanup();
#ifdef WIN32
	hoc_win32_cleanup();
#else
#if defined(__GO32__)
	sprintf(buf, "sh %s/lib/cleanup %d", neuron_home, hoc_pid());
#else
	sprintf(buf, "%s/lib/cleanup %d", neuron_home, hoc_pid());
#endif
	if (system(buf)) {;} // ignore return value
#endif
}
	
hoc_quit() {
#if carbon
	if (0 && inputReady_) {
		pthread_cancel(*inputReady_);
		pthread_kill(*inputReady_, SIGHUP);
		pthread_join(*inputReady_, 0);
	}
#endif
	hoc_final_exit();
	ivoc_final_exit();
	exit(0);
}

#if defined(CYGWIN)
static double_at2space(char* infile) {
	char *cp1, *cp2;
	for (cp1=infile, cp2=infile; *cp1; ++cp1, ++cp2) {
		if (*cp1 == '@' && cp1[1] == '@') {
			*cp2 = ' ';
			++cp1;
		}else{
			*cp2 = *cp1;
		}
	}
	*cp2 = '\0';
}
#endif /*CYGWIN*/

moreinput()
{
	if (pipeflag)
	{
		pipeflag = 0;
		return 1;
	}
#if defined(WIN32)
#ifndef CYGWIN
	if (!winio_exists()) {
		return 0;
	}
#endif
#if defined(CYGWIN)
	/* like mswin, do not need a '-' after hoc files, but ^D works */
	if (gargc == 0 && cygonce == 0) {
		cygonce = 1;
#else
	if (gargc == 0) {
#endif
		fin = stdin;
		infile = 0;
		hoc_xopen_file_[0] = 0;
#if defined(USE_PYTHON)
		return use_python_interpreter ? 0 : 1;
#else
		return 1;
#endif
	}
#endif
#if MAC
	if (gargc == 0) {
		fin = stdin;
		infile = 0;
		hoc_xopen_file_[0] = 0;
#if defined(USE_PYTHON)
		return use_python_interpreter ? 0 : 1;
#else
		return 1;
#endif
	}
#endif
	if (fin && fin != stdin) {
		IGNORE(fclose(fin));
	}
	fin = stdin;
	infile = 0;
	hoc_xopen_file_[0] = 0;
	if (gargc-- <= 0) {
		return 0;
	}
	infile = *gargv++;
#if defined(WIN32)
	if (infile[0] == '"') {
		char* cp = infile;
		++infile;
		for (++cp; *cp; ++cp) {
			if (*cp == '"') {
				*cp = '\0';
				break;
			}
		}
	}
#endif
#if defined(CYGWIN)
	/* have difficulty passing spaces within arguments from neuron.exe
	through the neuron.sh shell script to nrniv.exe. Therefore
	neuron.exe converts the ' ' to "@@" and here we need to convert
	it back */
	double_at2space(infile);
#endif
	lineno = 0;
#if defined(USE_PYTHON)
	if (use_python_interpreter) {
/* deal only with .hoc files. The hoc files are intended
only for legacy code and there is no notion of stdin interaction
with the hoc interpreter.
*/
		if (strlen(infile) < 4 || strcmp(infile+strlen(infile)-4, ".hoc") != 0) {
			return moreinput();
		}
	}
#endif
	if (strcmp(infile, "-") == 0) {
		fin = stdin;
		infile = 0;
		hoc_xopen_file_[0] = 0;
	} else if (strcmp(infile, "-parallel") == 0) {
	        /* ignore "val" as next argument */
	        infile = *gargv++;
		gargc--; 
	        return moreinput();
	} else if (strcmp(infile, "-c") == 0) {
		int hpfi, err;
		HocStr* hs;
		infile = *gargv++;
		gargc--;
#if defined (CYGWIN)
		double_at2space(infile);
#endif
		hs = hocstr_create(strlen(infile) + 2);
		sprintf(hs->buf, "%s\n", infile);
		/* now infile is a hoc statement */
		hpfi = hoc_print_first_instance;
		fin = (FILE*)0;
		hoc_print_first_instance = 0;
		err = hoc_oc(hs->buf);
		hoc_print_first_instance = hpfi;
		hocstr_delete(hs);
		if (err) {
			hoc_execerror("arg not valid statement:", infile);
		}
		return moreinput();
	} else if (strlen(infile) > 3 && strcmp(infile+strlen(infile) -3, ".py") == 0) {
		if (!p_nrnpy_pyrun) {
			hoc_execerror("Python not available to interpret",infile);
		}
		(*p_nrnpy_pyrun)(infile);
		return moreinput();
	} else if ((fin=fopen(infile, "r")) == NULL) {
#if OCSMALL
hoc_menu_cleanup();
#endif
		Fprintf(stderr, "%s: can't open %s\n", progname, infile);
		return moreinput();
	}
	if (infile) {
		strcpy(hoc_xopen_file_, infile);
	}
	return 1;
}

#if 1
hoc_run() {
	hoc_run1();
	while (pipeflag == 1) {
		pipeflag = 0;
		hoc_run1();
	}
}
#endif

typedef RETSIGTYPE (*SignalType)();

static SignalType signals[4];

static
set_signals() {
	signals[0] = signal(SIGINT, onintr);
	signals[1] = signal(SIGFPE, fpecatch);
#if HAVE_SIGSEGV
	signals[2] = signal(SIGSEGV, sigsegvcatch);
#endif
#if HAVE_SIGBUS
	signals[3] = signal(SIGBUS, sigbuscatch);
#endif
}

static
restore_signals() {
	signals[0] = signal(SIGINT, signals[0]);
	signals[1] = signal(SIGFPE, signals[1]);
#if HAVE_SIGSEGV
	signals[2] = signal(SIGSEGV, signals[2]);
#endif
#if HAVE_SIGBUS
	signals[3] = signal(SIGBUS, signals[3]);
#endif
}
	
static
hoc_run1()	/* execute until EOF */
{
	int controlled = control_jmpbuf;
	if (!controlled) {
		set_signals();
		control_jmpbuf = 1;
		IGNORE(setjmp(begin));
		intset = 0;
	}
	hoc_execerror_messages = 1;
	if (pipeflag == 1) {	/*at this location multiple emacs errors */
		hoc_pipeflush(); /* don't eat up stack space */
	}else{
		pipeflag=0;
	}
#if defined(WIN32) && !defined(CYGWIN)
	if (fin != stdin) {
		hoc_win_wait_cursor();
	}
#endif
	for (initcode(); hoc_yyparse(); initcode())
		execute(progbase);
#if defined(WIN32) && !defined(CYGWIN)
		hoc_win_normal_cursor();
#endif
	if (intset)
		execerror("interrupted", (char *)0);
	if (!controlled) {
		restore_signals();
		control_jmpbuf = 0;
	}
}

/* event driven interface to oc. This routine always returns after processing
   its argument. The normal case is where the argument consists of a complete
   statement which can be parsed and executed. However this routine can
   be called with single tokens as well and the parsing will proceed
   incrementally until the last token that completes a statement is seen
   at which time the statement is executed.
   The routine can also be called with a string containing multiple statements
   separated by '\n's.
   During execution a ^C will halt
   processing and this routine will return to the calling statement. (if it
   is the controlling call for the jmp_buf; see below).
   Parse errors and execution errors will also result in a normal return to the
   calling statement.

   To avoid blocking other input events, this routine should not be called
   with statements which take too much time to execute or block
   waiting for input. With regard to long executing statements, at least in
   xview it is possible to run the event loop from the execute loop at
   intervals in code.c or else to run the event loop once via a hoc command.

   Where do we go in case of an hoc_execerror. We have to go to the beginning
   of hoc. But just maybe that is here. However hoc_oc may be called
   recursively. Or it may be called from the original hoc_run. Or it may be
   There is therefore a notion of the controlling routine for the jmp_buf begin.
   We only do a setjmp and set the signals
   when there is no other controlling routine.
*/

int
hoc_oc(buf) char *buf; {
	char *cp;
	int controlled;
#if 0
	int yret;
#endif
	
	controlled = hoc_oc_jmpbuf || oc_jump_target_;
	if (!controlled) {
		hoc_oc_jmpbuf = 1;
		if (setjmp(hoc_oc_begin)) {
			hoc_oc_jmpbuf = 0;
			restore_signals();
			initcode();
			intset = 0;
			return 1;
		}
		set_signals();
	}
	intset = 0;

	cp = buf;
	while (*cp) {
		hocstr_resize(hoc_cbufstr, strlen(cp)+10);
		cbuf = hoc_cbufstr->buf;
		for (ctp = cbuf; *cp;) {
			*ctp++ = *cp++;
			if (ctp[-1] == '\n') {
				break;
			}
		}
		*ctp = '\0';
		ctp = cbuf;	

#if 1
		hoc_ParseExec(yystart);
#else
		if (yystart) {
			initcode();
		}
		yret = yyparse();
		switch (yret) {
		case 1:
			execute(progbase);
			initcode();
			break;
		case 'e':
			hoc_edit();
			for (initcode(); hoc_yyparse(); initcode())
				execute(progbase);
			break;
		default:
			break;
		}
#endif
		if (intset) {
			execerror("interrupted", (char *)0);
		}
	}
	
	if (!controlled) {
		hoc_oc_jmpbuf = 0;
		restore_signals();
	}
	hoc_execerror_messages = 1;
	return 0;
}

warning(s, t)	/* print warning message */
	char *s, *t;
{
	CHAR *cp;
	char id[10];
	int n;
	if (nrnmpi_numprocs_world > 1) {
		sprintf(id, "%d ", nrnmpi_myid_world);
	}else{
		id[0]='\0';
	}
	if (t) {
		Fprintf(stderr, "%s%s: %s %s\n", id, progname, s, t);
	}else{
		Fprintf(stderr, "%s%s: %s\n", id, progname, s);
	}
	if (hoc_xopen_file_ && hoc_xopen_file_[0]) {
		Fprintf(stderr, "%s in %s near line %d\n", id, hoc_xopen_file_, lineno);
	}else{
		Fprintf(stderr, "%s near line %d\n", id, lineno);
	}
	n = strlen(cbuf);
	for (cp = cbuf; cp < (cbuf + n); ++cp) {
		if (!isprint((int)(*cp)) && !isspace((int)(*cp))) {
			Fprintf(stderr, "%scharacter \\%03o at position %ld is not printable\n", id, ((int)(*cp) & 0xff), cp-cbuf);
			break;
		}
	}
	Fprintf(stderr, "%s %s",id, cbuf);
    if (nrnmpi_numprocs_world > 0) {
	for (cp = cbuf; cp != ctp; cp++) {
#if defined(WIN32) && !defined(CYGWIN)
		fputchar(' ');
#else
		IGNORE(putc(' ', stderr));
#endif
	}
	Fprintf(stderr,"^\n");
    }
	ctp = cbuf;
	*ctp = '\0';
}


int
Getc(fp)
	FILE *fp;
{
	/*ARGSUSED*/
	if (*ctp) {
		++hoc_ictp;
		return *ctp++;
	}

#if 0
/* don't allow parser to block. Actually partial statements were never
allowed anyway */
	if (!pipeflag && fp == stdin) {
		eos = 1;
		return 0;
	}
#endif

	if (hoc_get_line() == EOF) {
		return EOF;
	}
	return *ctp++;
}

unGetc(c, fp)
	int c;
	FILE *fp;
{
	/*ARGSUSED*/
	if (c != EOF && c && ctp != cbuf) {
		*(--ctp) = c;
	}
}

int hoc_in_yyparse=0;

int hoc_yyparse() {
	/* read line before calling yyparse() and set flag that we
	are inside yyparse() since re-entry is not allowed.
	This allows xview menus to work since most of the time
	we are reading a line from this point instead of in
	Getc which was called from yyparse().
	*/
	/*
	the above may be obsolete.
	I switched to a modified bison generator from yacc which is generated
	a parser exactly like it used to be but may return YYNEEDMORE=-3
	instead of blocking in yylex. If so another call to yyparse will
	take up exactly where it left off.  This makes it easier to
	support event driven processing.
	Maybe it's time to redo the get_line process which fills cbuf with
	the next line to read. A real event driven program would fill cbuf
	and then call yyparse() directly. yyparse() returns
	0 : end of file
	'\n' : ready to execute a command
	'e' : user gave it em command, you should go to an editor
	-3: need more input, not at a point where it accepts or rejects the
		input.
	*/

	int i;
	
	if (hoc_in_yyparse) {
		hoc_execerror("Cannot re-enter parser", (char *)0);
	}
	do {
		if (hoc_get_line() == EOF) {
			return 0;
		}
		hoc_in_yyparse = 1;
		i = yyparse();
		hoc_in_yyparse = 0;
		switch (i) {
		case 'e':
			i = '\n';
			hoc_edit();
			break;
		case -3 : /* need more input */
			hoc_in_yyparse = 1;
			i = '\n';
			break;
		}
	}while (i == '\n');
	return i;
}

#if defined(__GO32__)
#define INTERVIEWS 1
#endif
#ifdef WIN32
#define INTERVIEWS 1
#endif
#ifdef MAC
#define INTERVIEWS 1
#endif

#if defined(WITHOUT_MEMACS)
#undef INTERVIEWS
#define INTERVIEWS 0
#endif

int hoc_interviews = 0;
#if INTERVIEWS
extern int run_til_stdin(); /* runs the interviews event loop. Returns 1
				if there is input to be read. Returns 0
				if somebody said quit but there is no input
				*/

extern hoc_notify_value();

#if READLINE
extern Pfri rl_event_hook;
static int event_hook() {
#if carbon
	if (!inputReady_) {
		inputReady_ = (pthread_t*)emalloc(sizeof(pthread_t));
		pthread_mutex_init(&inputMutex_, 0);
		pthread_cond_init(&inputCond_, 0);
		pthread_create(inputReady_, 0, inputReadyThread, 0);
	}else{
		pthread_mutex_unlock(&inputMutex_);
	}
//	printf("run til stdin\n");
	run_til_stdin();
	pthread_mutex_lock(&inputMutex_);
	pthread_cond_signal(&inputCond_);
	return 1;
#endif
	int i;
	i = run_til_stdin();
	return i;
}
#endif
#endif

#if 1 || MAC
/*
 On Mac combinations of /n /r /r/n require binary mode
 (otherwise /r/n is /n/n)
 but then /r does not end a line in fgets (keeps reading til /n)
 so we make our own fgets. May need to use it for data as well.
*/
/*
   for unix and mac this allows files created on any machine to be
   read on any machine
*/
CHAR* hoc_fgets_unlimited(bufstr, f) HocStr* bufstr; FILE* f; {
	return fgets_unlimited_nltrans(bufstr, f, 1);
}

static CHAR* fgets_unlimited_nltrans(bufstr, f, nltrans)
    HocStr* bufstr; FILE* f;
    int nltrans;
{
	int c, i;
	int nl1, nl2;
	if (nltrans) { nl1 = 26; nl2 = 4;}else{nl1 = nl2 = EOF;}
	for(i=0;; ++ i) {
		c = getc(f);
		if (c == EOF || c == nl1 || c == nl2) { /* ^Z and ^D are end of file */
			/* some editors don't put a newline at last line */
			if ( i > 0) {
				ungetc(c, f);
				c = '\n';
			}else{
				break;
			}
		}
		if (c == '\r') {
			int c2 = getc(f);
			if (c2 != '\n') {
				ungetc(c2, f);
			}
			c = '\n';
		}
		if (bufstr->size <= i) {
			hocstr_resize(bufstr, bufstr->size * 2);
		}
		bufstr->buf[i] = c;
		if (c == '\n') {
			bufstr->buf[i+1] = '\0';
			return bufstr->buf;
		}
	}
	return (CHAR*)0;
}
#endif

#if MAC
int hoc_get_line(){ /* supports re-entry. fill cbuf with next line */
	int hoc_pipegets_need();
	char *hoc_pipegets();
	if (*ctp) {
		hoc_execerror("Internal error:", "Not finished with previous input line");
	}
	ctp = cbuf;
	*ctp = '\0';
	if (pipeflag) {
		if (hoc_pipegets_need() > hoc_cbufstr->size) {
			hocstr_resize(hoc_cbufstr, hoc_pipegets_need());
		}
		if (hoc_pipegets(cbuf, hoc_cbufstr->size) == (char *)0) {
			return EOF;
		}
	}else{
		if (fin == stdin && hoc_interviews && !hoc_in_yyparse) {
		#if MAC
			for(;;){
				extern CHAR* hoc_console_buffer;
				hoc_console_buffer = cbuf;
				if (run_til_stdin()){ 
					//printf("%s", cbuf); 
					//strcpy(cbuf, hoc_console_buffer);
					break;	
				} else {
					return EOF;
				}
			} 
		#endif
		} else if (hoc_fgets_unlimited(hoc_cbufstr, fin) == (CHAR *)0) {
			return EOF;
		}
	}
//	printf("%d %s", lineno, cbuf);
	errno = 0;
	lineno++;
	ctp = cbuf = hoc_cbufstr->buf;
	hoc_ictp=0;
	return 1;
}

#else
int hoc_get_line(){ /* supports re-entry. fill cbuf with next line */
	char *hoc_pipegets();
	if (*ctp) {
		hoc_execerror("Internal error:", "Not finished with previous input line");
	}
	ctp = cbuf = hoc_cbufstr->buf;
	*ctp = '\0';
	if (pipeflag) {
		if (hoc_pipegets_need() > hoc_cbufstr->size) {
			hocstr_resize(hoc_cbufstr, hoc_pipegets_need() + 100);
		}
		if (hoc_pipegets(cbuf, CBUFSIZE) == (char *)0) {
			return EOF;
		}
	}else{
#if READLINE
		if (fin == stdin && nrn_istty_) { char *line, *readline(); int n;
#if INTERVIEWS
			if (hoc_interviews && !hoc_in_yyparse) {
				rl_event_hook = event_hook;
				hoc_notify_value();
			}else{
				rl_event_hook = (Pfri)0;
			}
#endif
			if ((line = readline(hoc_promptstr)) == (char *)0) {
				extern int hoc_notify_stop;
				return EOF;
			}
#if defined(__GO32__)
			hoc_check_intupt(0);
#endif
			n = strlen(line);
			if (n >= hoc_cbufstr->size - 3) {
				hocstr_resize(hoc_cbufstr, n+100);
				ctp = cbuf = hoc_cbufstr->buf;
			}
			strcpy((char*)cbuf, line);
			cbuf[n] = '\n';
			cbuf[n+1] = '\0';
			if (line && *line) {
				add_history(line);
			}
			free(line);
			hoc_audit_command(cbuf);
		}else{
			fflush(stdout);
			if (hoc_fgets_unlimited(hoc_cbufstr, fin) == (CHAR *)0) {
				return EOF;
			}
		}
#else
#if INTERVIEWS
		if (fin == stdin && hoc_interviews && !hoc_in_yyparse) {
			run_til_stdin());
		}
#endif
#if defined(WIN32)
		if (fin == stdin) {
			if (gets(cbuf) == (char*)0) {
/*DebugMessage("gets returned NULL\n");*/
				return EOF;
			}
			strcat(cbuf, "\n");
		}else
#endif
		{
			if (hoc_fgets_unlimited(hoc_cbufstr, fin) == (char *)0) {
				return EOF;
			}
		}
#endif
	}
	errno = 0;
	lineno++;
	ctp = cbuf = hoc_cbufstr->buf;
	hoc_ictp=0;
	return 1;
}
#endif

hoc_help() {
#if INTERVIEWS
	if (hoc_interviews) {
		ivoc_help(cbuf);
	}else
#endif
	{
IFGUI
hoc_warning("Help only available from version with ivoc library", 0);
ENDGUI
	}
ctp = cbuf + strlen(cbuf) - 1;
}

#if defined(__GO32__)
hoc_check_intupt(intupt) int intupt; {
	if (_go32_was_ctrl_break_hit()) {
		if (intupt) {
			execerror("interrupted", (char*)0);
		}
	}
}
#endif
