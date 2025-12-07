#!/bin/sh

set -eu

dir="$(realpath "$0")"
dir="${dir%/*}"
oper="${1-list}"
shift

set -x

cd "$dir/"
case "$oper" in
list)	echo build debug run clean format add stat disable-coredump
	;;
debug)	cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Debug
	cmake --build build/ -j "$(nproc)"
	;;
build)	cmake -S . -B build/
	cmake --build build/ -j "$(nproc)"
	;;
run)	build/miscbox "$@"
	;;
clean)	rm -rf build/
	;;
format)	find src/ -name '*.c' -o -name '*.h' | xargs clang-format --verbose -i
	;;
add)	git add .
	;;
stat)	git diff --cached --stat
	;;
disable-coredump) :
	sudo sysctl kernel.core_pattern='|/bin/false'
	;;
test)	target=build/miscbox test/run_test
	;;
*)	echo "$0: $oper: unknown operation"
	exit 1
	;;
esac
