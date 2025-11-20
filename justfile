default:
  just --list

build:
  cmake . -B build/
  cmake --build build/

run:
  build/miscbox
