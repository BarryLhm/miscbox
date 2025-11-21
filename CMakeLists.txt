cmake_minimum_required(VERSION 3.23)

project(MiscBox)

include_directories(BEFORE src/base/)
include_directories(src/external/argparse/include/)

add_executable(miscbox)
target_sources(miscbox
  PRIVATE
    src/main.cpp
    src/base/args.cpp
    src/utils/die/die.cpp
)

