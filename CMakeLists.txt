cmake_minimum_required(VERSION 3.22)

project("Brights C++ Program - Assessment test 1 - Oskar Siegfrids 22.6.2023")


set(executable_name main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)


add_executable(${executable_name} main.cpp)
target_include_directories(${executable_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${executable_name} PUBLIC transaction file_input_output transaction_functionality)

add_subdirectory(tests)





