#!/bin/sh
## not executable, just for syntax highlighting

prompt="	->"

error()
{
	echo "$prompt [ERROR] $1" >&2; exit "${2-1}"
}

export PLATFORM=UNDEFINED
case "$(uname -s)" in
Linux) PLATFORM=linux;;
MSYS*) PLATFORM=windows;;
*) error "unknown platform"
esac

run()
{
	echo "$prompt running ${target##*/} $*" >&2
	"$target" "$@"
}

expect_fail()
{
	echo "$prompt expecting to fail: $*" >&2
	"$@" && error "not failed" || echo "returned $?" >&2
}

silently()
{
	"$@" >/dev/null
}

pass()
{
	echo "$prompt [OK] $1 passed test" >&2
}
