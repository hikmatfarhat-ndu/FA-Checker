#include <optional>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
std::string tolower(std::string s) {
	std::transform(s.begin(), s.end(),
		s.begin(),
		[](auto c) {return std::tolower(c); });
	return s;

}
std::optional<std::vector<std::pair<std::string,bool>>>
readTests(std::string filename) {

	std::ifstream file;
	file.open(filename);
	std::string input, expected;
	std::vector<std::pair<std::string,bool>> tests;
	if (file.is_open()) {
		while (file >> input >> expected) {
			bool e = (tolower(expected) == "true" ? true : false);
			tests.push_back(std::make_pair(input, e));
		}
		file.close();
		return tests;
	}

	else {
		std::cout << "cannot open file:" << filename << "\n";
		return {};
	}
}