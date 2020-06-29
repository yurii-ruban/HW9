cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(wineLib)

# TODO: find out, why I have to add definitions for all CMakeFiles.
function(SET_STRATEGY)
    if(USE_COMPOSITION)
        add_definitions(-DUSE_COMPOSITION)
    else()
        add_definitions(-DUSE_INHERITANCE)
    endif()
endfunction()

set(INCLUDE_DIR include)
set(SOURCE_DIR src)
set(SOURCES "${SOURCE_DIR}/wine.cpp")

set_strategy()
add_library(wine STATIC ${SOURCES})
target_include_directories(wine PUBLIC ${INCLUDE_DIR})