#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#include "argparse.h"
#include "error.h"
#include "utils.h"

int main(int argc, const char* argv[])
{
	printf("hello\n");
	if (argc > 1) {
		util_run(argv[1], 1, argc, argv);
	}
	return 0;
}
