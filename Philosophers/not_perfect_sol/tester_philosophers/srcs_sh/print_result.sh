#!/bin/bash

function print_result (){
	if [ $2 ] && [ $2 == $1 ]; then
		printf "${GREEN}OK :) ${RESET}\n"
	elif [ $1 == 0 ]; then
		printf "${GREEN}OK :) ${RESET}\n"
	elif [ $1 == 139 ]; then
		printf "${RED}KO :( [Crash!] ${RESET}\n"
	elif [ $1 == 134 ]; then
		printf "${RED}KO :( [Abort!] ${RESET}\n"
	else
		echo -n "$1: "
		printf "${RED}KO :(${RESET}\n"
	fi
}