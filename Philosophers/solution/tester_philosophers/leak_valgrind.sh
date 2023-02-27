#!/bin/bash

source ./tester_philosophers/srcs_sh/const.sh
. ./tester_philosophers/srcs_sh/print_result.sh

ARGS=(
"3 200 400 800"
"3 600 400 100"
"3 800 400 100"
"4 600 350 100"
"5 800 400 100"
"15 200 400 800"
"200 370 200 200"
"4 310 200 100"
"2 200 100 100"
"2 120 60 60"
"2 121 60 60"
"2 510 250 250 20"
"2 100 60 100000000"
"2 0 100 100"
"10 100 100 100 0"
"10 100 0 110"
"10 100 100 0"
"-1 100 100 100"
"10.1 100 100 100"
"10aa 100 100 100"
"10 100 100 100 -1"
)

sum=0
for arg in "${ARGS[@]}"; do
	printf "${PROMPT} valgrind --leak-check=full ${PHILO} ${arg} 2>&1 | grep -A2 \"LEAK SUMMARY:\"\n"
	valgrind --leak-check=full ${PHILO} ${arg} 2>&1 | grep -A2 "LEAK SUMMARY:"
	diff <(valgrind --leak-check=full ${PHILO} ${arg} 2>&1 | grep -A2 "LEAK SUMMARY:" | awk '{print$2$3$4$5}') \
		<(printf "LEAKSUMMARY:\ndefinitelylost:0bytes\nindirectlylost:0bytes\n")
	ret=$?
	print_result $ret
	sum=$(($sum + $ret)) 
done
printf "\n${CYAN}===LEAK SUMMERY===\n${RESET}"
print_result $sum

