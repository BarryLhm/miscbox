#include "args.hpp"
#include "common.hpp"

#include <iostream>
#include <string>
#include <vector>

ArgParser::ArgParser(const std::string& progname)
{
	argm_ = { { progname } };
}

const std::vector<std::vector<std::string>>& ArgParser::argm() { return argm_; }

M_RESULT ArgParser::parse_args(int argc, char* argv[])
{
	std::vector<std::string> args(argv + 1, argv + argc);
	for (int p = 0; p < args.size(); ++p) {
		const std::string& arg = args[p];
		if (args.empty()) {
			return R_INVALID; // fixme
		} else if (arg.front() == '-') {
			argm_.back().push_back(arg);
		} else {
			argm_.push_back({ arg });
		}
	}
	return R_SUCCESS;
}
