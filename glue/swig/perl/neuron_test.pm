#!/usr/bin/perl -w
#!/usr/bin/perl -w -d:ptkdb
#


use strict;


$| = 1;


BEGIN
{
    if ($ENV{srcdir})
    {
	print "Found ENV{srcdir} ($ENV{srcdir}), using it for finding perl modules\n";

	push @INC, "$ENV{srcdir}";

    }

    push @INC, '.';

    push @INC, '/usr/local/glue/swig/perl';
}


$SIG{__DIE__}
    = sub {
	use Carp;

	confess @_;
    };


use Data::Dumper;

use Neuron;


print "Neuron loaded\n";

Neuron::include_script("hoc_test.hoc");

print "Perl script finished\n";


