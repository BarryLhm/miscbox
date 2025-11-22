#pragma once
#include <string>
#include <vector>

#include "common.hpp"

class ArgParser {
	std::vector<std::vector<std::string>> argm_;

    public:
	explicit ArgParser(const std::string& progname);
	const std::vector<std::vector<std::string>>& argm();
	M_RESULT parse_args(int argc, char* argv[]);
};
