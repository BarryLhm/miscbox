#include <vector>

namespace mbox {
	std::vector<std::string> from_argcv(int argc, char* argv[]);
	M_RESULT parse_args(std::vector<std::string> args);
}
