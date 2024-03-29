/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 2 "parse.y"


#include <../../nrnconf.h>
/* changes as of 2-jan-89 */
/*  version 7.2.1 2-jan-89 short form of the for statement */

#if AIX
#pragma alloca
#endif

#include "hoc.h"
#include "code.h"
#include "equation.h"

#if LINT
Inst *inlint;
#define code	inlint = Code
#else
#define code	Code
#endif
extern Inst* codei(int i);

#define paction(arg) fprintf(stderr, "%s\n", arg)

/* maintain a list of ierr addresses so we can clear them */
#define HOCERRSIZE 20
static int** hoc_err;
static int hoc_errp;
static int localcnt;

static clean_err() {
	int i;
	for (i=0; i < hoc_errp; ++i) {
		*hoc_err[i] = 0;
	}
	hoc_errp = 0;
}

static pusherr(ip) int* ip; {
	if (!hoc_err) {
		hoc_err = (int**)ecalloc(HOCERRSIZE, sizeof(int*));
		hoc_errp = 0;
	}
	if (hoc_errp >= HOCERRSIZE) {
		clean_err();
		hoc_execerror("error stack full", (char*)0);
	}
	hoc_err[hoc_errp++] = ip;
}

#if YYBISON
#define myerr(arg) static int ierr=0;\
if (!(ierr++)){pusherr(&ierr);yyerror(arg);} --yyssp; --yyvsp; YYERROR
#else
#define myerr(arg) static int ierr=0;\
if (!(ierr++)){pusherr(&ierr);yyerror(arg);} YYERROR
#endif

#define code2(c1,c2)	code(c1); codein(c2)
#define code3(c1,c2,c3)	code(c1); codesym(c2); code(c3)
#define relative(ip1,ip2,offset)	((ip1-ip2) - offset)
#define CHECK 1	/* check syntactically the consistency of arrays */
#define NOCHECK 0 /* don't check syntactically. For object components */
#define PN pushi(NUMBER)	/* for type checking. expressions are usually numbers */
#define TPD hoc_ob_check(NUMBER);
#define TPDYNAM hoc_ob_check(0);

extern int pipeflag;
extern Symlist *symlist;	/* This list is permanent */
extern Symlist *p_symlist; /* Constants, strings, auto variables */
extern Symbol* hoc_decl();
extern Symbol* hoc_which_template();
extern Symbol* hoc_table_lookup();

extern arayinstal();
extern int indef;
static Inst *prog_error;			/* needed for stmtlist loc if error */
static int ntab;			/* auto indentation */
extern FILE	*fin;				/* input file pointer */

static Inst* argcode(), *argrefcode();
 


/* Line 268 of yacc.c  */
#line 156 "parse.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EQNEQ = 258,
     FUNCTION = 259,
     NUMBER = 260,
     STRING = 261,
     PRINT = 262,
     parseDELETE = 263,
     VAR = 264,
     BLTIN = 265,
     UNDEF = 266,
     WHILE = 267,
     IF = 268,
     ELSE = 269,
     FOR = 270,
     PROCEDURE = 271,
     RETURN = 272,
     FUNC = 273,
     parsePROC = 274,
     HOCOBJFUNC = 275,
     READ = 276,
     parseDOUBLE = 277,
     DEBUG = 278,
     EDIT = 279,
     FUN_BLTIN = 280,
     DEPENDENT = 281,
     EQUATION = 282,
     LOCAL = 283,
     HOCOBJFUNCTION = 284,
     BREAK = 285,
     CONTINUE = 286,
     AUTO = 287,
     STRDEF = 288,
     STOPSTMT = 289,
     CSTRING = 290,
     PARALLEL = 291,
     HELP = 292,
     ITERATOR = 293,
     ITERKEYWORD = 294,
     ITERSTMT = 295,
     STRINGFUNC = 296,
     OBJECTFUNC = 297,
     LOCALOBJ = 298,
     AUTOOBJ = 299,
     ARG = 300,
     NUMZERO = 301,
     ARGREF = 302,
     SECTIONKEYWORD = 303,
     SECTION = 304,
     CONNECTKEYWORD = 305,
     ACCESSKEYWORD = 306,
     RANGEVAR = 307,
     MECHANISM = 308,
     INSERTKEYWORD = 309,
     FORALL = 310,
     NRNPNTVAR = 311,
     FORSEC = 312,
     IFSEC = 313,
     UNINSERTKEYWORD = 314,
     SETPOINTERKEYWORD = 315,
     SECTIONREF = 316,
     BEGINTEMPLATE = 317,
     ENDTEMPLATE = 318,
     NEW = 319,
     OBJECTVAR = 320,
     TEMPLATE = 321,
     OBJVARDECL = 322,
     PUBLICDECL = 323,
     EXTERNALDECL = 324,
     OBFUNCTION = 325,
     STRFUNCTION = 326,
     OBJECTARG = 327,
     STRINGARG = 328,
     ROP = 329,
     OR = 330,
     AND = 331,
     NE = 332,
     EQ = 333,
     LE = 334,
     LT = 335,
     GE = 336,
     GT = 337,
     NOT = 338,
     UNARYMINUS = 339
   };
#endif
/* Tokens.  */
#define EQNEQ 258
#define FUNCTION 259
#define NUMBER 260
#define STRING 261
#define PRINT 262
#define parseDELETE 263
#define VAR 264
#define BLTIN 265
#define UNDEF 266
#define WHILE 267
#define IF 268
#define ELSE 269
#define FOR 270
#define PROCEDURE 271
#define RETURN 272
#define FUNC 273
#define parsePROC 274
#define HOCOBJFUNC 275
#define READ 276
#define parseDOUBLE 277
#define DEBUG 278
#define EDIT 279
#define FUN_BLTIN 280
#define DEPENDENT 281
#define EQUATION 282
#define LOCAL 283
#define HOCOBJFUNCTION 284
#define BREAK 285
#define CONTINUE 286
#define AUTO 287
#define STRDEF 288
#define STOPSTMT 289
#define CSTRING 290
#define PARALLEL 291
#define HELP 292
#define ITERATOR 293
#define ITERKEYWORD 294
#define ITERSTMT 295
#define STRINGFUNC 296
#define OBJECTFUNC 297
#define LOCALOBJ 298
#define AUTOOBJ 299
#define ARG 300
#define NUMZERO 301
#define ARGREF 302
#define SECTIONKEYWORD 303
#define SECTION 304
#define CONNECTKEYWORD 305
#define ACCESSKEYWORD 306
#define RANGEVAR 307
#define MECHANISM 308
#define INSERTKEYWORD 309
#define FORALL 310
#define NRNPNTVAR 311
#define FORSEC 312
#define IFSEC 313
#define UNINSERTKEYWORD 314
#define SETPOINTERKEYWORD 315
#define SECTIONREF 316
#define BEGINTEMPLATE 317
#define ENDTEMPLATE 318
#define NEW 319
#define OBJECTVAR 320
#define TEMPLATE 321
#define OBJVARDECL 322
#define PUBLICDECL 323
#define EXTERNALDECL 324
#define OBFUNCTION 325
#define STRFUNCTION 326
#define OBJECTARG 327
#define STRINGARG 328
#define ROP 329
#define OR 330
#define AND 331
#define NE 332
#define EQ 333
#define LE 334
#define LT 335
#define GE 336
#define GT 337
#define NOT 338
#define UNARYMINUS 339




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 86 "parse.y"
				/* stack type */
	Symbol	*sym;			/* symbol table pointer */
	Inst	*inst;			/* machine instruction */
	int	narg;			/* number of arguments */



/* Line 293 of yacc.c  */
#line 368 "parse.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 380 "parse.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2863

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  280
/* YYNRULES -- Number of states.  */
#define YYNSTATES  546

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,    93,     2,     2,     2,     2,
      92,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    88,   104,     2,
      94,    95,    86,    84,    99,    85,    98,    87,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   102,   103,
       2,    75,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    96,     2,    97,    91,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,     2,   101,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      76,    77,    78,    79,    80,    81,    82,    83,    89,    90
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    15,    19,    23,    27,
      31,    35,    39,    43,    44,    49,    52,    56,    60,    65,
      69,    77,    81,    85,    86,    90,    92,    94,    99,   105,
     111,   113,   115,   116,   123,   126,   127,   131,   134,   136,
     138,   141,   144,   148,   150,   153,   157,   162,   164,   167,
     171,   174,   178,   182,   186,   190,   193,   195,   197,   203,
     205,   207,   211,   215,   217,   219,   221,   223,   225,   227,
     229,   232,   235,   238,   245,   248,   251,   254,   257,   263,
     266,   272,   279,   280,   281,   292,   293,   294,   306,   311,
     316,   324,   325,   330,   332,   336,   341,   349,   357,   358,
     365,   368,   371,   374,   377,   380,   384,   395,   402,   403,
     411,   412,   413,   424,   425,   431,   432,   439,   440,   447,
     448,   455,   456,   463,   468,   469,   472,   473,   477,   482,
     483,   486,   488,   491,   495,   500,   502,   504,   508,   509,
     513,   515,   520,   522,   525,   527,   532,   536,   537,   539,
     543,   546,   550,   553,   555,   556,   557,   558,   561,   564,
     566,   568,   570,   572,   574,   577,   579,   584,   586,   588,
     594,   599,   604,   609,   613,   616,   620,   624,   628,   632,
     636,   640,   643,   647,   651,   655,   659,   663,   667,   671,
     675,   678,   680,   682,   684,   686,   690,   694,   697,   701,
     706,   708,   711,   712,   717,   721,   724,   726,   727,   732,
     734,   736,   740,   744,   746,   747,   754,   755,   762,   763,
     770,   771,   778,   780,   782,   784,   786,   788,   789,   796,
     797,   799,   801,   805,   807,   809,   812,   818,   821,   822,
     828,   830,   834,   837,   840,   841,   847,   848,   851,   852,
     855,   856,   858,   861,   865,   866,   868,   871,   875,   877,
     879,   881,   883,   885,   887,   889,   891,   893,   895,   897,
     899,   901,   903,   905,   907,   909,   911,   913,   915,   917,
     919
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,    -1,   106,    92,    -1,   106,   176,    92,
      -1,   106,   108,    92,    -1,   106,   126,    92,    -1,   106,
     163,    92,    -1,   106,    23,    92,    -1,   106,    24,    92,
      -1,   106,   122,    92,    -1,   106,   115,    92,    -1,   106,
      93,    92,    -1,    -1,   106,    37,   107,    92,    -1,   106,
       1,    -1,   169,    74,   163,    -1,    45,    74,   163,    -1,
      47,   172,    74,   163,    -1,   149,    74,   163,    -1,   112,
      74,    64,   201,    94,   184,    95,    -1,   112,    74,   163,
      -1,   169,    74,     1,    -1,    -1,    65,   110,   171,    -1,
      72,    -1,    44,    -1,    66,    96,   163,    97,    -1,    42,
     160,    94,   184,    95,    -1,    29,   160,    94,   184,    95,
      -1,   112,    -1,   109,    -1,    -1,   112,    98,   201,   113,
     171,   114,    -1,    65,     1,    -1,    -1,    94,   184,    95,
      -1,    62,   201,    -1,   119,    -1,   120,    -1,    63,   201,
      -1,    62,     1,    -1,    67,   160,   117,    -1,   118,    -1,
     118,   167,    -1,   117,    99,   118,    -1,   117,    99,   118,
     167,    -1,   201,    -1,    68,   201,    -1,   119,    99,   201,
      -1,    69,     9,    -1,   120,    99,     9,    -1,   123,    74,
     122,    -1,   112,    74,   122,    -1,   123,    74,   111,    -1,
     123,     1,    -1,   123,    -1,    35,    -1,    41,   160,    94,
     184,    95,    -1,     6,    -1,    73,    -1,    33,   160,   125,
      -1,   124,    99,   125,    -1,   201,    -1,   163,    -1,   124,
      -1,   165,    -1,   116,    -1,   121,    -1,   122,    -1,     8,
     175,    -1,    17,   160,    -1,    17,   163,    -1,    17,    64,
     201,    94,   184,    95,    -1,    40,   160,    -1,    30,   160,
      -1,    34,   160,    -1,    31,   160,    -1,    16,   160,    94,
     184,    95,    -1,     7,   174,    -1,    15,   160,   141,   126,
     161,    -1,   153,   154,   155,   156,   126,   161,    -1,    -1,
      -1,    15,   169,   127,    74,   163,    99,   163,   128,   126,
     161,    -1,    -1,    -1,    36,    15,   169,   129,    74,   163,
      99,   163,   130,   126,   161,    -1,   158,   157,   126,   161,
      -1,   159,   157,   126,   161,    -1,   159,   157,   126,   161,
      14,   126,   161,    -1,    -1,   100,   131,   162,   101,    -1,
     187,    -1,    48,   160,   147,    -1,    50,   145,    99,   163,
      -1,    50,   145,    99,   143,    94,   163,    95,    -1,    60,
     149,    94,   163,    95,    99,   152,    -1,    -1,    60,   160,
     132,   111,    99,   152,    -1,    51,   143,    -1,    51,   111,
      -1,    54,    53,    -1,    59,    53,    -1,   143,   126,    -1,
     111,   126,   161,    -1,   149,    94,   163,   102,   163,    95,
      74,   163,   102,   163,    -1,   149,    94,   163,    95,    74,
     163,    -1,    -1,    15,    94,   169,    95,   133,   126,   161,
      -1,    -1,    -1,    15,    94,   169,    99,   134,   163,    95,
     135,   126,   161,    -1,    -1,    55,   160,   136,   126,   161,
      -1,    -1,    57,   160,   122,   137,   126,   161,    -1,    -1,
      58,   160,   122,   138,   126,   161,    -1,    -1,    57,   160,
     111,   139,   126,   161,    -1,    -1,    58,   160,   111,   140,
     126,   161,    -1,    38,    94,   184,    95,    -1,    -1,   142,
     111,    -1,    -1,    49,   144,   171,    -1,   143,    94,   163,
      95,    -1,    -1,   146,   111,    -1,   148,    -1,   148,   167,
      -1,   147,    99,   148,    -1,   147,    99,   148,   167,    -1,
     201,    -1,   150,    -1,   143,    98,   150,    -1,    -1,    52,
     151,   171,    -1,   169,    -1,   149,    94,   163,    95,    -1,
     111,    -1,   149,     1,    -1,    47,    -1,    15,    94,   126,
     103,    -1,    15,    94,   103,    -1,    -1,   163,    -1,   103,
     126,    95,    -1,   103,    95,    -1,    94,   163,    95,    -1,
      12,   154,    -1,    13,    -1,    -1,    -1,    -1,   162,    92,
      -1,   162,   126,    -1,     1,    -1,     5,    -1,    46,    -1,
     169,    -1,    45,    -1,    47,   172,    -1,   149,    -1,   149,
      94,   163,    95,    -1,   111,    -1,   108,    -1,   164,   160,
      94,   184,    95,    -1,   169,    94,   184,    95,    -1,    21,
      94,   169,    95,    -1,    10,    94,   163,    95,    -1,    94,
     163,    95,    -1,    94,     1,    -1,   163,    84,   163,    -1,
     163,    85,   163,    -1,   163,    86,   163,    -1,   163,    87,
     163,    -1,   163,    88,   163,    -1,   163,    91,   163,    -1,
      85,   163,    -1,   163,    83,   163,    -1,   163,    82,   163,
      -1,   163,    81,   163,    -1,   163,    80,   163,    -1,   163,
      79,   163,    -1,   163,    78,   163,    -1,   163,    77,   163,
      -1,   163,    76,   163,    -1,    89,   163,    -1,     4,    -1,
      25,    -1,    70,    -1,    71,    -1,    22,   160,   166,    -1,
     165,    99,   166,    -1,   168,   167,    -1,    96,   163,    97,
      -1,   167,    96,   163,    97,    -1,   200,    -1,    32,   160,
      -1,    -1,     9,   160,   170,   171,    -1,   143,    98,     9,
      -1,   160,   173,    -1,   173,    -1,    -1,   173,    96,   163,
      97,    -1,   163,    -1,   122,    -1,   174,    99,   163,    -1,
     174,    99,   122,    -1,     9,    -1,    -1,    18,   181,   177,
      94,    95,   182,    -1,    -1,    19,   181,   178,    94,    95,
     182,    -1,    -1,    39,   181,   179,    94,    95,   182,    -1,
      -1,    20,   181,   180,    94,    95,   182,    -1,   200,    -1,
       4,    -1,    16,    -1,    38,    -1,    29,    -1,    -1,   100,
     196,   198,   183,   162,   101,    -1,    -1,   185,    -1,   186,
      -1,   185,    99,   186,    -1,   122,    -1,   163,    -1,   104,
     152,    -1,    64,   201,    94,   184,    95,    -1,    26,   189,
      -1,    -1,    27,   169,   102,   188,   190,    -1,   169,    -1,
     189,    99,   169,    -1,   192,     3,    -1,     3,   194,    -1,
      -1,   102,   191,   192,     3,   194,    -1,    -1,   193,   163,
      -1,    -1,   195,   163,    -1,    -1,   197,    -1,    28,   201,
      -1,   197,    99,   201,    -1,    -1,   199,    -1,    43,   201,
      -1,   199,    99,   201,    -1,     9,    -1,     6,    -1,     9,
      -1,    11,    -1,     4,    -1,    16,    -1,    25,    -1,    49,
      -1,    52,    -1,    56,    -1,    65,    -1,    66,    -1,    70,
      -1,    32,    -1,    44,    -1,    61,    -1,    53,    -1,    10,
      -1,    71,    -1,    29,    -1,    38,    -1,    41,    -1,    42,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   148,   149,   150,   152,   154,   156,   158,
     160,   164,   166,   168,   168,   169,   179,   183,   185,   188,
     192,   198,   204,   208,   208,   210,   212,   214,   216,   219,
     224,   227,   228,   228,   238,   241,   242,   245,   246,   247,
     248,   249,   251,   254,   256,   258,   260,   263,   273,   275,
     278,   280,   285,   287,   292,   294,   297,   298,   300,   304,
     306,   310,   312,   314,   327,   329,   330,   332,   334,   335,
     337,   339,   341,   350,   354,   360,   362,   364,   366,   368,
     370,   375,   386,   390,   385,   397,   401,   396,   409,   413,
     417,   423,   422,   428,   431,   432,   434,   436,   438,   438,
     441,   443,   445,   447,   449,   451,   454,   458,   463,   462,
     471,   474,   470,   480,   479,   487,   486,   493,   492,   499,
     498,   506,   505,   517,   522,   522,   528,   528,   532,   533,
     533,   543,   545,   547,   549,   552,   560,   562,   564,   564,
     567,   569,   571,   573,   574,   580,   582,   586,   588,   591,
     593,   596,   599,   602,   606,   609,   612,   613,   624,   625,
     630,   632,   634,   636,   638,   641,   643,   647,   650,   651,
     653,   655,   657,   659,   661,   663,   665,   667,   669,   671,
     673,   675,   677,   679,   681,   683,   685,   687,   689,   691,
     693,   696,   697,   698,   699,   701,   704,   709,   712,   714,
     717,   720,   723,   722,   729,   737,   772,   779,   780,   784,
     786,   788,   790,   793,   798,   797,   804,   803,   810,   809,
     816,   815,   822,   828,   829,   830,   831,   833,   833,   840,
     841,   843,   845,   848,   850,   852,   853,   858,   861,   860,
     866,   868,   871,   872,   874,   873,   878,   878,   883,   883,
     888,   889,   891,   898,   910,   911,   913,   923,   934,   942,
     942,   942,   942,   942,   942,   942,   942,   943,   943,   943,
     943,   943,   943,   943,   944,   944,   944,   944,   944,   944,
     945
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EQNEQ", "FUNCTION", "NUMBER", "STRING",
  "PRINT", "parseDELETE", "VAR", "BLTIN", "UNDEF", "WHILE", "IF", "ELSE",
  "FOR", "PROCEDURE", "RETURN", "FUNC", "parsePROC", "HOCOBJFUNC", "READ",
  "parseDOUBLE", "DEBUG", "EDIT", "FUN_BLTIN", "DEPENDENT", "EQUATION",
  "LOCAL", "HOCOBJFUNCTION", "BREAK", "CONTINUE", "AUTO", "STRDEF",
  "STOPSTMT", "CSTRING", "PARALLEL", "HELP", "ITERATOR", "ITERKEYWORD",
  "ITERSTMT", "STRINGFUNC", "OBJECTFUNC", "LOCALOBJ", "AUTOOBJ", "ARG",
  "NUMZERO", "ARGREF", "SECTIONKEYWORD", "SECTION", "CONNECTKEYWORD",
  "ACCESSKEYWORD", "RANGEVAR", "MECHANISM", "INSERTKEYWORD", "FORALL",
  "NRNPNTVAR", "FORSEC", "IFSEC", "UNINSERTKEYWORD", "SETPOINTERKEYWORD",
  "SECTIONREF", "BEGINTEMPLATE", "ENDTEMPLATE", "NEW", "OBJECTVAR",
  "TEMPLATE", "OBJVARDECL", "PUBLICDECL", "EXTERNALDECL", "OBFUNCTION",
  "STRFUNCTION", "OBJECTARG", "STRINGARG", "ROP", "'='", "OR", "AND", "NE",
  "EQ", "LE", "LT", "GE", "GT", "'+'", "'-'", "'*'", "'/'", "'%'", "NOT",
  "UNARYMINUS", "'^'", "'\\n'", "'\\005'", "'('", "')'", "'['", "']'",
  "'.'", "','", "'{'", "'}'", "':'", "';'", "'&'", "$accept", "list",
  "$@1", "asgn", "object", "$@2", "ob", "ob1", "$@3",
  "func_or_range_array_case", "template", "objvarlist", "objvarlst1",
  "obvarname", "publiclist", "externallist", "strnasgn", "string1",
  "string2", "strlist", "string", "stmt", "@4", "@5", "@6", "@7", "$@8",
  "$@9", "@10", "$@11", "@12", "@13", "@14", "@15", "@16", "@17",
  "iterator", "$@18", "section", "$@19", "section_or_ob", "@20",
  "sectiondecl", "sectionname", "rangevar", "rangevar1", "$@21", "pointer",
  "for_init", "for_st", "for_cond", "for_inc", "cond", "while", "if",
  "begin", "end", "stmtlist", "expr", "function", "doublelist", "newarray",
  "numdimen", "newname", "varname", "$@22", "wholearray", "argrefdim",
  "array", "prlist", "delsym", "defn", "$@23", "$@24", "$@25", "$@26",
  "procname", "procstmt", "$@27", "arglist", "arglist1", "arglist2",
  "eqn_list", "$@28", "dep_list", "equation", "$@29", "lhs", "$@30", "rhs",
  "$@31", "local", "local1", "localobj", "local2", "ckvar", "anyname", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    61,   330,   331,   332,   333,
     334,   335,   336,   337,    43,    45,    42,    47,    37,   338,
     339,    94,    10,     5,    40,    41,    91,    93,    46,    44,
     123,   125,    58,    59,    38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   107,   106,   106,   108,   108,   108,   108,
     108,   108,   108,   110,   109,   109,   109,   109,   109,   109,
     111,   112,   113,   112,   112,   114,   114,   115,   115,   115,
     115,   115,   116,   117,   117,   117,   117,   118,   119,   119,
     120,   120,   121,   121,   121,   121,   122,   122,   122,   123,
     123,   124,   124,   125,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   128,   126,   129,   130,   126,   126,   126,
     126,   131,   126,   126,   126,   126,   126,   126,   132,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   133,   126,
     134,   135,   126,   136,   126,   137,   126,   138,   126,   139,
     126,   140,   126,   141,   142,   141,   144,   143,   145,   146,
     145,   147,   147,   147,   147,   148,   149,   149,   151,   150,
     152,   152,   152,   152,   152,   153,   153,   154,   155,   156,
     156,   157,   158,   159,   160,   161,   162,   162,   162,   162,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   164,   164,   164,   164,   165,   165,   166,   167,   167,
     168,   169,   170,   169,   169,   171,   172,   173,   173,   174,
     174,   174,   174,   175,   177,   176,   178,   176,   179,   176,
     180,   176,   181,   181,   181,   181,   181,   183,   182,   184,
     184,   185,   185,   186,   186,   186,   186,   187,   188,   187,
     189,   189,   190,   190,   191,   190,   193,   192,   195,   194,
     196,   196,   197,   197,   198,   198,   199,   199,   200,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     0,     4,     2,     3,     3,     4,     3,
       7,     3,     3,     0,     3,     1,     1,     4,     5,     5,
       1,     1,     0,     6,     2,     0,     3,     2,     1,     1,
       2,     2,     3,     1,     2,     3,     4,     1,     2,     3,
       2,     3,     3,     3,     3,     2,     1,     1,     5,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     6,     2,     2,     2,     2,     5,     2,
       5,     6,     0,     0,    10,     0,     0,    11,     4,     4,
       7,     0,     4,     1,     3,     4,     7,     7,     0,     6,
       2,     2,     2,     2,     2,     3,    10,     6,     0,     7,
       0,     0,    10,     0,     5,     0,     6,     0,     6,     0,
       6,     0,     6,     4,     0,     2,     0,     3,     4,     0,
       2,     1,     2,     3,     4,     1,     1,     3,     0,     3,
       1,     4,     1,     2,     1,     4,     3,     0,     1,     3,
       2,     3,     2,     1,     0,     0,     0,     2,     2,     1,
       1,     1,     1,     1,     2,     1,     4,     1,     1,     5,
       4,     4,     4,     3,     2,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     3,     3,     2,     3,     4,
       1,     2,     0,     4,     3,     2,     1,     0,     4,     1,
       1,     3,     3,     1,     0,     6,     0,     6,     0,     6,
       0,     6,     1,     1,     1,     1,     1,     0,     6,     0,
       1,     1,     3,     1,     1,     2,     5,     2,     0,     5,
       1,     3,     2,     2,     0,     5,     0,     2,     0,     2,
       0,     1,     2,     3,     0,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,    15,   191,   160,    59,     0,     0,   154,
       0,   147,   153,   154,   154,   154,     0,     0,     0,     0,
     154,     0,     0,   192,     0,     0,   154,   154,   154,   154,
     154,   154,    57,     0,    13,     0,   154,   154,   154,    26,
     163,   161,   207,   154,   126,   129,     0,   138,     0,   154,
     154,   154,     0,   154,     0,     0,     0,     0,   154,     0,
       0,   193,   194,    25,    60,     0,     0,     3,     0,     0,
      91,   168,    31,   167,    30,     0,    67,    38,    39,    68,
       0,     0,    65,     0,     0,   165,   136,   147,     0,     0,
       0,   154,    66,   162,     0,    93,   168,   167,    30,   210,
      56,     0,   165,   209,    79,   213,    70,   202,     0,   152,
       0,     0,   124,    82,     0,     0,    71,    72,   223,   258,
     224,   226,   225,   214,   222,   216,   220,     0,     0,     8,
       9,   240,   237,     0,     0,    75,    77,   201,     0,    76,
       0,     0,   218,    74,     0,     0,     0,   164,   206,     0,
     154,     0,     0,     0,   101,    30,   100,   154,   102,   113,
       0,     0,   103,     0,     0,    98,    41,   262,   259,   260,
     275,   261,   263,   264,   277,   271,   278,   279,   280,   272,
     265,   266,   274,   267,   273,   268,   269,   270,   276,    37,
      40,    34,   154,     0,     0,    48,    50,   181,   190,    12,
     174,     0,     0,     5,    69,   155,    64,     0,     0,    11,
       0,     0,    10,    55,     0,     0,     6,     0,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,   229,     4,     0,     0,     0,   154,     0,
     146,     0,   162,     0,     0,     0,     0,     0,   229,     0,
       0,     0,     0,     0,   195,     0,   200,     0,   238,   229,
      61,    63,    85,    14,     0,   229,   229,    17,     0,     0,
      94,   131,   135,   207,   127,     0,     0,   130,   139,     0,
     119,   115,   121,   117,     0,     0,     0,    24,     0,    42,
      43,    47,   173,   159,     0,   105,     0,    53,    21,    32,
      49,    51,    54,    52,    62,   204,   137,    19,     0,     0,
     148,     0,   155,   155,   189,   188,   187,   186,   185,   184,
     183,   182,   175,   176,   177,   178,   179,   180,   229,   196,
      22,    16,     0,     0,   233,   234,     0,   230,   231,     0,
     212,   211,   203,   172,   145,   108,   110,   229,   155,   125,
       0,     0,   229,     0,     0,     0,   171,     0,   197,   241,
     246,     0,     0,     0,     0,     0,    18,     0,     0,   132,
     205,     0,     0,    95,   155,     0,     0,     0,     0,     0,
       0,    27,     0,    44,   157,    92,   158,     0,   154,   166,
       0,     0,     0,   151,    88,    89,     0,     0,   144,   142,
       0,   235,   140,   170,     0,   166,     0,     0,     0,    80,
       0,    78,     0,     0,     0,     0,     0,     0,   248,   244,
     239,     0,     0,    29,     0,     0,    58,    28,   208,   133,
     128,     0,   114,   155,   155,   155,   155,     0,     0,    45,
     229,    35,     0,     0,   150,     0,   155,     0,   169,   229,
     143,     0,   232,   155,     0,   123,     0,    73,   250,   215,
     217,   221,   198,     0,   243,     0,   246,   242,   247,     0,
     219,   134,     0,   120,   116,   122,   118,     0,    99,    46,
       0,   229,    33,   107,     0,   149,    81,   155,     0,     0,
     109,   111,    83,     0,   254,   251,   199,   249,     0,     0,
      96,    97,    20,     0,     0,    90,   236,   141,     0,     0,
     252,     0,   227,   255,     0,   248,    86,    36,     0,   155,
     155,   256,     0,     0,   253,   245,     0,     0,   112,    84,
       0,   257,   155,   106,   228,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   141,    96,    72,   192,    97,    98,   398,   492,
      75,    76,   299,   300,    77,    78,    79,   204,    81,    82,
     270,   396,   257,   519,   372,   536,   202,   296,   416,   417,
     518,   289,   386,   388,   385,   387,   255,   256,   101,   150,
     152,   153,   280,   281,   102,    86,   157,   411,    87,   109,
     319,   402,   223,    88,    89,   283,   305,   304,   206,    91,
      92,   264,   368,   265,    93,   248,   284,   147,   148,   104,
     106,    94,   260,   261,   274,   262,   123,   469,   532,   346,
     347,   348,    95,   370,   132,   430,   476,   431,   432,   474,
     475,   504,   505,   522,   523,   124,   271
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -423
static const yytype_int16 yypact[] =
{
    -423,  1094,  -423,  -423,  -423,  -423,  -423,  2100,    16,  -423,
     -81,  -423,  -423,     3,  -423,  2154,    57,    57,    57,   -67,
    -423,   -61,   -46,  -423,     2,     2,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,    26,  -423,    57,  -423,  -423,  -423,  -423,
       8,  -423,  -423,  -423,  -423,    29,    15,  -423,    36,  -423,
    -423,  -423,    37,    18,  2394,  2447,   887,   -17,  -423,  2447,
      83,  -423,  -423,  -423,  -423,  2270,  2270,  -423,    19,  1918,
    -423,    20,  -423,  1844,   -58,    21,  -423,    -5,    22,  -423,
      24,   990,    31,    28,  1650,   -55,  -423,  -423,    40,    40,
    2755,  -423,    32,   -51,    30,  -423,  -423,  -423,   -56,  -423,
    -423,    42,    -3,  2772,    39,  -423,  -423,  -423,  2270,  -423,
    1354,    43,    97,  -423,    45,  2447,  -423,  2772,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,     2,   134,  -423,
    -423,  -423,    46,    44,    50,  -423,  -423,  -423,  2447,  -423,
       2,    55,  -423,  -423,    54,    59,  2270,    75,    58,  2447,
    -423,    61,    52,   -12,  -423,    60,  -423,  -423,  -423,  -423,
     160,   160,  -423,    64,    62,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  2270,  2447,  -423,  -423,    77,    77,  -423,
    -423,  2555,  1191,  -423,  -423,  -423,  2772,  2030,  2447,  -423,
    2447,   161,  -423,  -423,   160,  2447,  -423,     6,  -423,  2270,
    2270,  2270,  2270,  1844,  1844,  2270,  2270,  2270,  2270,  2270,
    2270,  2270,  2270,  2270,  2270,  2270,  2270,  2270,  2270,  -423,
      78,   134,  1972,  1261,  -423,  2212,  2270,  2100,  -423,  2575,
    -423,    66,   -66,   164,    80,  1844,   -12,   101,  1261,    82,
      85,    86,    87,    93,  -423,    81,  -423,     2,  -423,  1261,
    -423,  -423,  -423,  -423,    96,  1261,  1261,  2772,  2270,  2270,
      79,    81,  -423,  -423,  -423,  2270,  2270,  -423,  -423,  1844,
    -423,  -423,  -423,  -423,   139,  2270,   -12,  -423,  2467,    95,
      81,  -423,  -423,  -423,  1454,  -423,  2447,  -423,  2772,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  2772,   272,    89,
    2772,  2595,  -423,  -423,  2246,  1090,    41,    41,    41,    41,
      41,    41,    17,    17,    77,    77,    77,    77,  1261,  -423,
    -423,  2772,  2447,   232,  -423,  2772,   102,   100,  -423,  2615,
    -423,  2772,  -423,  -423,  -423,  -423,  -423,  1261,  -423,  -423,
    2270,   105,  1261,   110,   111,   112,  -423,  2270,   113,  -423,
      -2,   115,   137,   117,   119,   120,  2772,  2489,  2447,   113,
      58,  2635,   -84,  2772,  -423,  1844,  1844,  1844,  1844,  2655,
     118,  -423,  2447,   113,  -423,  -423,  -423,   122,  -423,   146,
    2270,  1747,  1844,  -423,  -423,   194,   126,   135,  -423,  -423,
       5,  -423,  -423,  -423,  1261,  -423,  1844,  2270,   136,  -423,
     659,  -423,   140,   138,   138,   138,  2511,  2270,  -423,  -423,
    -423,   231,  2270,  -423,  2270,   138,  -423,  -423,  -423,    81,
    -423,  2270,  -423,  -423,  -423,  -423,  -423,   141,   232,    81,
    1261,   142,  2270,  2675,  -423,   147,  -423,  1844,  -423,  1261,
    -423,  2270,  -423,  -423,  2695,  -423,  2270,  -423,   216,  -423,
    -423,  -423,  -423,  2533,  -423,  2270,  -423,  -423,  2772,  2443,
    -423,   113,  2715,  -423,  -423,  -423,  -423,   232,  -423,   113,
     150,  1261,  -423,  2772,   174,  -423,  -423,  -423,   154,  2735,
    -423,  -423,  2772,  2447,   207,   152,  -423,  2772,   249,  2270,
    -423,  -423,  -423,   158,  2270,  -423,  -423,  -423,  1844,  1844,
    -423,  2447,  -423,   157,  2447,  -423,  2772,  -423,   238,  -423,
    -423,  -423,  1191,  2447,  -423,  -423,  1844,  2270,  -423,  -423,
    1552,  -423,  -423,  2772,  -423,  -423
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -423,  -423,  -423,   256,  -423,  -423,    -1,     4,  -423,  -423,
    -423,  -423,  -423,  -134,  -423,  -423,  -423,   395,   415,  -423,
      47,   109,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,    23,  -423,
    -423,  -423,  -423,  -113,   114,  -210,  -423,  -422,  -423,   179,
    -423,  -423,   178,  -423,  -423,  2343,  -260,  -264,   361,  -423,
    -423,    34,  -278,  -423,    -4,  -423,  -155,  -423,   -11,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,    84,  -350,  -423,  -220,
    -423,  -141,  -423,  -423,  -423,  -423,  -423,  -199,  -423,  -245,
    -423,  -423,  -423,  -423,  -423,  -124,   318
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -157
static const yytype_int16 yytable[] =
{
      73,   428,   288,   379,   266,    74,   460,   316,   242,   113,
     441,     9,     9,   108,   217,   315,   207,    26,   245,   219,
     131,   133,   393,   242,    84,   105,   488,   127,   243,   355,
      38,   129,    39,   356,    29,    29,   111,   297,   361,   220,
     208,   140,   208,   243,    26,   154,   130,   111,   111,   371,
     155,    44,    44,    56,    57,   374,   375,    38,    47,    39,
      63,   118,   404,   405,    44,   511,   119,    44,   151,   156,
      47,   219,    73,   120,   470,   471,   163,    74,    44,   193,
      56,    57,   146,    73,   316,   480,   121,    63,    74,   158,
     162,   246,   196,   352,   210,   122,    84,   110,   419,   461,
     429,   125,   126,   235,   236,   237,   252,    84,   238,    73,
      83,   199,   203,   209,    74,    85,   212,   266,   406,   142,
     216,   211,   244,   263,   442,   233,   234,   235,   236,   237,
     215,   241,   238,    84,   222,   254,   272,   418,   247,   258,
     217,   253,   422,   119,   269,   267,   268,   273,   275,   278,
     111,   286,   287,   276,   279,   285,   295,   155,   208,   290,
     292,   481,   294,   111,   155,   155,     6,   164,   238,   354,
     311,   489,   338,   315,   357,   360,   362,   367,   378,   363,
     364,   365,   205,   483,   484,   485,   486,    85,   366,    26,
     373,    47,   401,   218,   392,    32,   496,   413,    85,   414,
     421,    37,    38,   500,    39,   423,   424,   425,   457,   427,
     433,   434,   435,   312,   436,   437,   450,   448,   155,   251,
     452,   458,    73,    73,    85,    56,    57,    74,    74,   459,
     490,   465,    63,    64,   477,   467,   491,   515,   468,   498,
     487,     9,   495,   451,   503,   512,    84,    84,   514,   516,
     521,   524,   525,   527,    73,   359,   533,    71,   449,    74,
     155,    26,   314,   369,    29,   439,   221,   224,   540,   538,
     539,   513,   380,   462,    38,   339,    39,   508,    84,   408,
     535,    44,   545,     0,    47,     0,     0,     0,    73,     0,
     111,     0,     0,    74,     0,   390,     0,    56,    57,     0,
     155,     0,     0,    73,    63,     0,     0,     0,    74,   382,
       0,     0,    84,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    84,     0,   238,
       0,     0,   322,   323,     0,     0,     0,    85,    85,   412,
     537,     0,   409,     0,     0,     0,     0,   155,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     0,    90,   238,   358,     0,     0,   399,   103,    85,
       0,     0,   189,   190,   400,     0,   117,   195,     0,     0,
       0,     0,     0,     0,    73,    73,    73,    73,     0,    74,
      74,    74,    74,     0,     0,     0,    80,     0,   384,     0,
      73,    73,    99,    85,     0,    74,    74,     0,    84,    84,
      84,    84,     0,     0,     0,    73,     0,     0,    85,     0,
      74,     0,   100,     0,    84,    84,   197,   198,     0,     0,
     201,     0,     0,   259,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,   412,     0,     0,   409,     0,     0,
       0,     0,   155,     0,     0,     0,    73,   410,     0,     0,
       0,    74,     0,     0,     0,     0,     0,   282,     0,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,   412,     0,     0,   409,     0,     0,     0,
       0,   155,     0,     0,   443,   444,   445,   446,     0,    85,
      85,    85,    85,     0,     0,     0,     0,   277,     0,     0,
     455,   456,   301,     0,     0,    85,    85,    73,    73,     0,
       0,     0,    74,    74,     0,   463,   309,     0,   310,     0,
      85,     0,     0,     0,     0,    73,     0,     0,     0,    73,
      74,    84,    84,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,   291,   293,     0,     0,    84,
       0,     0,   410,    84,     0,     0,   497,     0,   308,     0,
       0,    85,     0,     0,     0,   100,   100,     0,     0,     0,
     317,   318,   320,   321,     0,     0,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
       0,   410,   307,   341,   345,     0,   308,   349,   351,   313,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   345,
       0,     0,   100,     0,   397,     0,     0,   529,   530,   100,
     345,     0,    85,    85,     0,     0,   345,   345,   344,   376,
     377,     0,   350,     0,     0,   542,   381,   383,     0,     0,
      85,     0,     0,   344,    85,     0,   389,     0,   100,     0,
     407,     0,   100,     0,   344,     0,     0,     0,     0,     0,
     344,   344,     0,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     0,     0,     0,
     100,   100,     0,     0,     0,     0,   282,     0,     0,   345,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,     0,   345,     0,
       0,   420,     0,   345,     0,     0,     0,     0,   426,     0,
       0,     0,     0,   344,     0,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,     0,
     238,     0,   344,   100,     0,     0,     0,   344,   466,     0,
       0,   453,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,   345,     0,   100,   464,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   473,     0,
       0,     0,     0,   478,     0,   479,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,   344,
       0,   345,     0,   493,     0,     0,     0,     0,     0,     0,
     345,   520,   499,     0,     0,     0,     0,   502,     0,   100,
       0,     0,     0,     0,     0,     0,   507,     0,     0,   531,
       0,     0,   534,     0,     0,   344,     0,     0,     0,     0,
       0,   541,   345,     0,   344,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,     0,     0,
     526,     0,     0,     0,   100,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   344,     0,   191,     0,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   543,   -23,
     -23,   -23,   -23,   -23,   -23,     0,   100,     0,   -23,   -23,
       0,     0,   -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,     0,     0,     0,   -23,   -23,   -23,
       0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
       0,   -23,   -23,     0,   -23,   -23,   -23,   -23,     0,     0,
       0,     0,   -23,   -23,   -23,     0,     0,   -23,   -23,   -23,
     -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,
       0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   213,     0,     0,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
       0,   -56,   -56,     0,     0,   -56,   -56,   -56,     0,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,
     -56,   -56,   -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,     0,   -56,   -56,     0,   -56,   -56,   -56,
     -56,     0,     0,     0,     0,   -56,   -56,   -56,     0,     0,
     -56,   -56,   -56,   -56,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -56,     0,     0,     0,   -56,
       0,     0,   -56,     0,   -56,   -56,     0,     0,     0,     0,
     -56,   -56,     0,   -56,     2,     3,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,    11,    12,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
       0,    50,    51,    52,    53,     0,    54,    55,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,    65,
       0,   238,     0,    66,     0,     0,    67,    68,    69,     0,
       0,     0,   303,     0,    70,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,     0,  -156,  -156,     0,  -156,  -156,  -156,     0,
       0,     0,  -156,  -156,     0,     0,  -156,  -156,  -156,     0,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,     0,     0,
       0,  -156,  -156,  -156,     0,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,     0,  -156,  -156,     0,  -156,  -156,
    -156,  -156,     0,     0,     0,     0,  -156,  -156,  -156,     0,
       0,  -156,  -156,  -156,  -156,     4,     5,     6,     0,     0,
       9,    10,     0,     0,     0,     0,  -156,     0,     0,     0,
    -156,     0,    19,  -156,     0,  -156,    23,     0,     0,     0,
      26,  -156,  -156,    29,     0,     0,    32,     0,     0,     0,
       0,     0,    37,    38,     0,    39,    40,    41,    42,     0,
      44,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   342,    56,    57,     0,     0,
       0,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
      66,     0,     0,     0,     0,    69,     0,     0,     4,     5,
       6,     7,     8,     9,    10,   343,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    19,    20,     0,     0,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     0,     0,    36,    37,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
       0,    50,    51,    52,    53,     0,     0,     0,     0,    56,
      57,    58,     0,     0,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,    66,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,    70,     0,     0,   250,     4,     5,
       6,     7,     8,     9,    10,     0,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    19,    20,     0,     0,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     0,     0,    36,    37,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
       0,    50,    51,    52,    53,     0,     0,     0,     0,    56,
      57,    58,     0,     0,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,    66,     0,     0,   394,     0,    69,     0,
       0,     0,     0,     0,    70,   395,     4,     5,     6,     7,
       8,     9,    10,     0,    11,    12,     0,    13,    14,    15,
       0,     0,     0,    19,    20,     0,     0,    23,    24,    25,
       0,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,     0,    36,    37,    38,     0,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,     0,    50,
      51,    52,    53,     0,     0,     0,     0,    56,    57,    58,
       0,     0,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,    66,     0,     0,   394,     0,    69,     0,     0,     0,
       0,     0,    70,   544,     4,     5,     6,     7,     8,     9,
      10,     0,    11,    12,     0,    13,    14,    15,     0,     0,
       0,    19,    20,     0,     0,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,     0,     0,     0,
      36,    37,    38,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,     0,    50,    51,    52,
      53,     0,     0,     0,     0,    56,    57,    58,     0,     0,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,    66,
       0,     0,     0,     0,    69,     0,     0,     0,   217,     0,
      70,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,     0,    13,    14,    15,     0,     0,     0,    19,    20,
       0,     0,    23,    24,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,     0,    36,    37,    38,
       0,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,     0,    50,    51,    52,    53,     0,     0,
       0,     0,    56,    57,    58,     0,     0,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,     0,     0,    66,     0,     0,     0,
       0,    69,   454,     0,     0,     0,     0,    70,     4,     5,
       6,     7,     8,     9,    10,     0,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    19,    20,     0,     0,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     0,     0,    36,    37,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
       0,    50,    51,    52,    53,     0,     0,     0,     0,    56,
      57,    58,     0,     0,    61,    62,    63,    64,     0,   200,
       0,     0,     4,     5,     0,     0,     0,     9,    10,    65,
       0,     0,     0,    66,     0,     0,     0,     0,    69,    19,
       0,     0,     0,    23,    70,     0,     0,    26,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,    39,    40,    41,    42,     0,    44,     0,     0,
      47,     0,     0,   340,     0,     0,     4,     5,     0,     0,
       0,     9,    10,    56,    57,     0,     0,     0,    61,    62,
      63,     0,     0,    19,     0,     0,     0,    23,     0,     0,
       0,    26,     0,    65,    29,     0,     0,    66,     0,     0,
       0,     0,    69,     0,    38,     0,    39,    40,    41,    42,
       0,    44,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,    56,    57,     9,
      10,     0,    61,    62,    63,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,    23,     0,    65,     0,    26,
       0,    66,    29,     0,     0,    32,    69,     0,     0,     0,
       0,    37,    38,     0,    39,    40,    41,    42,     0,    44,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,    56,    57,     0,     0,     0,
      61,    62,    63,    64,     4,     5,     6,     0,     0,     9,
      10,     0,     0,     0,     0,    65,     0,     0,     0,    66,
       0,    19,     0,     0,    69,    23,     0,     0,     0,    26,
       0,     0,    29,     0,     0,    32,     0,     0,     0,     0,
       0,    37,    38,     0,    39,    40,    41,    42,     0,    44,
       0,     0,    47,     0,     0,     0,     0,     0,     4,     5,
       0,     0,     0,     9,    10,    56,    57,     0,     0,     0,
      61,    62,    63,    64,     0,    19,     0,     0,     0,    23,
       0,     0,     0,    26,     0,    65,    29,     0,     0,    66,
       0,     0,     0,     0,    69,     0,    38,     0,    39,    40,
      41,    42,     0,    44,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,   115,    56,
      57,     9,    10,     0,    61,    62,    63,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,    23,     0,    65,
       0,    26,     0,    66,    29,     0,     0,     0,    69,     0,
       0,     0,     0,     0,    38,     0,    39,    40,    41,    42,
       0,    44,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,   306,    56,    57,     9,
      10,     0,    61,    62,    63,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,    23,     0,    65,     0,    26,
       0,    66,    29,     0,     0,     0,    69,     0,     0,     0,
       0,     0,    38,     0,    39,    40,    41,    42,     0,    44,
       0,     0,    47,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    56,    57,   238,     0,     0,
      61,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,    65,   112,   114,   116,    66,
       0,     0,     0,   128,    69,     0,     0,     0,     0,   134,
     135,   136,   137,   138,   139,     0,     0,     0,     0,   143,
     144,   145,     0,     0,     0,     0,   149,     0,     0,     0,
       0,     0,   159,   160,   161,   166,   165,     0,   167,     0,
     168,   194,     0,   169,   170,   171,     0,     0,     0,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,     0,     0,   174,     0,     0,   175,     0,     0,     0,
       0,     0,   176,     0,   240,   177,   178,     0,   179,     0,
       0,     0,     0,   180,     0,     0,   181,   182,     0,     0,
     183,   167,     0,   168,     0,   184,   169,   170,   171,   185,
     186,     0,     0,   172,   187,   188,     0,     0,     0,     0,
       0,     0,   173,     0,     0,     0,   174,     0,     0,   175,
       0,     0,     0,     0,     0,   176,     0,     0,   177,   178,
       0,   179,     0,     0,     0,     0,   180,     0,     0,   181,
     182,     0,     0,   183,     0,     0,     0,     0,   184,     0,
       0,     0,   185,   186,     0,     0,     0,   187,   188,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,     0,   238,     0,     0,     0,     0,     0,
       0,     0,   509,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,     0,   238,     0,
       0,     0,     0,     0,   391,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,     0,
     238,     0,     0,     0,     0,     0,   438,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,     0,   238,     0,     0,     0,     0,     0,   472,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,     0,   238,     0,     0,     0,     0,     0,
     506,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,     0,     0,     0,
     302,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,     0,     0,     0,
     353,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,     0,     0,     0,
     403,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,     0,     0,     0,
     415,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,     0,     0,     0,
     440,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,     0,     0,     0,
     447,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,     0,     0,     0,
     494,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,     0,     0,     0,
     501,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,     0,     0,     0,
     510,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,     0,     0,     0,
     517,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,   238,   239,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     0,     0,   238
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-423))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,     3,   157,   281,   128,     1,     1,   217,    74,    13,
      94,     9,     9,    94,    98,     9,    74,    29,    74,    74,
      24,    25,   300,    74,     1,     9,   448,    94,    94,    95,
      42,    92,    44,    99,    32,    32,    13,   192,   258,    94,
      98,    15,    98,    94,    29,    46,    92,    24,    25,   269,
      46,    49,    49,    65,    66,   275,   276,    42,    52,    44,
      72,     4,   322,   323,    49,   487,     9,    49,    45,    46,
      52,    74,    73,    16,   424,   425,    53,    73,    49,    96,
      65,    66,    74,    84,   294,   435,    29,    72,    84,    53,
      53,    94,     9,   248,    99,    38,    73,    94,   358,    94,
     102,    17,    18,    86,    87,    88,   110,    84,    91,   110,
       1,    92,    92,    92,   110,     1,    92,   241,   338,    35,
      92,    99,    92,   127,   384,    84,    85,    86,    87,    88,
      99,    99,    91,   110,    94,    38,   140,   357,    99,    94,
      98,    98,   362,     9,    94,    99,   102,    92,    94,    74,
     127,    99,   153,    94,    96,    94,    94,   153,    98,   160,
     161,   439,    98,   140,   160,   161,     6,    53,    91,   103,
       9,   449,    94,     9,    94,    74,    94,    96,    99,    94,
      94,    94,    73,   443,   444,   445,   446,    73,    95,    29,
      94,    52,   103,    84,    99,    35,   456,    95,    84,    99,
      95,    41,    42,   463,    44,    95,    95,    95,    14,    96,
      95,    74,    95,   214,    95,    95,    94,    99,   214,   110,
      74,    95,   223,   224,   110,    65,    66,   223,   224,    94,
     450,    95,    72,    73,     3,    95,    94,   497,   100,   459,
      99,     9,    95,   398,    28,    95,   223,   224,    74,    95,
      43,    99,     3,    95,   255,   256,    99,     1,   392,   255,
     256,    29,   215,   267,    32,   378,    87,    89,   532,   529,
     530,   491,   283,   414,    42,   241,    44,   476,   255,    47,
     525,    49,   542,    -1,    52,    -1,    -1,    -1,   289,    -1,
     267,    -1,    -1,   289,    -1,   296,    -1,    65,    66,    -1,
     296,    -1,    -1,   304,    72,    -1,    -1,    -1,   304,   286,
      -1,    -1,   289,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,   304,    -1,    91,
      -1,    -1,   223,   224,    -1,    -1,    -1,   223,   224,   343,
     102,    -1,   343,    -1,    -1,    -1,    -1,   343,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,     1,    91,   255,    -1,    -1,    95,     7,   255,
      -1,    -1,    54,    55,   102,    -1,    15,    59,    -1,    -1,
      -1,    -1,    -1,    -1,   385,   386,   387,   388,    -1,   385,
     386,   387,   388,    -1,    -1,    -1,     1,    -1,   289,    -1,
     401,   402,     7,   289,    -1,   401,   402,    -1,   385,   386,
     387,   388,    -1,    -1,    -1,   416,    -1,    -1,   304,    -1,
     416,    -1,     7,    -1,   401,   402,    65,    66,    -1,    -1,
      69,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,    -1,    -1,   448,    -1,    -1,   448,    -1,    -1,
      -1,    -1,   448,    -1,    -1,    -1,   457,   343,    -1,    -1,
      -1,   457,    -1,    -1,    -1,    -1,    -1,   149,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     457,    -1,    -1,   487,    -1,    -1,   487,    -1,    -1,    -1,
      -1,   487,    -1,    -1,   385,   386,   387,   388,    -1,   385,
     386,   387,   388,    -1,    -1,    -1,    -1,   146,    -1,    -1,
     401,   402,   194,    -1,    -1,   401,   402,   518,   519,    -1,
      -1,    -1,   518,   519,    -1,   416,   208,    -1,   210,    -1,
     416,    -1,    -1,    -1,    -1,   536,    -1,    -1,    -1,   540,
     536,   518,   519,    -1,   540,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   160,   161,    -1,    -1,   536,
      -1,    -1,   448,   540,    -1,    -1,   457,    -1,   207,    -1,
      -1,   457,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,
     219,   220,   221,   222,    -1,    -1,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,   487,   207,   242,   243,    -1,   245,   246,   247,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,   207,    -1,   306,    -1,    -1,   518,   519,   214,
     269,    -1,   518,   519,    -1,    -1,   275,   276,   243,   278,
     279,    -1,   247,    -1,    -1,   536,   285,   286,    -1,    -1,
     536,    -1,    -1,   258,   540,    -1,   295,    -1,   243,    -1,
     342,    -1,   247,    -1,   269,    -1,    -1,    -1,    -1,    -1,
     275,   276,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,
     275,   276,    -1,    -1,    -1,    -1,   378,    -1,    -1,   338,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,   360,    -1,   362,    -1,    -1,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   338,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      91,    -1,   357,   338,    -1,    -1,    -1,   362,    99,    -1,
      -1,   400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   357,    -1,    -1,   414,    -1,   362,   417,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,    -1,    -1,   432,    -1,   434,    -1,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,   414,
      -1,   450,    -1,   452,    -1,    -1,    -1,    -1,    -1,    -1,
     459,   503,   461,    -1,    -1,    -1,    -1,   466,    -1,   414,
      -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,   521,
      -1,    -1,   524,    -1,    -1,   450,    -1,    -1,    -1,    -1,
      -1,   533,   491,    -1,   459,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,    -1,    -1,
     509,    -1,    -1,    -1,   459,   514,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,   537,    12,
      13,    14,    15,    16,    17,    -1,   491,    -1,    21,    22,
      -1,    -1,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    -1,    -1,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,
      -1,    -1,    92,    -1,    94,    95,    -1,    -1,    -1,    -1,
     100,   101,    -1,   103,     0,     1,    -1,    -1,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    -1,    62,    63,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    85,
      -1,    91,    -1,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,     1,    -1,   100,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    15,    16,    17,    -1,
      -1,    -1,    21,    22,    -1,    -1,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,
      -1,    70,    71,    72,    73,     4,     5,     6,    -1,    -1,
       9,    10,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      89,    -1,    21,    92,    -1,    94,    25,    -1,    -1,    -1,
      29,   100,   101,    32,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    94,    -1,    -1,     4,     5,
       6,     7,     8,     9,    10,   104,    12,    13,    -1,    15,
      16,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    -1,   100,    -1,    -1,   103,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    15,
      16,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,
      -1,    -1,    -1,    -1,   100,   101,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,
      -1,    -1,   100,   101,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    -1,    -1,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
     100,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    15,    16,    17,    -1,    -1,    -1,    21,    22,
      -1,    -1,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,   100,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    15,
      16,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    71,    72,    73,    -1,     1,
      -1,    -1,     4,     5,    -1,    -1,    -1,     9,    10,    85,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    94,    21,
      -1,    -1,    -1,    25,   100,    -1,    -1,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,    -1,
      -1,     9,    10,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    -1,    85,    32,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    94,    -1,    42,    -1,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,    65,    66,     9,
      10,    -1,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    25,    -1,    85,    -1,    29,
      -1,    89,    32,    -1,    -1,    35,    94,    -1,    -1,    -1,
      -1,    41,    42,    -1,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,
      -1,    21,    -1,    -1,    94,    25,    -1,    -1,    -1,    29,
      -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    41,    42,    -1,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,    -1,     9,    10,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    -1,    85,    32,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    94,    -1,    42,    -1,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    64,    65,
      66,     9,    10,    -1,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    85,
      -1,    29,    -1,    89,    32,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    64,    65,    66,     9,
      10,    -1,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    25,    -1,    85,    -1,    29,
      -1,    89,    32,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    52,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    65,    66,    91,    -1,    -1,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    85,    13,    14,    15,    89,
      -1,    -1,    -1,    20,    94,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,     1,    53,    -1,     4,    -1,
       6,    58,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    91,    41,    42,    -1,    44,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,    -1,
      56,     4,    -1,     6,    -1,    61,     9,    10,    11,    65,
      66,    -1,    -1,    16,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    97,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    97,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    92,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   106,     0,     1,     4,     5,     6,     7,     8,     9,
      10,    12,    13,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    39,    40,    41,    42,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    54,    55,
      57,    58,    59,    60,    62,    63,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    85,    89,    92,    93,    94,
     100,   108,   109,   111,   112,   115,   116,   119,   120,   121,
     122,   123,   124,   126,   143,   149,   150,   153,   158,   159,
     163,   164,   165,   169,   176,   187,   108,   111,   112,   122,
     123,   143,   149,   163,   174,     9,   175,   160,    94,   154,
      94,   143,   160,   169,   160,    64,   160,   163,     4,     9,
      16,    29,    38,   181,   200,   181,   181,    94,   160,    92,
      92,   169,   189,   169,   160,   160,   160,   160,   160,   160,
      15,   107,   181,   160,   160,   160,    74,   172,   173,   160,
     144,   143,   145,   146,   111,   112,   143,   151,    53,   160,
     160,   160,    53,   143,   149,   160,     1,     4,     6,     9,
      10,    11,    16,    25,    29,    32,    38,    41,    42,    44,
      49,    52,    53,    56,    61,    65,    66,    70,    71,   201,
     201,     1,   110,    96,   160,   201,     9,   163,   163,    92,
       1,   163,   131,    92,   122,   126,   163,    74,    98,    92,
      99,    99,    92,     1,    74,    99,    92,    98,   126,    74,
      94,   154,    94,   157,   157,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    91,    92,
     160,    99,    74,    94,    92,    74,    94,    99,   170,   163,
     103,   126,   169,    98,    38,   141,   142,   127,    94,   201,
     177,   178,   180,   169,   166,   168,   200,    99,   102,    94,
     125,   201,   169,    92,   179,    94,    94,   163,    74,    96,
     147,   148,   201,   160,   171,    94,    99,   111,   171,   136,
     111,   122,   111,   122,    98,    94,   132,   171,   163,   117,
     118,   201,    95,     1,   162,   161,    64,   122,   163,   201,
     201,     9,   111,   122,   125,     9,   150,   163,   163,   155,
     163,   163,   126,   126,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,    94,   166,
       1,   163,    64,   104,   122,   163,   184,   185,   186,   163,
     122,   163,   171,    95,   103,    95,    99,    94,   126,   111,
      74,   184,    94,    94,    94,    94,    95,    96,   167,   169,
     188,   184,   129,    94,   184,   184,   163,   163,    99,   167,
     173,   163,   143,   163,   126,   139,   137,   140,   138,   163,
     111,    97,    99,   167,    92,   101,   126,   201,   113,    95,
     102,   103,   156,    95,   161,   161,   184,   201,    47,   111,
     149,   152,   169,    95,    99,    95,   133,   134,   184,   161,
     163,    95,   184,    95,    95,    95,   163,    96,     3,   102,
     190,   192,   193,    95,    74,    95,    95,    95,    97,   148,
      95,    94,   161,   126,   126,   126,   126,    95,    99,   118,
      94,   171,    74,   163,    95,   126,   126,    14,    95,    94,
       1,    94,   186,   126,   163,    95,    99,    95,   100,   182,
     182,   182,    97,   163,   194,   195,   191,     3,   163,   163,
     182,   167,   163,   161,   161,   161,   161,    99,   152,   167,
     184,    94,   114,   163,    95,    95,   161,   126,   184,   163,
     161,    95,   163,    28,   196,   197,    97,   163,   192,    99,
      95,   152,    95,   184,    74,   161,    95,    95,   135,   128,
     201,    43,   198,   199,    99,     3,   163,    95,   163,   126,
     126,   201,   183,    99,   201,   194,   130,   102,   161,   161,
     162,   201,   126,   163,   101,   161
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 147 "parse.y"
    { ntab = 0;}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 148 "parse.y"
    { return '\n';}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 149 "parse.y"
    { return '\n';}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 151 "parse.y"
    { hoc_ob_check(-1); code2(nopop, STOP); return 1; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 153 "parse.y"
    { codein(STOP); return 1; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 155 "parse.y"
    { TPDYNAM; code2(print, STOP); return 1; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 157 "parse.y"
    { debug(); return '\n';}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 159 "parse.y"
    { return 'e';}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 161 "parse.y"
    {code3(prstr, hoc_newline, STOP); return 1; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 164 "parse.y"
    { return '\n';}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 167 "parse.y"
    { plt(-3,0.,0.); return '\n';}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 168 "parse.y"
    {hoc_help();}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 168 "parse.y"
    { return '\n'; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 170 "parse.y"
    {clean_err(); hoc_execerror("parse error", (char*)0);
#if LINT
if (0) {
if(yydebug);
goto yynewstate;
}
#endif
		}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 180 "parse.y"
    {Symbol *s; TPD; s = spop();
		hoc_obvar_declare(s, VAR, 1);
		code3(varpush, s, assign); codei((yyvsp[(2) - (3)].narg)); PN;}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 184 "parse.y"
    {  TPD; defnonly("$"); argcode(argassign, (yyvsp[(1) - (3)].narg)); codei((yyvsp[(2) - (3)].narg)); (yyval.inst)=(yyvsp[(3) - (3)].inst); PN;}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 186 "parse.y"
    { TPD; defnonly("$&"); argrefcode(hoc_argrefasgn, (yyvsp[(1) - (4)].narg), (yyvsp[(2) - (4)].narg)); codei((yyvsp[(3) - (4)].narg)); (yyval.inst)=(yyvsp[(4) - (4)].inst); PN;}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 189 "parse.y"
    { TPD; code(range_const); codesym(spop()); codei((yyvsp[(2) - (3)].narg)); PN;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 193 "parse.y"
    { Inst* p; hoc_opasgn_invalid((yyvsp[(2) - (7)].narg));
		 code(hoc_newobj); codesym(hoc_which_template((yyvsp[(4) - (7)].sym))); codei((yyvsp[(6) - (7)].narg));
		 p = (Inst*)spop();
		 if (p) { p->i += 2; }
		}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 199 "parse.y"
    {Inst* p; TPDYNAM; code(hoc_object_asgn); codei((yyvsp[(2) - (3)].narg));
		 p = (Inst*)spop();
		 if (p) { p->i += 2; }
		}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 204 "parse.y"
    {myerr("assignment to variable, make sure right side is a number");}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 208 "parse.y"
    {pushi(OBJECTVAR);pushs((yyvsp[(1) - (1)].sym)); pushi(CHECK);}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 209 "parse.y"
    {(yyval.inst) = (yyvsp[(3) - (3)].inst); code(hoc_objectvar); spop(); codesym((yyvsp[(1) - (3)].sym));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 211 "parse.y"
    {defnonly("$o"); (yyval.inst) = argcode(hoc_objectarg, (yyvsp[(1) - (1)].narg)); pushi(OBJECTVAR);}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 213 "parse.y"
    {(yyval.inst) = code(hoc_autoobject); codesym((yyvsp[(1) - (1)].sym)); pushi(OBJECTVAR);}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 215 "parse.y"
    {TPD; (yyval.inst) = (yyvsp[(3) - (4)].inst); code(hoc_constobject); codesym((yyvsp[(1) - (4)].sym)); pushi(OBJECTVAR);}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 217 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); code(call); codesym((yyvsp[(1) - (5)].sym)); codei((yyvsp[(4) - (5)].narg));
		  code(hoc_known_type); codei(OBJECTVAR); pushi(OBJECTVAR);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 220 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); code(call); codesym((yyvsp[(1) - (5)].sym)); codei((yyvsp[(4) - (5)].narg));
		  code(hoc_known_type); codei(OBJECTVAR); pushi(OBJECTVAR);}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 224 "parse.y"
    { spop(); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 227 "parse.y"
    { pushs((Symbol*)0); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 228 "parse.y"
    {pushs((yyvsp[(3) - (3)].sym));pushi(NOCHECK);}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 229 "parse.y"
    {int isfunc; Inst* p;
		 isfunc = ipop();
		 code(hoc_object_component); codesym(spop()); codei(ipop());
		 codei((yyvsp[(6) - (6)].narg));
		 codei(0); codesym(0);
		 p = codei(isfunc); /* for USE_PYTHON */
		 spop();
		 pushs((Symbol*)p); /* in case assigning to a PythonObject we will want to update isfunc to 2 */
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 238 "parse.y"
    {myerr("object syntax is o1.o2.o3.");}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 241 "parse.y"
    {(yyval.narg) = 0; pushi(0);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 243 "parse.y"
    {(yyval.narg) = (yyvsp[(2) - (3)].narg); pushi(1);}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 245 "parse.y"
    {hoc_begintemplate((yyvsp[(2) - (2)].sym));}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 248 "parse.y"
    {hoc_endtemplate((yyvsp[(2) - (2)].sym));}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 249 "parse.y"
    {myerr("begintemplate Name\npublic namelist\nexternal namelist\n...\nendtemplate Name");}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 252 "parse.y"
    {(yyval.inst) = (yyvsp[(2) - (3)].inst);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 255 "parse.y"
    {code(hoc_objvardecl); codesym((yyvsp[(1) - (1)].sym)); codei(0);}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 257 "parse.y"
    {code(hoc_objvardecl); codesym((yyvsp[(1) - (2)].sym)); codei((yyvsp[(2) - (2)].narg));}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 259 "parse.y"
    {code(hoc_objvardecl); codesym((yyvsp[(3) - (3)].sym)); codei(0);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 261 "parse.y"
    {code(hoc_objvardecl); codesym((yyvsp[(3) - (4)].sym)); codei((yyvsp[(4) - (4)].narg));}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 264 "parse.y"
    {
		  Symbol* s;
		  s = hoc_decl((yyvsp[(1) - (1)].sym));
		  if (s->type != UNDEF && s->type != OBJECTVAR) {
			acterror(s->name, " already declared");
		  }
		  (yyval.sym) = s;
		}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 274 "parse.y"
    {hoc_add_publiclist((yyvsp[(2) - (2)].sym));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 276 "parse.y"
    {hoc_add_publiclist((yyvsp[(3) - (3)].sym));}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 279 "parse.y"
    {hoc_external_var((yyvsp[(2) - (2)].sym));}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 281 "parse.y"
    {hoc_external_var((yyvsp[(3) - (3)].sym));}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 286 "parse.y"
    {hoc_opasgn_invalid((yyvsp[(2) - (3)].narg)); code(assstr);}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 288 "parse.y"
    {Inst* p = (Inst*) spop(); pushi(STRING); TPDYNAM; code(hoc_object_asgn);
		 hoc_opasgn_invalid((yyvsp[(2) - (3)].narg)); codei((yyvsp[(2) - (3)].narg)); hoc_ob_check(-1); code(nopop);
		 if (p) { p->i += 2; }
		}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 293 "parse.y"
    {code(hoc_asgn_obj_to_str); hoc_opasgn_invalid((yyvsp[(2) - (3)].narg)); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 294 "parse.y"
    {myerr("string assignment: both sides need to be a string");}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 299 "parse.y"
    {(yyval.inst) = code(hoc_push_string); codesym((yyvsp[(1) - (1)].sym));}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 301 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); code(call); codesym((yyvsp[(1) - (5)].sym)); codei((yyvsp[(4) - (5)].narg));}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 305 "parse.y"
    {(yyval.inst) = code(hoc_push_string); codesym((yyvsp[(1) - (1)].sym));}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 307 "parse.y"
    {defnonly("$s"); (yyval.inst) = argcode(hoc_stringarg, (yyvsp[(1) - (1)].narg));}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 311 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (3)].inst); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 315 "parse.y"
    {
			Symbol* s = hoc_decl((yyvsp[(1) - (1)].sym));
			if (s->type == UNDEF) {
				hoc_obvar_declare(s, STRING, 0);
				OPSTR(s) = (char**)emalloc(sizeof(char*));
				*OPSTR(s) = 0;
			}else if (s->type != STRING) {
				acterror(s->name, " already declared");
			}
			hoc_assign_str(OPSTR(s), "");
		}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 328 "parse.y"
    { code(nopop); hoc_ob_check(-1); /*don't check*/}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 336 "parse.y"
    { code(nopop); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 338 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst);}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 340 "parse.y"
    { defnonly("return"); (yyval.inst)=(yyvsp[(2) - (2)].inst); code(procret); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 342 "parse.y"
    {  if (indef == 3) {
			TPDYNAM; (yyval.inst) = (yyvsp[(2) - (2)].inst);
			code(hocobjret);
		   }else{
			TPD; defnonly("return"); (yyval.inst)=(yyvsp[(2) - (2)].inst);
			code(funcret);
		   }
		}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 351 "parse.y"
    {(yyval.inst) = code(hoc_newobj_ret); codesym(hoc_which_template((yyvsp[(3) - (6)].sym))); codei((yyvsp[(5) - (6)].narg));
		 code(hocobjret);
		}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 355 "parse.y"
    { if (indef != 2) {
acterror("iterator_statement used outside an iterator declaration", 0);
		  }
			code(hoc_iterator_stmt);
		}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 361 "parse.y"
    { code(Break); (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 363 "parse.y"
    { code(Stop); (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 365 "parse.y"
    { code(Continue); (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 367 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); code(call); codesym((yyvsp[(1) - (5)].sym)); codei((yyvsp[(4) - (5)].narg)); code(nopop); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 369 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst); code(hoc_newline); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 371 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst);
		  ((yyvsp[(3) - (5)].inst))[0].i = relative((yyvsp[(4) - (5)].inst), (yyvsp[(3) - (5)].inst), 0); /* body */
		  ((yyvsp[(3) - (5)].inst))[1].i = relative((yyvsp[(5) - (5)].inst), (yyvsp[(3) - (5)].inst), 1); /* exit */
		}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 376 "parse.y"
    {
			((yyvsp[(2) - (6)].inst))[1].i =relative((yyvsp[(5) - (6)].inst), (yyvsp[(2) - (6)].inst), 1);	/* body */
			((yyvsp[(2) - (6)].inst))[2].i =relative((yyvsp[(6) - (6)].inst), (yyvsp[(2) - (6)].inst), 2); /* exit from the for */
			((yyvsp[(2) - (6)].inst))[3].i  =relative((yyvsp[(4) - (6)].inst), (yyvsp[(2) - (6)].inst), 3);	/* increment */
			(yyval.inst) = (yyvsp[(1) - (6)].inst);
#if LINT
if (0){YYERROR;}
#endif
			}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 386 "parse.y"
    { Symbol *s; (yyval.inst) = Code(varpush); codesym(s = spop());
			hoc_obvar_declare(s, VAR, 1);
		  }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 390 "parse.y"
    {TPD; TPD; hoc_opasgn_invalid((yyvsp[(4) - (7)].narg)); 
		    (yyval.inst) = code(shortfor); codei(0); codei(0);}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 393 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (10)].inst); ((yyvsp[(8) - (10)].inst))[1].i = relative((yyvsp[(9) - (10)].inst), (yyvsp[(8) - (10)].inst), 1); /* body */
			   ((yyvsp[(8) - (10)].inst))[2].i = relative((yyvsp[(10) - (10)].inst), (yyvsp[(8) - (10)].inst), 2); /* exit */
		  }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 397 "parse.y"
    { Symbol *s; (yyval.inst) = Code(varpush); codesym(s = spop());
			hoc_obvar_declare(s, VAR, 1);
		  }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 401 "parse.y"
    {TPD; TPD; hoc_opasgn_invalid((yyvsp[(5) - (8)].narg)); 
		     code(hoc_parallel_begin);
		     (yyval.inst) = code(shortfor); codei(0); codei(0);}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 405 "parse.y"
    { (yyval.inst) = (yyvsp[(3) - (11)].inst); ((yyvsp[(9) - (11)].inst))[1].i = relative((yyvsp[(10) - (11)].inst), (yyvsp[(9) - (11)].inst), 1); /* body */
			   ((yyvsp[(9) - (11)].inst))[2].i = relative((yyvsp[(11) - (11)].inst), (yyvsp[(9) - (11)].inst), 2); /* exit */
			code(hoc_parallel_end);
		  }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 410 "parse.y"
    {
		((yyvsp[(1) - (4)].inst))[1].i = relative((yyvsp[(3) - (4)].inst), (yyvsp[(1) - (4)].inst), 1);	/* body of loop */
		((yyvsp[(1) - (4)].inst))[2].i = relative((yyvsp[(4) - (4)].inst), (yyvsp[(1) - (4)].inst), 2); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 414 "parse.y"
    {
		((yyvsp[(1) - (4)].inst))[1].i = relative((yyvsp[(3) - (4)].inst), (yyvsp[(1) - (4)].inst), 1);	/* thenpart */
		((yyvsp[(1) - (4)].inst))[3].i = relative((yyvsp[(4) - (4)].inst), (yyvsp[(1) - (4)].inst), 3); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 418 "parse.y"
    {
		((yyvsp[(1) - (7)].inst))[1].i = relative((yyvsp[(3) - (7)].inst), (yyvsp[(1) - (7)].inst), 1);	/* thenpart */
		((yyvsp[(1) - (7)].inst))[2].i = relative((yyvsp[(6) - (7)].inst), (yyvsp[(1) - (7)].inst), 2);	/* elsepart */
		((yyvsp[(1) - (7)].inst))[3].i = relative((yyvsp[(7) - (7)].inst), (yyvsp[(1) - (7)].inst), 3); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 423 "parse.y"
    { ntab++;}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 425 "parse.y"
    {
		ntab--; (yyval.inst) = (yyvsp[(3) - (4)].inst);
		}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 431 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (3)].inst); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 433 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(2) - (4)].inst); code(connectsection);}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 435 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(2) - (7)].inst); code(simpleconnectsection);}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 437 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(2) - (7)].inst); code(connectpointer); codesym(spop());}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 438 "parse.y"
    {code(nrn_cppp);}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 439 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (6)].inst); code(connect_point_process_pointer);
			 hoc_ob_check(-1);}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 442 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst); code(sec_access);}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 444 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst); hoc_ob_check(SECTION); code(sec_access_object);}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 446 "parse.y"
    { (yyval.inst) = Code(mech_access); codesym((yyvsp[(2) - (2)].sym));}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 448 "parse.y"
    { (yyval.inst) = Code(mech_uninsert); codesym((yyvsp[(2) - (2)].sym));}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 450 "parse.y"
    { code(sec_access_pop);}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 452 "parse.y"
    { code(sec_access_pop); hoc_ob_check(-1);
			insertcode((yyvsp[(2) - (3)].inst), (yyvsp[(3) - (3)].inst), ob_sec_access);}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 455 "parse.y"
    { TPD; TPD; TPD; TPD; code(range_interpolate); codesym(spop());
		  codei((yyvsp[(7) - (10)].narg));
		}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 459 "parse.y"
    { TPD; TPD; code(range_interpolate_single); codesym(spop());
		  codei((yyvsp[(5) - (6)].narg));
		}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 463 "parse.y"
    {Symbol *s; code(varpush); codesym(s = spop());
		 hoc_obvar_declare(s, VAR, 1);
		 (yyval.inst) = code(for_segment); codei(0); codei(0);}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 467 "parse.y"
    { (yyval.inst) = (yyvsp[(3) - (7)].inst); ((yyvsp[(5) - (7)].inst))[1].i = relative((yyvsp[(6) - (7)].inst), (yyvsp[(5) - (7)].inst), 1); /* body */
			((yyvsp[(5) - (7)].inst))[2].i = relative((yyvsp[(7) - (7)].inst), (yyvsp[(5) - (7)].inst), 2); /* exit */
		}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 471 "parse.y"
    {Symbol *s; code(varpush); codesym(s = spop());
		hoc_obvar_declare(s, VAR, 1);}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 474 "parse.y"
    { TPD; (yyval.inst) = code(for_segment1); codei(0); codei(0);}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 476 "parse.y"
    { (yyval.inst) = (yyvsp[(3) - (10)].inst); ((yyvsp[(8) - (10)].inst))[1].i = relative((yyvsp[(9) - (10)].inst), (yyvsp[(8) - (10)].inst), 1); /* body */
			((yyvsp[(8) - (10)].inst))[2].i = relative((yyvsp[(10) - (10)].inst), (yyvsp[(8) - (10)].inst), 2); /* exit */
		}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 480 "parse.y"
    {	code(hoc_push_string); codesym((Symbol*)0);
			(yyval.inst) = code(forall_section); codei(0); codei(0);}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 483 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); ((yyvsp[(3) - (5)].inst))[1].i = relative((yyvsp[(4) - (5)].inst), (yyvsp[(3) - (5)].inst), 1); /* body */
			((yyvsp[(3) - (5)].inst))[2].i = relative((yyvsp[(5) - (5)].inst), (yyvsp[(3) - (5)].inst), 2); /* exit */
		}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 487 "parse.y"
    { (yyval.inst) = code(forall_section); codei(0); codei(0);}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 489 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (6)].inst); ((yyvsp[(4) - (6)].inst))[1].i = relative((yyvsp[(5) - (6)].inst), (yyvsp[(4) - (6)].inst), 1); /* body */
			((yyvsp[(4) - (6)].inst))[2].i = relative((yyvsp[(6) - (6)].inst), (yyvsp[(4) - (6)].inst), 2); /* exit */
		}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 493 "parse.y"
    { (yyval.inst) = code(hoc_ifsec); codei(0); codei(0);}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 495 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (6)].inst); ((yyvsp[(4) - (6)].inst))[1].i = relative((yyvsp[(5) - (6)].inst), (yyvsp[(4) - (6)].inst), 1); /* body */
			((yyvsp[(4) - (6)].inst))[2].i = relative((yyvsp[(6) - (6)].inst), (yyvsp[(4) - (6)].inst), 2); /* exit */
		}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 499 "parse.y"
    {hoc_ob_check(-1);
		(yyval.inst) = code(forall_sectionlist); codei(0); codei(0); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 502 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (6)].inst); ((yyvsp[(4) - (6)].inst))[1].i = relative((yyvsp[(5) - (6)].inst), (yyvsp[(4) - (6)].inst), 1); /* body */
			((yyvsp[(4) - (6)].inst))[2].i = relative((yyvsp[(6) - (6)].inst), (yyvsp[(4) - (6)].inst), 2); /* exit */
		}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 506 "parse.y"
    { hoc_ob_check(-1);
		 (yyval.inst) = code(hoc_ifseclist); codei(0); codei(0);
		}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 511 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (6)].inst); ((yyvsp[(4) - (6)].inst))[1].i = relative((yyvsp[(5) - (6)].inst), (yyvsp[(4) - (6)].inst), 1); /* body */
			((yyvsp[(4) - (6)].inst))[2].i = relative((yyvsp[(6) - (6)].inst), (yyvsp[(4) - (6)].inst), 2); /* exit */
		}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 518 "parse.y"
    {
		  code(hoc_iterator); codesym((yyvsp[(1) - (4)].sym)); codei((yyvsp[(3) - (4)].narg));
		  (yyval.inst) = progp; codein(STOP); codein(STOP);
		}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 522 "parse.y"
    {code(hoc_push_current_object);}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 523 "parse.y"
    {codei(ITERATOR);
		  (yyval.inst) = progp; codein(STOP); codein(STOP);
		}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 528 "parse.y"
    {pushs((yyvsp[(1) - (1)].sym)); pushi(CHECK);}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 529 "parse.y"
    {code(sec_access_push); codesym(spop()); (yyval.inst) = (yyvsp[(3) - (3)].inst);}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 532 "parse.y"
    {TPD;}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 533 "parse.y"
    {(yyval.inst) = progp; code(connect_obsec_syntax);}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 534 "parse.y"
    {
#if 0
		 acterror("Sorry. The \"connect ob.sec...\" syntax ",
			"is not implemented");
#endif
		 hoc_ob_check(SECTION); code(ob_sec_access);
		}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 544 "parse.y"
    { code(add_section); codesym((yyvsp[(1) - (1)].sym)); codei(0);}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 546 "parse.y"
    { code(add_section); codesym((yyvsp[(1) - (2)].sym)); codei((yyvsp[(2) - (2)].narg));}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 548 "parse.y"
    {code(add_section); codesym((yyvsp[(3) - (3)].sym)); codei(0);}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 550 "parse.y"
    { code(add_section); codesym((yyvsp[(3) - (4)].sym)); codei((yyvsp[(4) - (4)].narg));}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 553 "parse.y"
    {
			Symbol* s;
			s = hoc_decl((yyvsp[(1) - (1)].sym));
			if (s->type != UNDEF && s->type != SECTION)
				acterror(s->name, " already declared");
		}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 561 "parse.y"
    { code(sec_access_push); codesym((Symbol *)0);}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 564 "parse.y"
    {pushs((yyvsp[(1) - (1)].sym)); pushi(CHECK);}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 565 "parse.y"
    {(yyval.inst) = (yyvsp[(3) - (3)].inst);}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 568 "parse.y"
    { code3(varpush, spop(), hoc_evalpointer);}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 570 "parse.y"
    { TPD; code(rangevarevalpointer); codesym(spop());}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 572 "parse.y"
    {hoc_ipop(); code(hoc_ob_pointer);}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 573 "parse.y"
    {myerr("rangevariable needs explicit arc position,eg. v(.5)");}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 575 "parse.y"
    {(yyval.inst) = argcode(hoc_argrefarg, (yyvsp[(1) - (1)].narg));}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 581 "parse.y"
    { (yyval.inst) = (yyvsp[(3) - (4)].inst);}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 583 "parse.y"
    { (yyval.inst) = progp; }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 586 "parse.y"
    { (yyval.inst) = code(forcode); codei(0); codei(0); codei(0); }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 589 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(1) - (1)].inst); codein(STOP);}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 592 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (3)].inst); code(STOP);}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 594 "parse.y"
    { (yyval.inst) = progp; code(STOP);}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 597 "parse.y"
    { TPD; codein(STOP); (yyval.inst) = (yyvsp[(2) - (3)].inst);}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 600 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 603 "parse.y"
    { (yyval.inst)=code(ifcode); codei(0); codei(0); codei(0); }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 606 "parse.y"
    { (yyval.inst) = progp; }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 609 "parse.y"
    { codein(STOP); (yyval.inst) = progp; }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 612 "parse.y"
    { (yyval.inst) = progp; prog_error = (yyval.inst); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 614 "parse.y"
    {
			prog_parse_recover = progp;
			prog_error = (yyval.inst);
			if (fin == stdin && !pipeflag)
			{	int i;
				Printf(">");
				for (i = 0; i < ntab; i++)
					Printf("	");
			}
		}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 626 "parse.y"
    {myerr("syntax error in compound statement");}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 631 "parse.y"
    { (yyval.inst) = code(constpush); codesym((yyvsp[(1) - (1)].sym)); PN;}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 633 "parse.y"
    { (yyval.inst) = code(pushzero); PN;}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 635 "parse.y"
    { code3(varpush, spop(), eval); PN;}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 637 "parse.y"
    { defnonly("$"); (yyval.inst) = argcode(arg, (yyvsp[(1) - (1)].narg)); PN;}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 639 "parse.y"
    { defnonly("$&"); (yyval.inst) = argrefcode(hoc_argref, (yyvsp[(1) - (2)].narg), (yyvsp[(2) - (2)].narg)); PN;}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 642 "parse.y"
    {code(rangepoint); codesym(spop()); PN;}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 644 "parse.y"
    { TPD; code(rangevareval); codesym(spop()); PN;}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 648 "parse.y"
    {code(hoc_object_eval);}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 652 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); code(call); codesym((yyvsp[(1) - (5)].sym)); codei((yyvsp[(4) - (5)].narg)); PN;}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 654 "parse.y"
    { code(call); codesym(spop()); codei((yyvsp[(3) - (4)].narg)); PN;}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 656 "parse.y"
    { (yyval.inst)=(yyvsp[(3) - (4)].inst); code(varread); codesym(spop()); PN;}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 658 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(3) - (4)].inst); code(bltin); codesym((yyvsp[(1) - (4)].sym)); PN;}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 660 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (3)].inst); }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 662 "parse.y"
    {myerr("syntax error in expression");}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 664 "parse.y"
    { TPD; TPD; code(add); PN; }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 666 "parse.y"
    { TPD; TPD;code(sub); PN;}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 668 "parse.y"
    { TPD; TPD; code(mul); PN;}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 670 "parse.y"
    { TPD; TPD; code(hoc_div); PN;}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 672 "parse.y"
    { TPD; TPD; code(hoc_cyclic); PN;}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 674 "parse.y"
    { TPD; TPD; code(power); PN;}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 676 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(2) - (2)].inst); code(negate); PN;}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 678 "parse.y"
    { TPD; TPD; code(gt); PN;}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 680 "parse.y"
    { TPD; TPD; code(ge); PN;}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 682 "parse.y"
    { TPD; TPD; code(lt); PN;}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 684 "parse.y"
    { TPD; TPD; code(le); PN;}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 686 "parse.y"
    { hoc_ob_check(-1); hoc_ob_check(-1); code(eq); PN;}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 688 "parse.y"
    { hoc_ob_check(-1); hoc_ob_check(-1); code(ne); PN;}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 690 "parse.y"
    { TPD; TPD; code(hoc_and); PN;}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 692 "parse.y"
    { TPD; TPD; code(hoc_or); PN;}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 694 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(2) - (2)].inst); code(hoc_not); PN;}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 702 "parse.y"
    {Symbol *s; code(varpush); codesym(s=spop()); (yyval.inst) = (yyvsp[(2) - (3)].inst);
		code(arayinstal); codei((yyvsp[(3) - (3)].narg)); hoc_obvar_declare(s, VAR, 0);}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 705 "parse.y"
    {Symbol *s; code(varpush); codesym(s = spop());
		code(arayinstal); codei((yyvsp[(3) - (3)].narg)); hoc_obvar_declare(s, VAR, 0);}
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 710 "parse.y"
    {pushs((yyvsp[(1) - (2)].sym)); (yyval.narg) = (yyvsp[(2) - (2)].narg);}
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 713 "parse.y"
    {  TPD; (yyval.narg) = 1; }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 715 "parse.y"
    {  TPD;(yyval.narg) = (yyval.narg) + 1; }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 721 "parse.y"
    { pushs((yyvsp[(1) - (2)].sym)); (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 723 "parse.y"
    { if ((yyvsp[(1) - (2)].sym)->subtype == USERPROPERTY) {
			code(sec_access_push); codesym((Symbol *)0);
		  }
		pushs((yyvsp[(1) - (2)].sym)); pushi(CHECK);
		}
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 728 "parse.y"
    {(yyval.inst) = (yyvsp[(2) - (4)].inst);}
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 730 "parse.y"
    { if ((yyvsp[(3) - (3)].sym)->subtype != USERPROPERTY) {
			acterror((yyvsp[(3) - (3)].sym)->name, "not a section variable");
		  }
		(yyval.inst) = (yyvsp[(1) - (3)].inst); pushs((yyvsp[(3) - (3)].sym));
		}
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 744 "parse.y"
    {
		int d1, chk;
		Symbol *sym;
		d1 = ipop();
		chk = ipop();
		sym = spop();
   if (chk) {
	if (!ISARRAY(sym)) {
		if (d1)
			acterror(sym->name, "not an array variable");
	}else{
		if ( d1 == 0 ) { /*fake index list with all 0's*/
			int i;
			for (i=0; i<sym->arayinfo->nsub; i++) {
				code(pushzero);
			}
		}			
		else if ( d1 != sym->arayinfo->nsub) {
			acterror("wrong # of subscripts",sym->name);
		}
	}
   }else {
	pushi(d1); /* must check dynamically */
   }
		pushs(sym);
		}
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 773 "parse.y"
    {
			(yyval.narg) = ipop();
		}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 779 "parse.y"
    { pushi(0); }
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 781 "parse.y"
    {  TPD;pushi(ipop() + 1); }
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 785 "parse.y"
    { TPDYNAM; code(prexpr);}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 787 "parse.y"
    { code(prstr); }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 789 "parse.y"
    { TPDYNAM; code(prexpr);}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 791 "parse.y"
    { code(prstr); }
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 794 "parse.y"
    { (yyval.inst) = code(hoc_delete_symbol); codesym((yyvsp[(1) - (1)].sym)); }
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 798 "parse.y"
    {(yyvsp[(2) - (2)].sym)->type=FUNCTION; indef=1; }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 800 "parse.y"
    { code(procret); hoc_define((yyvsp[(2) - (6)].sym));
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nobjauto = (yyvsp[(6) - (6)].narg) - localcnt;
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nauto=(yyvsp[(6) - (6)].narg); indef=0; }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 804 "parse.y"
    { (yyvsp[(2) - (2)].sym)->type=PROCEDURE; indef=1; }
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 806 "parse.y"
    { code(procret); hoc_define((yyvsp[(2) - (6)].sym));
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nobjauto = (yyvsp[(6) - (6)].narg) - localcnt;
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nauto=(yyvsp[(6) - (6)].narg); indef=0; }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 810 "parse.y"
    { (yyvsp[(2) - (2)].sym)->type = ITERATOR; indef=2; }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 812 "parse.y"
    {code(procret); hoc_define((yyvsp[(2) - (6)].sym));
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nobjauto = (yyvsp[(6) - (6)].narg) - localcnt;
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nauto = (yyvsp[(6) - (6)].narg); indef = 0; }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 816 "parse.y"
    { (yyvsp[(2) - (2)].sym)->type=HOCOBJFUNCTION; indef=3; }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 818 "parse.y"
    { code(procret); hoc_define((yyvsp[(2) - (6)].sym));
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nobjauto = (yyvsp[(6) - (6)].narg) - localcnt;
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nauto=(yyvsp[(6) - (6)].narg); indef=0; }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 823 "parse.y"
    { Symbol *s; s=yylval.sym;
		if(s->type != UNDEF) acterror(s->name, "already defined");
		s->u.u_proc = (Proc *)emalloc(sizeof(Proc));
		s->u.u_proc->defn.in = STOP;
		s->u.u_proc->list = (Symlist *)0; }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 833 "parse.y"
    {ntab++;}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 834 "parse.y"
    {
		ntab--;
		(yyval.narg) = (yyvsp[(2) - (6)].narg) + (yyvsp[(3) - (6)].narg);
		}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 840 "parse.y"
    { (yyval.narg) = 0; }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 844 "parse.y"
    {(yyval.narg) = 1;}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 846 "parse.y"
    {(yyval.narg) = (yyvsp[(1) - (3)].narg) + 1;}
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 849 "parse.y"
    {}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 851 "parse.y"
    { hoc_ob_check(-1);}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 854 "parse.y"
    {
		 code(hoc_newobj_arg); codesym(hoc_which_template((yyvsp[(2) - (5)].sym))); codei((yyvsp[(4) - (5)].narg));
		}
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 859 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 861 "parse.y"
    {code3(varpush, spop(), eqn_name);
		do_equation = 1; }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 864 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); do_equation = 0; }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 867 "parse.y"
    {Symbol *s; code3(varpush,s= spop(), dep_make); hoc_obvar_declare(s, VAR, 0);}
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 869 "parse.y"
    {Symbol *s; code3(varpush, s=spop(), dep_make); hoc_obvar_declare(s, VAR, 0);}
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 874 "parse.y"
    { code(eqn_init); }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 878 "parse.y"
    { code(eqn_lhs); }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 880 "parse.y"
    { codein(STOP); TPD; }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 883 "parse.y"
    { code(eqn_rhs); }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 885 "parse.y"
    { codein(STOP); TPD; }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 888 "parse.y"
    { (yyval.narg) = 0; localcnt = (yyval.narg);}
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 892 "parse.y"
    {
		Symbol *sp;
		(yyval.narg) = 1; localcnt = (yyval.narg);
		sp = install((yyvsp[(2) - (2)].sym)->name, AUTO, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg);
		}
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 899 "parse.y"
    {
		Symbol *sp;
		(yyval.narg) = (yyvsp[(1) - (3)].narg) + 1; localcnt = (yyval.narg);
		if (hoc_table_lookup((yyvsp[(3) - (3)].sym)->name, p_symlist)) {
			acterror((yyvsp[(3) - (3)].sym)->name, "already declared local");
		}
		sp = install((yyvsp[(3) - (3)].sym)->name, AUTO, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg);
		}
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 910 "parse.y"
    { (yyval.narg) = 0;}
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 914 "parse.y"
    {
		Symbol *sp;
		(yyval.narg) = 1;
		if (hoc_table_lookup((yyvsp[(2) - (2)].sym)->name, p_symlist)) {
			acterror((yyvsp[(2) - (2)].sym)->name, "already declared local");
		}
		sp = install((yyvsp[(2) - (2)].sym)->name, AUTOOBJ, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg) + localcnt;
		}
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 924 "parse.y"
    {
		Symbol *sp;
		(yyval.narg) = (yyvsp[(1) - (3)].narg) + 1;
		if (hoc_table_lookup((yyvsp[(3) - (3)].sym)->name, p_symlist)) {
			acterror((yyvsp[(3) - (3)].sym)->name, "already declared local");
		}
		sp = install((yyvsp[(3) - (3)].sym)->name, AUTOOBJ, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg) + localcnt;
		}
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 935 "parse.y"
    {  Symbol* s;
	   s = hoc_decl((yyvsp[(1) - (1)].sym));
	   if (s->subtype != NOTUSER)
		acterror("can't redeclare user variable", s->name);
	   (yyval.sym) = s;
	}
    break;



/* Line 1806 of yacc.c  */
#line 4426 "parse.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 947 "parse.y"

	/* end of grammar */

yyerror(s)	/* called for yacc syntax error */
	char *s;
{
	execerror(s, (char *)0);
}

acterror(s, t)	/* recover from action error while parsing */
	char *s, *t;
{
	execerror(s,t);
}

static Inst* argrefcode(pfri, i, j) Pfri pfri; int i, j; {
	Inst* in;
	in = argcode(pfri, i);
	codei(j);
	return in;
}

static Inst* argcode(pfri, i)
	Pfri pfri;
	int i;
{
	Inst* in;
	if (i == 0) {
		Symbol* si = hoc_lookup("i");
		if (si->type != AUTO) {
			acterror("arg index used and i is not a LOCAL variable", 0);
		}
		in = code3(varpush, si, eval);		
		Code(pfri);
		codei(0);
	}else{
		in = Code(pfri);
		codei(i);
	}
	return in;
}

hoc_opasgn_invalid(op) int op; {
        if (op) {
                acterror("Invalid assignment operator.", "Only '=' allowed. ");
        }
} 


