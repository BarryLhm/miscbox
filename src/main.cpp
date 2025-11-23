#include <iostream>

#include "args.hpp"
#include "common.hpp"
#include "utils/die/die.hpp"

int main(int argc, char* argv[])
{
	auto argm = ArgParser("miscbox")
			.scanlist_add(0, "--test3", 3)
			.scanlist_add(0, "--test4", 4)
			.parse_args(argc, argv);
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
