#!/bin/bash

echo "Enter BUFFER_SIZE: "
read b_size

gcc -Wall -Wextra -Werror -g gnl_test_files/main.c get_next_line.c get_next_line_utils.c -I. get_next_line.h -D BUFFER_SIZE=$b_size

echo "<result>"
./a.out

