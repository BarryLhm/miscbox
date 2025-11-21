#include <common.h>
#include "utils/die/die.h"

#include <iostream>

int main(int argc, char* argv[])
{
	die(mbox::utils::die::SEGV, 0);
	std::printf("hello\n");
}
