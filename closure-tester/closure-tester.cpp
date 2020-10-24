// closure-tester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
#include "../FA.h"

int main()
{
	{
		FA nfa("p0", { "p1","p2" });
		nfa.addTransition("p0", 'e', { "p1" });
		nfa.addTransition("p0", '0', { "p3" });
		nfa.addTransition("p1", 'e', { "p2","p3" });
		nfa.addTransition("p3", '1', { "p4" });
		auto result = nfa.closure(std::unordered_set<STATE>{ "p0" });
		auto p = nfa.closure("p1");
		std::cout << "done\n";
	}
	{
		FA nfa("p0", { "p1","p2" });
		nfa.addTransition("p0", 'e', { "p1" });
		nfa.addTransition("p0", '0', { "p3" });
		nfa.addTransition("p1", 'e', { "p2" });
		nfa.addTransition("p1", 'e', { "p3" });
		nfa.addTransition("p3", '1', { "p4" });
		auto result = nfa.closure(std::unordered_set<STATE>{ "p0" });
		auto p = nfa.closure("p1");
		std::cout << "done\n";
	}
}
