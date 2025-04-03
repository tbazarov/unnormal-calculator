cmake_minimum_required(VERSION 3.10)
project(NumberSystemAdderTests)

find_package(GTest REQUIRED)
include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

set(TEST_SOURCES
    test_main.cpp
    test_number_converter.cpp
    test_input_parser.cpp
)

add_executable(runTests ${TEST_SOURCES})

target_link_libraries(runTests 
    ${GTEST_LIBRARIES}
    ${CMAKE_SOURCE_DIR}/src/NumberSystemConverter.cpp
    ${CMAKE_SOURCE_DIR}/src/InputParser.cpp
    pthread
)

add_test(NAME NumberSystemAdderTests COMMAND runTests)