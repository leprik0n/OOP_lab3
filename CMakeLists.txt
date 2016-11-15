cmake_minimum_required(VERSION 2.8)

project(Vector CXX)

if (MSVC)
    add_definitions(/W4)
else()
    add_definitions(-Wall)
    add_definitions(-std=c++11)
endif()

include_directories(include)

enable_testing()

set(SOURCES scr/stat.cpp)

add_executable(test_ test/test_stat.cpp ${SOURCES})

add_test(NAME ${PROJECT_NAME} COMMAND test_)
