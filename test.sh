#!/bin/bash
if  ! [ $# -eq 2 ]
then
	echo "error"
	exit 1
fi
if [ "$2" = "init" ]
then
	rm -rf tests
	mkdir tests
	cd tests
	cmake .. -DBoost_INCLUDE_DIR=$BOOST_ROOT_1_72_0/include
	make FA-Checker
else
	cd tests
fi

./FA-Checker ../$1.txt ../$1-tests.txt
