#pragma once
#include "common.h"

typedef enum {
	E_INVALID_ARG,
	E_NO_UTILITY,
	E_FAILED,
	E_INTERNAL,
} error_t;

extern const char* error_prog;

result_t perr(const char* fmt, ...);
result_t error(error_t type, const char* fmt, ...);
[[noreturn]] void errexit(int code, error_t type, const char* fmt, ...);
