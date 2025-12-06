#pragma once
#include "common.h"

typedef result_t (*util_entry_t)(int argc, const char* argv[]);

typedef struct {
	const char* name;
	const util_entry_t run;
	const util_entry_t show_help;
} util_t;

extern const util_t utils[];
extern const size_t utilc;

result_t util_run(const char* name, size_t arg_shift, int argc, const char* argv[]);
result_t util_show_help(const char* name, size_t arg_shift, int argc, const char* argv[]);
