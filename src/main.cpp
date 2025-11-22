#include "common.hpp"
#include "args.hpp"
#include "utils/die/die.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	ArgParser parser("miscbox");
	parser.parse_args(argc, argv);
	//die(mbox::utils::die::SEGV, 0);
	std::printf("hello\n");
	for (auto v: parser.argm()) {
		for (auto e: v) {
			std::cout << e << ' ';
		}
	std::cout << std::endl;
	}
	return 0;
}
