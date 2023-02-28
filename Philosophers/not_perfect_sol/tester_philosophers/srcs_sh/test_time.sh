#!/bin/bash

SRCS_DIR=$(dirname $0)
source ${SRCS_DIR}/const.sh
. ${SRCS_DIR}/print_result.sh

clonology_test (){
	printf "${CYAN}[${FUNCNAME[0]}]${RESET}\n"
	for arg in "${ARGS[@]}"; do
		printf "${PROMPT} ${PHILO} ${arg}\n"
		$PHILO $arg > $LOG_FILE
		if [ $? == 139 ]; then
			printf "${RED}KO :( [Crash!] ${RESET}\n"
		else
			grep "\x1b" $LOG_FILE > /dev/null
			if [ $? == 0 ]; then
				printf "${YELLOW}Color log format is not supported for this test.${RESET}\n"
				exit 1
			fi
			diff <( cat $LOG_FILE | awk '{print$1}' | sort -n) <(cat $LOG_FILE | awk '{print$1}')
			print_result $?
		fi
	done
	printf "\n"

}

chmod a+rwx $LOG_FILE
clonology_test
