cmake_minimum_required(VERSION 3.12)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Werror -Wextra)
include_directories(./include)
link_directories(./lib)
link_libraries(ft)
file(GLOB PROJ_SRC src/*.c)
add_executable(push_swap ${PROJ_SRC})
