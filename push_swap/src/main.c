/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:02 by myko              #+#    #+#             */
/*   Updated: 2022/12/20 21:18:43 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h> // TODO 스택 확인을 위한 헤더

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (stack_init2(argv, &stack))
			return (0);
	}
	else
	{
		if (stack_init1(argc, argv, &stack))
			return (0);
	}
	if (stack.a_len == 1)
		return (0);
	stack.b = (int *)malloc(sizeof(int) * stack.a_len);
	if (!stack.b)
		ft_error();
	stack.b_len = 0;

	// TODO 스택에 잘 들어왔는지 확인, 나중에 지우기
	for (int i = 0; i < stack.a_len; i++)
		printf("%d ", stack.a[i]);
	printf("\n");
	stack_sort(&stack);
	return (0);
}
