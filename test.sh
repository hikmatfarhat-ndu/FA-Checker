#!/bin/bash
echo "Problem $1"
echo "----------"
./FA-Checker ../$1.txt ../$1-tests.txt |tee -a grade
score=$(cut -d ' ' -f 5 grade|paste -sd +|bc)
total=$(cut -d ' ' -f 7 grade|paste -sd +|bc)
/bin/echo -e "\x1B[36mscore\033[0m $score / $total" |tee -a grade
/bin/echo -e "\x1B[36mscore"
#echo $GITHUB_REPOSITORY|tee -a grade
