#include <stdio.h>
#include <string.h>

#include "common.h"
#include "utils/die/die.h"

int main(int argc, char* argv[])
{
	printf("hello\n");
	parse_args(argc, argv);
	if (argc > 1 && !strcmp(argv[1], "die")) {
		die(D_NULLPTR, 0);
	}
	return 0;
}
