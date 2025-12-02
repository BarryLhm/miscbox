#!/bin/sh

set -eu

dir="$( realpath "$0")"
dir="${dir%/*}"
oper="${1-list}"
shift

set -x

cd "$dir/"
case "$oper" in
list)	echo build run clean format add stat
	;;
build)	cmake -G Ninja -S . -B build/
	cmake --build build/
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
esac
