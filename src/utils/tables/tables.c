#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#include "error.h"

#include "elements.h"

// keep both two below in strcmp order
typedef enum {
	TBL_ASCII,
	TBL_ELEMENTS,
} table_t;

const str2enum_t table_types[] = {
	{ "ascii",	   TBL_ASCII    },
	{ "elements", TBL_ELEMENTS },
};

const size_t table_typec = sizeof table_types / sizeof(str2enum_t);

result_t tables_help(int argc, char* argv[])
{
	return R_SUCCESS;
}

result_t tables_main(int argc, char* argv[])
{
	if (argc <= 1) errexit(EXIT_ERROR, E_INVALID_ARG, "table type not specified\n");
	int type = str2enum(table_types, table_typec, argv[1]);
	switch (type) {
	case EN_NOT_FOUND: errexit(EXIT_ERROR, E_INVALID_ARG, "%s: unknown table\n", argv[1]);
	case TBL_ELEMENTS: {
	}
	case TBL_ASCII: {
	}
	default: return R_NOT_IMPLEMENTED;
	}
}
