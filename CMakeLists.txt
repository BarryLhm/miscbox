cmake_minimum_required(VERSION 3.23)

project(MiscBox)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(miscbox)

target_sources(miscbox
    PRIVATE
	src/main.c
	src/base/error.c
	src/base/argparse.c
	src/utils/die/die.c
)

target_include_directories(miscbox
    PRIVATE
	src/base/
)
