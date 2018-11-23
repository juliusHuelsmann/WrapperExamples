cmake_minimum_required(VERSION 3.5)
project(wrapperMutex LANGUAGES C CXX VERSION 0.0.0.1)

add_executable(${PROJECT_NAME} main.cc)
target_include_directories(${PROJECT_NAME} PRIVATE ../shared)
target_link_libraries(${PROJECT_NAME} Wrapper::Wrapper)

