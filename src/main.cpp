#include <iostream>

#include "args.hpp"
#include "common.hpp"
#include "utils/die/die.hpp"

int main(int argc, char* argv[])
{
	ArgParser parser("miscbox");
	parser.parse_args(argc, argv);
	std::cout << "hello\n";
	for (auto const& v: parser.argm()) {
		for (auto const& e: v) {
			std::cout << e << ' ';
		}
		std::cout << '\n';
	}
	if (parser.argm().size() > 1 && parser.argm()[1][0] == "die") {
		die(mbox::utils::die::DEATH_TYPE::SEGV, 0);
	}
	return 0;
}
