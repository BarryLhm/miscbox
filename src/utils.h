#pragma once
#include "common.h"
#include <stddef.h>

typedef result_t (*util_entry_t)(int argc, char* argv[]);

typedef struct {
	const char* name;
	const util_entry_t run;
} util_t;

extern const util_t utils[];
extern const size_t utilc;

void* util_match(const char* str);
