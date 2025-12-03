#include "utils.h"
#include "common.h"

#include "die/entry.h"

struct util_struct utils[U__MAX] = {
	[U_DIE] = { U_DIE, "die", die_entry },
};
