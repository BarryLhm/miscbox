#pragma once
#include "common.h"

typedef enum {
	E_INVALID_ARG,
	E_NO_UTILITY,
} error_t;

extern const char* error_prog;

result_t perr(const char* fmt, ...);
result_t error(error_t type, const char* fmt, ...);
