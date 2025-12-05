#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#include "argparse.h"
#include "error.h"
#include "utils.h"

int main(int argc, char* argv[])
{
	printf("hello\n");
	parse_args(argc, argv);
	if (argc > 1) {
		util_t* util = util_match(argv[1]);
		printf("util addr: %p\n", util);
		if (!util) {
			error(E_INVALID_ARG, "%s\n", argv[1]);
			exit(1);
		}
		util->run(argc - 1, &argv[1]);
	}
	return 0;
}
