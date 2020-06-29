cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(testApp)

add_subdirectory(lib)

set(INCLUDE_DIR include)
set(INCLUDES "${INCLUDE_DIR}/wine.h")
set(SOURCES main.cpp)

add_executable(testapp ${SOURCES})
target_include_directories(testapp PUBLIC ${INCLUDES})
