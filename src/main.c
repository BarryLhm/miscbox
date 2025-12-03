#include <stdio.h>
#include <string.h>

#include "common.h"
#include "utils.h"

int main(int argc, char* argv[])
{
	printf("hello\n");
	parse_args(argc, argv);
	if (argc > 1 && !strcmp(argv[1], "die")) {
		utils[U_DIE].run(0, NULL);
	}
	return 0;
}
