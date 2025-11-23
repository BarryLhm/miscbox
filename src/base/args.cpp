#include <iostream>
#include <string>
#include <vector>

#include "args.hpp"
#include "common.hpp"

[[noreturn]] void ArgParser::invalid_arg_(InvalidArg reason, uint pos)
{
	//std::cerr << arg << " invalid!\n";
	std::cerr << "invalid argument\n";
	std::exit(1);
}

ArgParser& ArgParser::scanlist_add(uint pos, const std::string& arg, uint num)
{
	if (pos >= scanlist_.size()) scanlist_.resize(pos + 1);
	scanlist_[pos][arg] = num;
	return *this;
}

const std::vector<std::vector<std::string>>& ArgParser::parse_args(int argc, char* argv[])
{
	args_ = std::vector<std::string>(argv + 1, argv + argc);
	for (int pos = 0; pos < args_.size(); ++pos) {
		const std::string& arg = args_[pos];
		if (arg.empty()) invalid_arg_(InvalidArg::EMPTY_ARG, pos);
		if (arg.front() == '-') {
			argm_.back().push_back(arg);
		} else {
			argm_.push_back({ arg });
		}
	}
	return argm_;
}
