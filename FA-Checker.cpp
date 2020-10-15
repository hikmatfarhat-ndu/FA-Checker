// FA-Checker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <boost/container_hash/hash.hpp>
#include "FA.h"
extern std::optional<FA> readFA(std::string);
extern std::optional<std::vector<std::pair<std::string,bool>>>
readTests(std::string);

int main(int argc,char **argv)
{
    if (argc < 3) {
        std::cout << "Usage FA-checker NFA-description Tests\n";
        exit(1);
    }
    if (auto n = readFA(argv[1]) ) {
        FA nfa = *n;
        if (auto t = readTests(argv[2])) {
            std::vector<std::pair<std::string, bool>> v = *t;
            int count = 1;
            for (auto& [a, b] : v) {
                //std::cout << a << " " <<std::boolalpha<< b << "\n";
                bool r = nfa.accept(a);
                if (r == b)std::cout << "\x1B[32mcheck " << count
                <<" passed \033[0m\n";
                else {
                    std::cout << "\x1B[31mcheck "<<count
                        <<" failed \033[0m";
                    std::cout << " Input:" << a
                        << " Expected: " << b << " Result:" << r << std::endl;
                }
                ++count;
            }
        }
       
    }
    else {
        std::cout << "could not read input\n";
        exit(1);
    }
}
