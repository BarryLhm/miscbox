#include <signal.h>

#include "common.h"
#include "die.h"

result_t die_entry(int argc, char* argv[])
{
	return die_main(D_NULLPTR, 0);
}

result_t die_main(deathtype_t type, int x)
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
