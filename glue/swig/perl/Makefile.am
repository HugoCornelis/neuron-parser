SUBDIRS = 


#t the following rules are crap complete, would be good if a auto
#t expert takes a look at it.

dist-hook:
	cp $(srcdir)/neuron.i $(distdir)
	cp $(srcdir)/neuron_test.pm $(distdir)

swigdir = $(prefix)/glue/swig

#t use $(swigdir) here

perldir = @PMDIR@

swig_DATA = neuron.i

nobase_perl_HEADERS = Neuron.pm Neuron/Integrators/Commands.pm

perl_DATA = neuron_test.pm SwiggableNeuron.pm SwiggableNeuron.$(PERLLIB_EXTENSION)

BUILT_SOURCES = \
	SwiggableNeuron.pm \
	swiggable_neuron_wrap.c

SwiggableNeuron.pm swiggable_neuron_wrap.c: $(swig_DATA)
	$(SWIG) -I/usr/local/neurospaces/instrumentor -I$(srcdir)/../../.. -I$(top_builddir) -perl5 -makedefault -module SwiggableNeuron -o swiggable_neuron_wrap.c $(srcdir)/neuron.i

swiggable_neuron_wrap.o: swiggable_neuron_wrap.c
	$(SWIGCOMPILECOMMAND_PERL)


SwiggableNeuron.$(PERLLIB_EXTENSION): swiggable_neuron_wrap.o
	$(SWIGLINKCOMMAND_PERL)





all: SwiggableNeuron.$(PERLLIB_EXTENSION)

CLEANFILES = \
	SwiggableNeuron.pm \
	swiggable_neuron_wrap.c \
	swiggable_neuron_wrap.o \
	SwiggableNeuron.$(PERLLIB_EXTENSION)

#TESTS = neuron_test.pm

test: check

