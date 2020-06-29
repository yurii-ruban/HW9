cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(testApp)

# TODO: find out, why I have to add definitions for all CMakeFiles.
function(SET_STRATEGY)
    if(USE_COMPOSITION)
        add_definitions(-DUSE_COMPOSITION)
    else()
        add_definitions(-DUSE_INHERITANCE)
    endif()
endfunction()

add_subdirectory(lib)

set(INCLUDE_DIR include)
set(SOURCES main.cpp)

set_strategy()
add_executable(testapp ${SOURCES})
target_link_libraries(testapp wine)
target_include_directories(testapp PUBLIC ${INCLUDE_DIR})