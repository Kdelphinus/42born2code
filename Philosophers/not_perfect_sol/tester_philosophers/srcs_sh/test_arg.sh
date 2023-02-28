#!/bin/bash

SRCS_DIR=$(dirname $0)
source ${SRCS_DIR}/const.sh
. ${SRCS_DIR}/print_result.sh

normal_test (){
	printf "${CYAN}[${FUNCNAME[0]}]${RESET}\n"
	for arg in "${ARGS[@]}"; do
		printf "${PROMPT} ${PHILO} ${arg}\n"
		$PHILO $arg > /dev/null
		print_result $?
	done
	printf "\n"
}

arg_error_test (){
	printf "${CYAN}[${FUNCNAME[0]}]${RESET}\n"
	for arg in "${ERR_CHECK[@]}"; do
		printf "${PROMPT} ${PHILO} ${arg}\n"
		$PHILO $arg
		print_result $? 1
	done
	printf "\n"
}


arg_error_test
normal_test