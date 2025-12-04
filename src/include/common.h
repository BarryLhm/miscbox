#pragma once
#include <stddef.h> // for size_t

typedef enum {
	R_SUCCESS,
	R_FAILED,
	R_INVALID_ARG,
	R_NOT_IMPLEMENTED,
	R_NON_FATAL
} result_t;

typedef enum {
	E_INVALID_ARG
} error_t;

typedef enum {
	IA_NO_REASON,
	IA_EMPTY_ARG,
	IA_UNKNOWN_ARG,
	IA_NEED_VALUE,
	IA_MISSING_ARG
} invalid_arg_t;

typedef struct {
	const char* name;
	int val;
} str2enum_t;
