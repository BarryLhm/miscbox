#include <stdio.h>
#include <stdlib.h>

#include "common.h"

[[noreturn]] void invalid_arg(
    char* args[],
    invalid_arg_t reason,
    uint pos,
    uint info)
{
	switch (reason) {
	case IA_NO_REASON: error(E_INVALID_ARG, "at pos %u\n", pos); break;
	case IA_EMPTY_ARG: {
		error(E_INVALID_ARG, "empty string at pos %u\ncmdline:", pos);
		for (uint i = 0; i < pos; ++i) perr(" %s", args[i]);
		perr(" >>> %s <<<", args[pos]);
		for (uint i = pos; args[++i] != NULL;) perr(" %s", args[i]);
		perr("\n");
		break;
	}
	default: error(E_INVALID_ARG, "DEFAULT_MESSAGE\n");
	}
	exit(1);
}

result_t parse_args(int argc, char* argv[])
{
	return R_SUCCESS;
}
