#pragma once
#include <signal.h>

#include "common.h"

#if defined(_WIN32)
const str2enum_t die_signals[] = {
	{ "abrt", SIGABRT },
	{ "fpe", SIGFPE },
	{ "ill", SIGILL },
	{ "int", SIGINT },
	{ "segv", SIGSEGV },
	{ "term", SIGTERM },
};

#elif defined(__linux__)
const str2enum_t die_signals[] = {
	{ "hup", SIGHUP },
	{ "int", SIGINT },
	{ "quit", SIGQUIT },
	{ "ill", SIGILL },
	{ "abrt", SIGABRT },
	{ "fpe", SIGFPE },
	{ "kil", SIGKILL },
	{ "segv", SIGSEGV },
	{ "pipe", SIGPIPE },
	{ "alrm", SIGALRM },
	{ "term", SIGTERM },
	{ "usr1", SIGUSR1 },
	{ "usr2", SIGUSR2 },
	{ "chld", SIGCHLD },
	{ "cont", SIGCONT },
	{ "stop", SIGSTOP },
	{ "tstp", SIGTSTP },
	{ "ttin", SIGTTIN },
	{ "ttou", SIGTTOU },
	{ "bus", SIGBUS },
	{ "poll", SIGPOLL },
	{ "prof", SIGPROF },
	{ "sys", SIGSYS },
	{ "trap", SIGTRAP },
	{ "urg", SIGURG },
	{ "vtalrm", SIGVTALRM },
	{ "xcpu", SIGXCPU },
	{ "xfsz", SIGXFSZ },
	{ "iot", SIGIOT },
	{ "emt", SIGEMT },
	{ "stkflt", SIGSTKFLT },
	{ "io", SIGIO },
	{ "pwr", SIGPWR },
	{ "info", SIGINFO },
	{ "lost", SIGLOST },
	{ "winch", SIGWINCH },
};

#endif

const size_t die_signalc = (sizeof(die_signals) / sizeof(str2enum_t));
