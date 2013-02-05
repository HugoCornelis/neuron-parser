#!/usr/bin/perl -w
#!/usr/bin/perl -w -d:ptkdb
#

package Neuron;


use strict;


use SwiggableNeuron;


our $backend_initialized;


sub neuron_list_objects
{
    if (!$backend_initialized)
    {
	run_model(undef, $GENESIS3::model_container);
    }

    my $result = SwiggableNeuron::ListObjects();

    if (!$result)
    {
	print "$0: neuron_list_objects() failed\n";
    }
}

sub neuron_list_commands
{
    if (!$backend_initialized)
    {
	run_model(undef, $GENESIS3::model_container);
    }

    my $result = SwiggableNeuron::ListCommands();

    if (!$result)
    {
	print "$0: neuron_list_commands() failed\n";
    }
}

sub neuron_print_command_list
{
    if (!$backend_initialized)
    {
	run_model(undef, $GENESIS3::model_container);
    }

    my $result = SwiggableNeuron::PrintCommandList();

    if (!$result)
    {
	print "$0: neuron_print_command_list() failed\n";
    }
}

sub include_script
{
    my $script = shift;

    # include the script, result is 1 for success, 0 for failure.

    my $result = SwiggableNeuron::IncludeHocScript("$script");

    if (!$result)
    {
	print "$0: include_script() failed\n";
    }
}


sub include_model
{
    my $script = shift;

    my $model_container = shift;

    # set the directory where to find .p files

    $script =~ m(^(.*)/);

    my $morphology_directory = $1;

    $morphology_directory = $ENV{HOME} . "/neurospaces_project/ns-neuron/source/snapshots/0";

    # read the model, result is always 0 for some obscure reason.

    my $result
	= SwiggableNeuron::IncludeHocModel
	    (
	     "$morphology_directory",
	     "$script",
	     $model_container->backend(),
	     $ENV{HOME} . "/neurospaces_project/neuron-parser/source/snapshots/0/.simrc-ns-neuron",
	    );

    if (!$result)
    {
	print "$0: include_model() failed\n";
    }
    else
    {
	$backend_initialized = 'initialized from include_model()';
    }
}


sub interpreter
{
    SwiggableNeuron::RunInterpreter(1);
}


sub run_model
{
    my $script = shift;

    my $model_container = shift;

    # set the directory where to find .p files

    my $morphology_directory;

    if (defined $script)
    {
	$script =~ m(^(.*)/);

	$morphology_directory = $1;

	$morphology_directory = $ENV{HOME} . "/neurospaces_project/neuron-parser/source/snapshots/0";

    }

    # read the model, result is always 0 for some obscure reason.

    my $result
	= SwiggableNeuron::RunHocModel
	    (
	     (defined $morphology_directory ? "$morphology_directory" : undef),
	     (defined $script ? "$script" : undef),
	     $model_container->backend(),
	     $ENV{HOME} . "/neurospaces_project/neuron-parser/source/snapshots/0/.simrc-ns-neuron",
	    );

    if (!$result)
    {
	print "$0: run_model() failed\n";
    }
    else
    {
	$backend_initialized = 'initialized from run_model()';
    }
}


1;


