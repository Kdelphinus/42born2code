cmake_minimum_required(VERSION 3.12)
project(philo VERSION 0.1.0)

set(CMAKE_C_STANDARD 99)

file(GLOB PROJ_SRC "src/*.c")
add_executable(philo ${PROJ_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
include(CPack)