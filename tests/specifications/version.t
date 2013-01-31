#!/usr/bin/perl -w
#

use strict;


my $test
    = {
       command_definitions => [
			       {
				arguments => [
					      'no version yet',
					     ],
				command => '/bin/echo',
				command_tests => [
						  {
description => "Do we see correct version information",
read => "no version yet",
						   wait => 1,
						  },
						 ],
				description => "check version information",
			       },
			      ],
       description => "run-time versioning",
       name => 'version.t',
      };


return $test;


