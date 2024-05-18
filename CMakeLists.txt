cmake_minimum_required(VERSION 3.2)

project(ComputerClub)

set(CMAKE_CXX_STANDARD 20)

include(cmake/function.cmake)

add_subdirectory(include)
add_subdirectory(main)

option(BTEST "build test?" OFF)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()
