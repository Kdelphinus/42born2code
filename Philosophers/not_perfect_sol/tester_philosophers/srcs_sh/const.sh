#!/bin/bash

DIR_PATH=./tester_philosophers
SRCS_DIR=${DIR_PATH}/srcs_sh

TESTS=(
"test_arg"
"test_time"
"test_retval"
)

PHILO=./philo

LOG_FILE=${DIR_PATH}/logs/log
TMP_FILE=${DIR_PATH}/logs/tmp

# define
THICK="\033[1m"
CYAN="\033[1;36m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
RESET="\033[m"
PROMPT="${CYAN}$>${RESET}"

ARGS=(
"3 200 400 800"
"3 600 400 100"
"3 800 400 100"
"4 600 350 100"
"4 390 200 200"
"5 800 400 100"
"15 200 400 800"
"200 390 200 200"
)

ERR_CHECK=(
""
"0 0 0 0"
"1 1 1 -1"
"-10 60 60 120"
"1"
"-1234"
"1 1 1"
"1 1 1 1 1 1"
"aaa 1 2 3"
"1 aaa 2 3 4"
"2147483648"
"-2147483649"
"1000000000000000000"
"0.001 1.25 123 567 8"
"aaa bbb ccc ddd eee"
"42424242424242Tokyo"
)