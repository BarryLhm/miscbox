default:
  just --list

build:
  cmake -G Ninja -S . -B build/
  cmake --build build/

run:
  build/miscbox

clean:
  rm -rf build/
