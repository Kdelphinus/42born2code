/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:02 by myko              #+#    #+#             */
/*   Updated: 2022/12/27 01:27:20 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	arr_init(&stack, stack.a_len, STACK_A);
	quick_sort(stack.arr, 0, stack.a_len - 1);
	if (is_duplication(stack.arr, stack.a_len))
		ft_error();
	find_order(&stack);
	return (0);
}
