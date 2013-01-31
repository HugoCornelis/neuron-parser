#!/bin/sh

prefix=/usr/local
exec_prefix=/usr/local/i686
NRNBIN=${exec_prefix}/bin
ARCH=i686
NEURONHOME=/usr/local/share/nrn

cd $1

if [ -x ${ARCH}/special ] ; then
	program="./${ARCH}/special"
else
	program="${NRNBIN}/nrniv"
fi

hostname
pwd
shift
shift
echo "time $program $*"
time $program $*

