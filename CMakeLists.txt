cmake_minimum_required(VERSION 3.6)
project(lem_in)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.cpp src/part1.c src/part2.c)
file(GLOB SOURCE_FILES "./src/*.c" "./includes/*.h" "./Lib/src/ft_printf/*.c"
        "./Lib/src/get_next_line/*.c" "./Lib/src/libft/*.c")
add_executable(lem_in ${SOURCE_FILES})
target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/Lib/big_libft.a)
