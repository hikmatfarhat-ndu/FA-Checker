#pragma once
#include <optional>
#include "FA.h"
std::optional<FA> readFA(std::string);
std::optional<std::vector<std::pair<std::string, bool>>>
readTests(std::string);