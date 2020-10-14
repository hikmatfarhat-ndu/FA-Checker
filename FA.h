#pragma once
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <boost/container_hash/hash.hpp>
using STATE = char;
class FA {
public:
	// We have to supply a hash function
	// for std::pair. Instead we are using
	// Boost to do that
	STATE initial;

	std::unordered_map < std::pair<STATE, char>,
		std::unordered_set<STATE>,
		boost::hash<std::pair<STATE, char>>
		> transitions;
	FA(STATE i) :initial(i) {}
	void addTransition(STATE p, char a, std::unordered_set<STATE> s) {
		transitions.insert(
			std::make_pair(std::make_pair(p,a) ,s)
		);
	}
	std::unordered_set<STATE> step(std::unordered_set<STATE> start,
									char a) 
	{
		std::unordered_set<STATE> result;
		for (const STATE & p : start) {
			auto q
				=transitions.find(std::make_pair(p, a));
			if (q != transitions.end())
				//important to create a copy of q
				//otherwise merge will "remove" the pair
				// from transitions
				result.merge(std::unordered_set<STATE>(q->second));

		}
		return result;
	}
	std::unordered_set<STATE> run(std::string input) {
		std::unordered_set<STATE> res{ initial };
		for (auto& a : input) 
			res = step(res, a);
		return res;
	}
};