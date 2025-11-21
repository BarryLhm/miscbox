#include <common.hpp>
#include <args.hpp>
#include "utils/die/die.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	mbox::parse_args(mbox::from_argcv(argc, argv));
	//die(mbox::utils::die::SEGV, 0);
	std::printf("hello\n");
}
