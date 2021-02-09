#pragma once
#include <string>
#include "FA.h"


std::string print_fail(std::string s);
std::string print_success(std::string s);

FA parse_fa(std::string);


class invalid_spec :std::exception {
	std::string _message;
public:
	invalid_spec(std::string message) :_message(message) {}
	const char* what() const noexcept override {
		return _message.c_str();
	}
};