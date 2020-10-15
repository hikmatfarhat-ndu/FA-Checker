#!/bin/bash
rm -rf tests
mkdir tests
cd tests
cmake ..
make FA-Checker
cmake .. -DBoost_INCLUDE_DIR=$BOOST_ROOT_1_72_0/include
./FA-Checker ../data.txt
