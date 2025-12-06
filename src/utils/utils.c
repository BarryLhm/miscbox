#include <stdlib.h>
#include <string.h>

#include "common.h"

#include "../utils.h"
#include "argparse.h"
#include "error.h"

// no need to expose as address stored globally
result_t die_main(int argc, const char* argv[]);

// keep this in alphabetical order
const util_t utils[] = {
	{ "die", die_main }
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

result_t util_run(const char* name, size_t arg_shift, int argc, const char* argv[])
{
	util_t* util = util_match(name);
	if (!util) {
		error(E_NO_UTILITY, "%s\n", name);
		exit(EXIT_ERROR);
	}
	error_prog = name;
	argparse_offset += arg_shift;
	return util->run(argc - arg_shift, &argv[arg_shift]);
}
