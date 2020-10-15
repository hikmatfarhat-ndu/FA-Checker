#pragma once
#include <optional>
#include "FA.h"
std::optional<FA> readFA(std::string);
std::optional<std::vector<std::tuple<std::string, bool,std::string>>>
readTests(std::string);