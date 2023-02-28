/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:22:15 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/05 22:59:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void	leak_checker(void)__attribute__((destructor));

void	leak_checker(void)
{
	int		status;

	status = system("leaks -q philo");
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
		fprintf(stderr, "%sOK! No memory leaks :)%s\n", GREEN, RESET);
	}
	else if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
	{
		fprintf(stderr, "%sKO! Memory leak detected :(%s\n", RED, RESET);
	}
	else
		fprintf(stderr, "%sdestructor error ;)%s\n", YELLOW, RESET);
}
