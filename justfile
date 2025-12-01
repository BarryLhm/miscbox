default:
  just --list

build:
  cmake -G Ninja -S . -B build/
  cmake --build build/

run:
  build/miscbox

clean:
  rm -rf build/

format:
  find src/ -name '*.c' -o -name '*.h' | xargs clang-format --verbose -i

add:
  git add .

stat:
  git diff --cached --stat
