#include <common.hpp>
#include "utils/die/die.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	die(mbox::utils::die::SEGV, 0);
	std::printf("hello\n");
}
