// FA-Checker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <boost/container_hash/hash.hpp>
#include "FA.h"
extern std::optional<FA> readFA(std::string);
int main()
{
    if (auto n = readFA("data.txt")) {
        FA nfa = *n;
        bool r = nfa.accept("101101010101");
        std::cout << std::boolalpha << r << std::endl;
    }
    else {
        std::cout << "could not read input\n";
        exit(1);
    }
}
