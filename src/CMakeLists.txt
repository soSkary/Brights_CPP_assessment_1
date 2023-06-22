add_library(transaction transaction.cpp)
target_include_directories(transaction PUBLIC ${CMAKE_SOURCE_DIR}/include)


add_library(transaction_functionality transaction_functionality.cpp)
target_include_directories(transaction_functionality PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(file_input_output file_input_output.cpp)
target_include_directories(file_input_output PUBLIC ${CMAKE_SOURCE_DIR}/include)
