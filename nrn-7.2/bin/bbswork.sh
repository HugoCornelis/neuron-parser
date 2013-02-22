#!/bin/sh

prefix=/usr/local
exec_prefix=/usr/local/x86_64
NRNBIN=${exec_prefix}/bin
ARCH=x86_64
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

