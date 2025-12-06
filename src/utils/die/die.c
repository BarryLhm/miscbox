#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#include "error.h"

#include "sig_defs.h"

// keep both two below in strcmp order
typedef enum {
	D_NULLPTR,
	D_RAISE,
} deathtype_t;

const str2enum_t die_types[] = {
	{ "nullptr", D_NULLPTR },
	{ "raise", D_RAISE },
};

const size_t die_typec = sizeof die_types / sizeof(str2enum_t);

result_t die_help(int argc, char* argv[])
{
	return R_SUCCESS;
}

result_t die_main(int argc, char* argv[])
{
	if (argc <= 1) errexit(EXIT_ERROR, E_INVALID_ARG, "die type not specified\n");
	int type = str2enum(die_types, die_typec, argv[1]);
	switch (type) {
	case EN_NOT_FOUND: errexit(EXIT_ERROR, E_INVALID_ARG, "%s: unknown way to die\n", argv[1]);
	case D_NULLPTR: {
		if (argc > 2) errexit(EXIT_ERROR, E_INVALID_ARG, "extra argument\n");
		volatile int* nurupo = NULL;
		*nurupo = 114514;
		exit(EXIT_ERROR);
	}
	case D_RAISE: {
		if (argc <= 2) {
			raise(SIGABRT);
			errexit(EXIT_ERROR, E_FAILED, "I'm not killed!\n");
		}
		if (*argv[2] == '\0') errexit(EXIT_ERROR, E_INVALID_ARG, "empty string\n");
		// for(size_t ptr = argv[2], *ptr, ++ptr)
		//	if (*ptr >= 'A' && *ptr <= 'Z') ptr |= 32;
		char* endptr = NULL;
		errno = 0;
		long int signal = strtol(argv[2], &endptr, 10);
		if (errno == ERANGE) errexit(EXIT_ERROR, E_INVALID_ARG, "number overflow\n");
		if (signal) {
			if (*endptr != '\0') errexit(EXIT_ERROR, E_INVALID_ARG, "unknown signame\n");
			if (signal < 0 || signal > 64) errexit(EXIT_ERROR, E_INVALID_ARG, "sigid must be 1~64\n");
			if (raise(signal)) errexit(EXIT_ERROR, E_FAILED, "raise failed\n");
			errexit(EXIT_ERROR, E_FAILED, "I'm not killed!\n");
		}
		if (*endptr == '\0') errexit(EXIT_ERROR, E_INVALID_ARG, "there's no signal 0\n");
		signal = str2enum(die_signals, die_signalc, argv[2]);
		if (signal != EN_NOT_FOUND)
			;
		else if (strncmp(argv[2], "sig", 3))
			errexit(EXIT_ERROR, E_INVALID_ARG, "unknown signame\n");
		else {
			signal = str2enum(die_signals, die_signalc, argv[2] + 3);
			if (signal == EN_NOT_FOUND) errexit(EXIT_ERROR, E_INVALID_ARG, "unknown signame\n");
		}
		raise(signal);
		errexit(EXIT_ERROR, E_FAILED, "I'm not killed!\n");
	}
	default: return R_NOT_IMPLEMENTED;
	}
}
