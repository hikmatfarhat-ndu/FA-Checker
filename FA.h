#pragma once
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <boost/container_hash/hash.hpp>
using STATE = std::string;
class FA {

	// We have to supply a hash function
	// for std::pair. Instead we are using
	// Boost to do that
	STATE _starting;
	std::unordered_set<STATE> _accepting;

	std::unordered_map < std::pair<STATE, char>,
		std::unordered_set<STATE>,
		boost::hash<std::pair<STATE, char>>
		> transitions;


	std::unordered_set<STATE> step(std::unordered_set<STATE> start,
		char a)
	{
		std::unordered_set<STATE> result;
		for (const STATE& p : start) {
			auto q
				= transitions.find(std::make_pair(p, a));
			if (q != transitions.end())
				//important to create a copy of q
				//otherwise merge will "remove" the pair
				// from transitions
				result.merge(std::unordered_set<STATE>(q->second));

		}
		return result;
	}
public:
	FA() {}
	FA(STATE i, std::unordered_set<STATE> a)
		:_starting(i), _accepting(a) {}
	FA(STATE i,std::initializer_list<STATE> a)
		:_starting(i),_accepting(a) {}

	void addTransition(STATE p, char a, std::unordered_set<STATE> s) {
		transitions.insert(
			std::make_pair(std::make_pair(p,a) ,s)
		);
	}
	
	std::unordered_set<STATE> run(std::string input) {
		std::unordered_set<STATE> res{ _starting };
		for (auto& a : input) 
			res = step(res, a);
		return res;
	}
	bool accept(std::string input) {
		auto res = run(input);
		for (auto& p : res) {
			if (_accepting.count(p) > 0)
				return true;
		}
		return false;

	}
	STATE& starting() {
		return _starting;
	}
	std::unordered_set<STATE> & accepting() {
		return _accepting;
	}
};