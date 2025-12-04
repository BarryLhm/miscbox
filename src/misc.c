#include "common.h"

int str2enum_cmp(const void* key, const void* elem)
{
	return strcmp((const char*)key, ((const str2enum_t*)elem)->name);
}

void* str2enum(const* str2enum_t list, int size, const char* str)
{
	return bsearch(str, list, size, sizeof(str2enum_t), str2enum_cmp);
}
