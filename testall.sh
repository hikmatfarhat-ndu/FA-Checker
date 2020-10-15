#!/bin/bash
rm -rf tests
mkdir tests
cd tests
cmake .. -DBoost_INCLUDE_DIR=$BOOST_ROOT_1_72_0/include
make FA-Checker
./FA-Checker ../1a.txt ../1a-tests.txt
./FA-Checker ../1b.txt ../1b-tests.txt
./FA-Checker ../1c.txt ../1c-tests.txt
./FA-Checker ../1d.txt ../1d-tests.txt
./FA-Checker ../1e.txt ../1e-tests.txt
