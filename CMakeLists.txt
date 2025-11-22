cmake_minimum_required(VERSION 3.23)

project(MiscBox)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(miscbox)

target_sources(miscbox
  PRIVATE
    src/main.cpp
    src/base/args.cpp
    src/utils/die/die.cpp
)

target_include_directories(miscbox
  PRIVATE
     src/base/
)
