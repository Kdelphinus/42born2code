# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    norm.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/15 22:04:33 by mfunyu            #+#    #+#              #
#    Updated: 2021/08/15 22:12:35 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

THICK="\033[1m"
CYAN="\033[1;36m"
RED="\033[31m"
GREEN="\033[32m"
RESET="\033[m"
PROMPT="${CYAN}$>${RESET} "

printf "${PROMPT} norminette | grep -v \": OK!\"${RESET}\n"
norminette | grep -v ": OK!"
if [ $? == 1 ] ; then
	printf "${GREEN}Norm OK :)${RESET}\n"
else
	printf "${RED}Norm KO :(${RESET}\n"
fi

