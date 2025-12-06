#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

#include "error.h"

const char* error_prog = PROJECT_NAME;

result_t perr(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	return R_SUCCESS;
}

result_t verror(error_t type, const char* fmt, va_list vargs)
{
	fprintf(stderr, "[ERROR] ");
	switch (type) {
	case E_INVALID_ARG: fprintf(stderr, "invalid argument: "); break;
	default: fprintf(stderr, "error: ");
	}
	vfprintf(stderr, fmt, vargs);
	return R_SUCCESS;
}

result_t error(error_t type, const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	result_t retval = verror(type, fmt, ap);
	va_end(ap);
	return retval;
}

[[noreturn]] void errexit(int code, error_t type, const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	result_t retval = verror(type, fmt, ap);
	va_end(ap);
	exit(code);
}
