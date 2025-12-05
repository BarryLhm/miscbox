#include <stdarg.h>
#include <stdio.h>

#include "common.h"

#include "error.h"

result_t perr(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	return R_SUCCESS;
}

result_t error(error_t type, const char* fmt, ...)
{
	va_list ap;
	fprintf(stderr, "[ERROR] ");
	switch (type) {
	case E_INVALID_ARG: fprintf(stderr, "invalid argument: "); break;
	default: fprintf(stderr, "error: ");
	}
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	return R_SUCCESS;
}
