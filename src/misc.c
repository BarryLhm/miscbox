#include <stdlib.h>
#include <string.h>

#include "common.h"

#include "error.h"

int str2enum_cmp(const void* key, const void* elem)
{
	return strcmp((const char*)key, ((const str2enum_t*)elem)->name);
}

int str2enum(const str2enum_t list[], size_t size, const char* str)
{
	str2enum_t* item = bsearch(str, list, size, sizeof(str2enum_t), str2enum_cmp);
	if (!item) return EN_NOT_FOUND;
	return item->val;
}
