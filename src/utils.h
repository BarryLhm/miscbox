#pragma once
#include "common.h"

result_t util_run(const char* name, size_t arg_shift, int argc, const char* argv[]);
result_t util_show_help(const char* name, size_t arg_shift, int argc, const char* argv[]);
