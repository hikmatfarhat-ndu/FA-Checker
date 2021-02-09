#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "FA.h"
#include "utils.h"
using nlohmann::json;

void runTests(json& p) {
	FA nfa{};
	try {
		nfa=parse_fa(p["NFA-specs"]);
		std::cout << "fsa file found\n";
	}
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "problem " << p["name"] << "\n";
	json& tests = p["tests"];
	bool flip = false;
	int total = 0;
	int possible = 0;
	for (auto& t : tests) {
		possible += t["points"];
		bool r = nfa.accept(t["input"]);
		bool er = t["expected-output"];
		if (r != er) {
			t["output"] = r;
			t["points"] = 0;
		}
		else {
			total += t["points"];
		}
	/*	t["output"] = true;
		t["non existent"] = "appeared";
		if (flip)t["points"] = 0;
		flip = !flip;
		total += t["points"];*/
	}
	p["total"] = total;
	p["max points"] = possible;

}


void  runProblems(std::string filename) {
	
	std::ifstream file;
	file.open(filename);
	std::string input(std::istreambuf_iterator<char>{file}, {});
	file.close();
	json tree;
	try {
		tree = json::parse(input);
	}
	catch (std::exception& e) {
		std::cout << "Abort\n";
		std::cout << e.what() << "\n";
		exit(1);
	}
	json& problems = tree["problems"];
	for (auto& p : problems)runTests(p);
	std::cout<<tree.dump(4)<<"\n";
}
int main(int argc,char **argv) {
	if (argc < 2) {
		std::cout << "usage: parse_problems filename.json\n";
		exit(1);
	}
	runProblems(argv[1]);
}