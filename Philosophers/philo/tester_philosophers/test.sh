#!/bin/bash

source ./tester_philosophers/srcs_sh/const.sh

rm -f ${DIR_PATH}/logs/tester_log

make

single_bash_test (){
	printf "${CYAN}-------------${1}--------------${RESET}\n"
	file="${SRCS_DIR}/${1}.sh"
	$file 2> /dev/null
}

all_bash_tests (){
	for test in ${TESTS[@]}; do
		single_bash_test $test
	done
}

python_test (){
	test=advanced_test
	file="${DIR_PATH}/${test}.py"
	printf "${CYAN}-------------${test}--------------${RESET}\n"
	for arg in "${ARGS[@]}"; do
		printf "${PROMPT} ${PHILO} ${arg}${RESET}\n"
		$PHILO $arg | python3 $file $arg
	done
}

print_help (){
	printf "${CYAN}Call test.sh with a cmd arg to exec single test\n${RESET}"
	for test in ${TESTS[@]}; do
		printf "$test: ./test.sh ${test:5:10}\n"
	done
	printf "advanced_test: ./test.sh advanced\n"
}


if [ -e $1 ]; then
	all_bash_tests
	python_test
elif [ "$1" == "help" ]; then
	print_help
elif [ "$1" == "advanced" ]; then
	python_test
elif [ "$1" ]; then
	single_bash_test "test_${1}"
fi