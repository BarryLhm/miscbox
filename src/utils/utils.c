#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "utils.h"

#include "die/entry.h"

const util_t utils[] = {
	{ "die", die_entry },
};

const size_t utilc = (sizeof(utils) / sizeof(util_t));

int util_cmp(const void* key, const void* elem)
{
	return strcmp((const char*)key, ((const util_t*)elem)->name);
}

void* util_match(const char* str)
{
	return bsearch(str, utils, utilc, sizeof(util_t), util_cmp);
}
