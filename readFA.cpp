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
		if (std::getline(file, tmp)) {
			std::vector<std::string> v;
			tmp.erase(
				std::remove(tmp.begin(), tmp.end(), ' '),
				tmp.end());
			boost::split(v, tmp,
				boost::is_any_of("-"));
			if (v.size() != 2) {
				std::cout << "invalid starting state\n";
				return {};
			}
			starting = v[1];
		}
		else {
			std::cout << "cannot read first line\n";
			return {};
		}
		//process the accepting set
		if (std::getline(file, tmp)) {
			std::vector<std::string> v;
			tmp.erase(
				std::remove(tmp.begin(), tmp.end(), ' '),
				tmp.end());
			boost::split(v, tmp,
				boost::is_any_of("-,"));
			
			accepting.insert(v.begin() + 1, v.end());
		}
		else {
			std::cout << "cannot read second line\n";
			return {};
		}
		nfa.starting() = starting;
		nfa.accepting()=accepting;
		while (std::getline(file, tmp)) {
			if (tmp.find("#") == std::string::npos) {//no #
				std::vector < std::string> v;
				tmp.erase(
					std::remove(tmp.begin(),tmp.end(),' '),
					tmp.end());
				boost::split(v, tmp,
					boost::is_any_of("-,"));
				nfa.addTransition(v[0], v[1][0],
					std::unordered_set<STATE>(v.begin() + 2, v.end()));
				//for (auto& x : v)std::cout << x << ",";
				//std::cout << std::endl;
			}

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
