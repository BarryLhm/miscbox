#pragma once
#include "common.h"

typedef enum {
	D_NULLPTR,
	D_RAISE
} deathtype_t;

result_t die_main(deathtype_t type, int x);
