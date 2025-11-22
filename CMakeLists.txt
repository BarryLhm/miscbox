cmake_minimum_required(VERSION 3.23)

project(MiscBox)

include_directories(BEFORE src/base/)

add_executable(miscbox)
target_sources(miscbox
  PRIVATE
    src/main.cpp
    src/base/args.cpp
    src/utils/die/die.cpp
)
target_include_directories(miscbox
  PUBLIC
    src/base/
)
