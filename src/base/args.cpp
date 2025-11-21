#include <common.hpp>

#include <iostream>
#include <vector>

namespace mbox {
	std::vector<std::string> from_argcv(int argc, char* argv[]) {
		std::vector<std::string> args;
		for (int i = 0; i < argc; ++i) args[i] = std::string(argv[i]);
		return args;
	}
	M_RESULT parse_args(std::vector<std::string> args) {
		for (auto arg: args) std::cout << arg << std::endl;
		return R_SUCCESS;
	}
}
