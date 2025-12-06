#pragma once
#include <signal.h>

#include "common.h"

#if defined(_WIN32)
// strcmp order
const str2enum_t die_signals[] = {
	{ "abrt", SIGABRT },
	{ "fpe", SIGFPE },
	{ "ill", SIGILL },
	{ "int", SIGINT },
	{ "segv", SIGSEGV },
	{ "term", SIGTERM },
};

#elif defined(__linux__)
// strcmp order
const str2enum_t die_signals[] = {
	/* unsorted original list
	{ "hup", SIGHUP },	 // 1
	{ "int", SIGINT },	 // 2
	{ "quit", SIGQUIT },	 // 3
	{ "ill", SIGILL },	 // 4
	{ "trap", SIGTRAP },	 // 5
	{ "abrt", SIGABRT },	 // 6
	{ "iot", SIGIOT },	 // 6
	{ "bus", SIGBUS },	 // 7
	{ "fpe", SIGFPE },	 // 8
	{ "kill", SIGKILL },	 // 9
	{ "usr1", SIGUSR1 },	 // 10
	{ "segv", SIGSEGV },	 // 11
	{ "usr2", SIGUSR2 },	 // 12
	{ "pipe", SIGPIPE },	 // 13
	{ "alrm", SIGALRM },	 // 14
	{ "term", SIGTERM },	 // 15
	{ "stkflt", SIGSTKFLT }, // 16
	{ "chld", SIGCHLD },	 // 17
	{ "cont", SIGCONT },	 // 18
	{ "stop", SIGSTOP },	 // 19
	{ "tstp", SIGTSTP },	 // 20
	{ "ttin", SIGTTIN },	 // 21
	{ "ttou", SIGTTOU },	 // 22
	{ "urg", SIGURG },	 // 23
	{ "xcpu", SIGXCPU },	 // 24
	{ "xfsz", SIGXFSZ },	 // 25
	{ "vtalrm", SIGVTALRM }, // 26
	{ "prof", SIGPROF },	 // 27
	{ "winch", SIGWINCH },	 // 28
	{ "io", SIGIO },	 // 29
	{ "poll", SIGPOLL },	 // 29
	{ "pwr", SIGPWR },	 // 30
	{ "sys", SIGSYS },	 // 31
	*/

	// sorted list
	// generated with `head -END FILE | tail +START | sort >> FILE`
	{ "abrt", SIGABRT },	 // 6
	{ "alrm", SIGALRM },	 // 14
	{ "bus", SIGBUS },	 // 7
	{ "chld", SIGCHLD },	 // 17
	{ "cont", SIGCONT },	 // 18
	{ "fpe", SIGFPE },	 // 8
	{ "hup", SIGHUP },	 // 1
	{ "ill", SIGILL },	 // 4
	{ "int", SIGINT },	 // 2
	{ "io", SIGIO },	 // 29
	{ "iot", SIGIOT },	 // 6
	{ "kill", SIGKILL },	 // 9
	{ "pipe", SIGPIPE },	 // 13
	{ "poll", SIGPOLL },	 // 29
	{ "prof", SIGPROF },	 // 27
	{ "pwr", SIGPWR },	 // 30
	{ "quit", SIGQUIT },	 // 3
	{ "segv", SIGSEGV },	 // 11
	{ "stkflt", SIGSTKFLT }, // 16
	{ "stop", SIGSTOP },	 // 19
	{ "sys", SIGSYS },	 // 31
	{ "term", SIGTERM },	 // 15
	{ "trap", SIGTRAP },	 // 5
	{ "tstp", SIGTSTP },	 // 20
	{ "ttin", SIGTTIN },	 // 21
	{ "ttou", SIGTTOU },	 // 22
	{ "urg", SIGURG },	 // 23
	{ "usr1", SIGUSR1 },	 // 10
	{ "usr2", SIGUSR2 },	 // 12
	{ "vtalrm", SIGVTALRM }, // 26
	{ "winch", SIGWINCH },	 // 28
	{ "xcpu", SIGXCPU },	 // 24
	{ "xfsz", SIGXFSZ },	 // 25
};
#endif

const size_t die_signalc = sizeof die_signals / sizeof(str2enum_t);
