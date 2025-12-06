#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

#include "error.h"

#include "sig_defs.h"

// keep both two below in strcmp order
typedef enum {
	D_NULLPTR,
	D_RAISE,
} deathtype_t;

const str2enum_t die_types[] = {
	{ "nullptr", D_NULLPTR },
	{ "raise", D_RAISE },
};

const size_t die_typec = sizeof die_types / sizeof(str2enum_t);

result_t die_exec(deathtype_t type, int x); // move it up FIXME

result_t die_main(int argc, char* argv[])
{
	if (argc > 1) {
		deathtype_t type = str2enum(die_types, die_typec, argv[1]);
		if (type == EN_NOT_FOUND) {
			error(E_INVALID_ARG, "%s: unknown way to die", argv[1]);
			exit(EXIT_ERROR);
		}
		// return error;
		return die_exec(type, 0);
	}
	return R_FAILED;
}

result_t die_exec(deathtype_t type, int x)
{
	switch (type) {
	case D_NULLPTR:
		if (x != 0) return R_INVALID_ARG;
		{
			volatile int* nurupo = NULL;
			*nurupo = 114514;
		}
		return R_FAILED;
	case D_RAISE: raise(x); return R_NON_FATAL;
	default: return R_NOT_IMPLEMENTED;
	}
}
