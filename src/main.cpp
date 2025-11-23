#include <iostream>

#include "args.hpp"
#include "common.hpp"
#include "utils/die/die.hpp"

int main(int argc, char* argv[])
{
	ArgParser parser("miscbox");
	parser.add_optarg(0, "--test3", 3);
	parser.add_optarg(0, "--test4", 4);
	auto argm = parser.parse_args(argc, argv);
	std::cout << "hello\n";
	for (auto const& v: argm) {
		for (auto const& e: v) {
			std::cout << e << ' ';
		}
		std::cout << '\n';
	}
	if (argm.size() > 1 && argm[1][0] == "die") {
		die(mbox::utils::die::DeathType::SEGV, 0);
	}
	return 0;
}
