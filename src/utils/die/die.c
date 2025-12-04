#include <signal.h>

#include "common.h"
#include "die.h"

// keep both two below in strcmp order
typedef enum {
	D_RAISE,
	D_NULLPTR
} deathtype_t;

const str2enum_t die_types[] = {
	{ "raise", D_RAISE },
	{ "nullptr", D_NULLPTR }
};

const size_t die_typec = (sizeof(die_types) / sizeof(str2enum_t));

result_t die_main(int argc, char* argv[])
{
	if (argc > 1) {
		str2enum(
		return die_exec(D_NULLPTR, 0);
	}
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
