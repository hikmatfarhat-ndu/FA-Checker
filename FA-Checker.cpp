// FA-Checker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <boost/container_hash/hash.hpp>
#include "FA.h"
int main()
{
   

    FA nfa{'p'};
    nfa.addTransition('p', '0', std::unordered_set<char>{'p'});
    nfa.addTransition('p', '1', std::unordered_set<char>{'p','q'});
    nfa.addTransition('q', '0', std::unordered_set<char>{'t'});
    nfa.addTransition('q', '1', std::unordered_set<char>{'t'});
    nfa.addTransition('t', '0', std::unordered_set<char>{});
    nfa.addTransition('t', '1', std::unordered_set<char>{});

   //auto result=nfa.step(std::unordered_set<char>{'p'}, '1');
    auto result = nfa.run("0110");

   for (auto& p : result)
       std::cout << p << ",";
    
   
}
