#pragma once

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

result_t perr(const char* fmt, ...);
result_t error(error_t type, const char* fmt, ...);

//[[noreturn]] void invalid_arg(invalid_arg_t reason, uint pos, uint info);
result_t parse_args(int argc, char* argv[]);
