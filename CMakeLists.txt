cmake_minimum_required(VERSION 2.8)

project(Polly)

add_definitions(-Wall)

add_definitions(-std=gnu++11)

include_directories(include)

enable_testing()

set(SOURCES scr/stat.cpp)

add_executable(main test/test_stat.cpp ${SOURCES})

add_test(NAME ${PROJECT_NAME} COMMAND main)
