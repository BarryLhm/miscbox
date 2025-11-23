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
  find src/ -name '*.cpp' -o -name '*.hpp' | xargs clang-format --verbose -i

add:
  git add .

stat:
  git diff --cached --stat
