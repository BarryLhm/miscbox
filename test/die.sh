#!/bin/sh
## not executable, just for syntax highlighting

# nullptr
"$target" die nullptr && error "nullptr failed" || \
  [ "$?" != 139 ] && error "nullptr unexpected signal" || pass nullptr

# raise
case "$PLATFORM" in
linux)	for i in $(seq 1 18) $(seq 23 64)
	do expect_fail silently run die raise "$i"
	done
	for i in	EXIT HUP INT QUIT ILL TRAP ABRT BUS FPE KILL USR1 SEGV USR2 \
			PIPE ALRM TERM STKFLT CHLD CONT URG XCPU XFSZ VTALRM PROF \
			WINCH POLL PWR SYS
			# FIXME: add stop/tstp/ttin/ttou tests
	do	for j in "$i" "SIG$i"
		do	for k in "$j" "$(echo "$j" | tr '[:upper:]' '[:lower:]')"
			do expect_fail silently run die raise "$k"
			done
		done
	done
	;;
windows) :
	;;
esac
pass raise

