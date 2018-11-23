cmake_minimum_required(VERSION 3.5)
project(wrapperExamples LANGUAGES C CXX VERSION 0.0.0.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Wall -pedantic -Werror -g")

add_subdirectory(vendor/wrapper)
add_subdirectory(examples)


