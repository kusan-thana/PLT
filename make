#!/bin/bash

if [ "$1" == "-h" ] || [ "$1" == "--help" ] ; then
	echo "make  : build both client and server"
    exit 2	
fi

cd build
make -j5
