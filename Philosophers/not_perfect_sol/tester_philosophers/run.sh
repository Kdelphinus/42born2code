#!/bin/bash

source ./tester_philosophers/srcs_sh/const.sh

if [ "$#" -lt "4" ]; then
	printf "${YELLOW}Error: at least 4 arguments required\n"
	exit
fi

printf "${PROMPT} ${PHILO} $* | python3 ${DIR_PATH}/advanced_test.py $*\n"
$PHILO $* | python3 ${DIR_PATH}/advanced_test.py $*