#!/bin/bash
rm -rf tests
mkdir tests
cd tests
cmake .. -DBoost_INCLUDE_DIR=$BOOST_ROOT_1_72_0/include
make FA-Checker
echo "Problem 1a"
echo "----------"
./FA-Checker ../1a.txt ../1a-tests.txt |tee -a grade
echo "Problem 1b"
echo "----------"
./FA-Checker ../1b.txt ../1b-tests.txt|tee -a grade
echo "Problem 1c"
echo "----------"
./FA-Checker ../1c.txt ../1c-tests.txt |tee -a grade
echo "Problem 1d"
echo "----------"
./FA-Checker ../1d.txt ../1d-tests.txt |tee -a grade
echo "Problem 1e"
echo "----------"
./FA-Checker ../1e.txt ../1e-tests.txt|tee -a grade
echo "Problem 2"
echo "----------"
./FA-Checker ../2.txt ../2-tests.txt|tee -a grade
cut -d ' ' -f 5 grade|paste -sd +|bc
cut -d ' ' -f 7 grade
