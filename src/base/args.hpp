#pragma once
#include <any>
#include <string>
#include <unordered_map>
#include <vector>

#include "common.hpp"

class ArgParser {
	std::vector<std::string> args_;
	std::vector<std::vector<std::string>> argm_;
	std::vector<std::unordered_map<std::string, uint>> optargs_;
	enum class InvalidArg {
		NO_REASON,
		EMPTY_ARG,
		UNKNOWN_ARG,
		NEED_VALUE,
		MISSING_ARG
	};

	[[noreturn]] void invalid_arg_(InvalidArg reason, uint pos, std::any info);

    public:
	explicit ArgParser(const std::string& progname) { argm_ = { { progname } }; }

	const std::vector<std::string>& args() { return args_; }

	const std::vector<std::vector<std::string>>& argm() { return argm_; }

	ArgParser& add_optarg(uint pos, const std::string& arg, uint num);
	const std::vector<std::vector<std::string>>& parse_args(int argc, char* argv[]);
};
