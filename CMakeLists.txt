cmake_minimum_required(VERSION 3.22)

project("Brights C++ Program - Assessment test 1 - Oskar Siegfrids 22.6.2023")


set(executable_name main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

#This is for testing, build with cmake -DENABLE_DOCTEST=ON
#if you want to build test executable 
option(DISABLE_DOCTEST "This is an option for disable building test exe" ON)
if(DISABLE_DOCTEST)
    add_executable(${executable_name} main.cpp)
    target_include_directories(${executable_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${executable_name} PUBLIC )
else()
    add_subdirectory(tests)
endif()





