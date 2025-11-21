#include <common.hpp>

#include <iostream>
#include <vector>

namespace mbox {
	std::vector<std::string> from_argcv(int argc, char* argv[]) {
		return std::vector<std::string>(argv, argv + argc);
	}
	M_RESULT parse_args(std::vector<std::string> args) {
		for (auto arg: args) std::cout << arg << std::endl;
		
		return R_SUCCESS;
	}
}
