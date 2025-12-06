#include <stdlib.h>
#include <string.h>

#include "common.h"

#include "../utils.h"
#include "argparse.h"
#include "error.h"

typedef enum {
	UO_RUN,
	UO_HELP,
} util_oper_t;

// they should exist
#define UTIL_DECLARE(name)                                  \
	result_t name##_main(int argc, const char* argv[]); \
	result_t name##_help(int argc, const char* argv[]);
#define UTIL_REGISTER(name) { #name, name##_main, name##_help },

UTIL_DECLARE(die)

// keep this in alphabetical order
const util_t utils[] = {
	UTIL_REGISTER(die)
};

const size_t utilc = sizeof utils / sizeof(util_t);

int util_cmp(const void* key, const void* elem)
{
	return strcmp((const char*)key, ((const util_t*)elem)->name);
}

void* util_match(const char* str)
{
	return bsearch(str, utils, utilc, sizeof(util_t), util_cmp);
}

result_t util_oper(util_oper_t oper, const char* name, size_t arg_shift, int argc, const char* argv[])
{
	util_t* util = util_match(name);
	if (!util) {
		error(E_NO_UTILITY, "%s\n", name);
		exit(EXIT_ERROR);
	}
	error_prog = name;
	argparse_offset += arg_shift;
	switch (oper) {
	case UO_RUN: return util->run(argc - arg_shift, &argv[arg_shift]);
	case UO_HELP: return util->show_help(argc - arg_shift, &argv[arg_shift]);
	default: errexit(EXIT_ERROR, E_INTERNAL, "unknown util operation\n");
	}
}

result_t util_run(const char* name, size_t arg_shift, int argc, const char* argv[])
{
	return util_oper(UO_RUN, name, arg_shift, argc, argv);
}

result_t util_help(const char* name, size_t arg_shift, int argc, const char* argv[])
{
	return util_oper(UO_HELP, name, arg_shift, argc, argv);
}
