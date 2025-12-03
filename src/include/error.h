#pragma once
#include "common.h"

typedef enum {
	E_INVALID_ARG
} error_t;

result_t perr(const char* fmt, ...);
result_t error(error_t type, const char* fmt, ...);
