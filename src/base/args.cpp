#include <iostream>
#include <string>
#include <vector>

#include "args.hpp"
#include "common.hpp"

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
		if (args.empty()) return M_RESULT::INVALID;
		if (arg.front() == '-') {
			argm_.back().push_back(arg);
		} else {
			argm_.push_back({ arg });
		}
	}
	return M_RESULT::SUCCESS;
}
