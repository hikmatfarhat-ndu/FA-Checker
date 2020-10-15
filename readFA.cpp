#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <optional>
#include <boost/algorithm/string.hpp>
#include "FA.h"

std::optional<FA> readFA(std::string filename) {
	std::ifstream file;
	file.open(filename);
	std::string tmp;
	STATE starting;
	FA nfa{};
	std::unordered_set<STATE> accepting;

	if (file.is_open()) {
		
		//process the starting state
		while (std::getline(file, tmp)) {
			tmp.erase(
				std::remove(tmp.begin(), tmp.end(), ' '),
				tmp.end());
			if (tmp=="" || tmp.find('#') != std::string::npos )continue;
			
			
			std::vector<std::string> v;
			boost::split(v, tmp,
				boost::is_any_of("-"));
			if (v.size() != 2 || v[0]!="starting") {
				std::cout << "invalid starting state\n";
				return {};
			}
			
			starting = v[1];
			break;
		}
		// if no starting state
		if (starting == "") {
			std::cout << "missing starting state\n";
			return {};
		}
		//process the accepting set
		while(std::getline(file, tmp)) {
			tmp.erase(
				std::remove(tmp.begin(), tmp.end(), ' '),
				tmp.end());
			if (tmp=="" || tmp.find('#') != std::string::npos)continue;
			std::vector<std::string> v;
			boost::split(v, tmp,
				boost::is_any_of("-,"));
			if (v[0] != "accepting") {
				std::cout << "invalid accepting\n";
				return {};
			}
			accepting.insert(v.begin() + 1, v.end());
			break;
		}
		if (accepting.empty()) {
			std::cout << "missing accepting state(s)\n";
			return {};
		}
		nfa.starting() = starting;
		nfa.accepting()=accepting;
		while (std::getline(file, tmp)) {
			tmp.erase(
				std::remove(tmp.begin(), tmp.end(), ' '),
				tmp.end());
			if (tmp == "" || tmp.find('#') != std::string::npos)continue;

			std::vector < std::string> v;
			

			boost::split(v, tmp,
				boost::is_any_of("-,"));
			nfa.addTransition(v[0], v[1][0],
				std::unordered_set<STATE>(v.begin() + 2, v.end()));
		}
	}
	else {
		std::cout << "cannot open file:"<<filename<<"\n";
		//std::string s(get_current_dir_name());
		//std::cout<<s<<std::endl;
		return {};
	}
	return nfa;

}
