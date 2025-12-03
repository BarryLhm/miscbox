#pragma once
#include "common.h"

typedef enum {
	IA_NO_REASON,
	IA_EMPTY_ARG,
	IA_UNKNOWN_ARG,
	IA_NEED_VALUE,
	IA_MISSING_ARG
} invalid_arg_t;

//[[noreturn]] void invalid_arg(invalid_arg_t reason, uint pos, uint info);
result_t parse_args(int argc, char* argv[]);
