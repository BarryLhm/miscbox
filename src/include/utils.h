#pragma once
#include "common.h"

typedef enum {
	U_DIE,
	U__MAX
} util_t;

typedef result_t (*util_entry_t)(int argc, char* argv[]);

struct util_struct {
	util_t id;
	char* name;
	util_entry_t run;
};

extern struct util_struct utils[U__MAX];
