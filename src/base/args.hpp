#include "common.hpp"

#include <vector>

class ArgParser {
	std::vector<std::vector<std::string>> argm_;

    public:
	ArgParser(const std::string& progname);
	const std::vector<std::vector<std::string>>& argm();
	M_RESULT parse_args(int argc, char* argv[]);
};
