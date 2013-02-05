#!/usr/bin/perl -w
#!/usr/bin/perl -w -d:ptkdb
#

package Neuron::Integrators::Commands;


use strict;


use Neuron;


our $g3_commands
    = [
       'neuron_load',
       'neuron_load_help',
      ];


sub neuron_load
{
    my $filename = shift;

    if (!-e $filename)
    {
	$filename = "/usr/local/neuron-parser/tests/scripts/$filename";
    }

    Neuron::include_model($filename, $GENESIS3::model_container);

    return "*** Ok: neuron_load $filename";
}


sub neuron_load_help
{
    print "description: load and extract models from a Neuron .hoc file.\n";

    print "synopsis: neuron_load <filename.g>\n";

    return "*** Ok";
}


1;


