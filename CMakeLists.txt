cmake_minimum_required(VERSION 3.10.0)
project(rotate VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(src)
add_executable(rotate src/main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
