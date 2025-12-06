#pragma once
#include <stddef.h> // for size_t

#define PROJECT_NAME "miscbox"

typedef enum {
	R_SUCCESS,
	R_FAILED,
	R_INVALID_ARG,
	R_NOT_IMPLEMENTED,
	R_NON_FATAL,
} result_t;

enum {
	EXIT_ERROR = -1,
	EN_NOT_FOUND = -114514,
};

typedef struct {
	const char* name;
	int val;
} str2enum_t;

int str2enum(const str2enum_t list[], size_t size, const char* str);
