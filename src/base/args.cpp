#include <any>
#include <iostream>
#include <string>
#include <vector>

#include "args.hpp"
#include "common.hpp"

[[noreturn]] void ArgParser::invalid_arg_(InvalidArg reason, uint pos, std::any info)
{
	switch (reason) {
	case InvalidArg::NO_REASON: std::printf("invalid argument at pos %u\n", pos); break;
	case InvalidArg::EMPTY_ARG: {
		std::cout << "invalid argument: empty string at pos "
			  << pos << '\n'
			  << args_[0];
		for (uint i = 1; i < pos; ++i) std::cout << ' ' << args_[i];
		std::cout << " >>> " << args_[pos] << " <<<";
		for (uint i = pos + 1; i < args_.size(); ++i) std::cout << ' ' << args_[i];
		std::cout << '\n';
		break;
	}
	default: std::cerr << "invalid argument\n";
	}
	std::exit(1);
}

ArgParser::ArgParser(const std::string& progname) : argm_ { { progname } } { }

ArgParser& ArgParser::add_optarg(uint pos, const std::string& arg, uint num)
{
	if (pos >= optargs_.size()) optargs_.resize(pos + 1);
	optargs_[pos][arg] = num;
	return *this;
}

const std::vector<std::vector<std::string>>& ArgParser::parse_args(int argc, char* argv[])
{
	args_ = std::vector<std::string>(argv, argv + argc);
	for (uint pos = 1; pos < args_.size(); ++pos) {
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
