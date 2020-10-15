#!/bin/bash
rm -rf tests
mkdir tests
cd tests
cmake .. -DBoost_INCLUDE_DIR=$BOOST_ROOT_1_72_0/include
make FA-Checker
x=$(./FA-Checker ../1a.txt ../1a-tests.txt)
echo "Problem 1a"
echo "----------"
echo $x
x=$(./FA-Checker ../1b.txt ../1b-tests.txt)
echo "Problem 1b"
echo "----------"
echo $x
x=$(./FA-Checker ../1c.txt ../1c-tests.txt)
echo "Problem 1c"
echo "----------"
echo $x
x=$(./FA-Checker ../1d.txt ../1d-tests.txt)
echo "Problem 1d"
echo "----------"
echo $x
x=$(./FA-Checker ../1e.txt ../1e-tests.txt)
echo "Problem 1e"
echo "----------"
echo $x
x=$(./FA-Checker ../2.txt ../2-tests.txt)
echo "Problem 2"
echo "----------"
echo $x
