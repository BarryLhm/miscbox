#include <any>
#include <iostream>
#include <string>
#include <vector>

#include "args.hpp"
#include "common.hpp"

[[noreturn]] void ArgParser::invalid_arg_(InvalidArg reason, uint pos, std::any info)
{
	// std::cerr << arg << " invalid!\n";
	std::cerr << "invalid argument\n";
	std::exit(1);
}

ArgParser& ArgParser::add_optarg(uint pos, const std::string& arg, uint num)
{
	if (pos >= optargs_.size()) optargs_.resize(pos + 1);
	optargs_[pos][arg] = num;
	return *this;
}

const std::vector<std::vector<std::string>>& ArgParser::parse_args(int argc, char* argv[])
{
	args_ = std::vector<std::string>(argv + 1, argv + argc);
	for (uint pos = 0; pos < args_.size(); ++pos) {
		const auto& arg = args_[pos];
		if (arg.empty()) invalid_arg_(InvalidArg::EMPTY_ARG, pos, std::any {});
		if (arg.front() == '-') {
			argm_.back().push_back(arg);
			if (optargs_.size() < argm_.size()) continue;
			const auto& oam = optargs_[argm_.size() - 1];
			const auto& oae = oam.find(arg);
			if (oae == oam.end()) continue;
			auto count = oae->second;
			if (count == 0) continue;
			auto last_pos = pos + count;
			if (last_pos >= args_.size()) {
				invalid_arg_(InvalidArg::NEED_VALUE, pos, count);
			}
			while (++pos <= last_pos) argm_.back().push_back(args_[pos]);
			--pos;
		} else {
			argm_.push_back({ arg });
		}
	}
	return argm_;
}
