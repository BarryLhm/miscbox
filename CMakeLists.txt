cmake_minimum_required(VERSION 3.23)

project(MiscBox)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_executable(miscbox)
target_sources(miscbox
  PRIVATE
    src/main.cpp
)

