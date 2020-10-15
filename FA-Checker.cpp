// FA-Checker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <boost/container_hash/hash.hpp>
#include "FA.h"
extern std::optional<FA> readFA(std::string);
int main(int argc,char **argv)
{
    if (argc < 2) {
        std::cout << "Usage FA-checker NFA description\n";
        exit(1);
    }
    if (auto n = readFA(argv[1])) {
        FA nfa = *n;
        bool r = nfa.accept("101101010111");
        std::cout << std::boolalpha << r << std::endl;
    }
    else {
        std::cout << "could not read input\n";
        exit(1);
    }
}
