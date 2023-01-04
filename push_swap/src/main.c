/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:02 by myko              #+#    #+#             */
/*   Updated: 2023/01/04 13:10:14 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	hard_sort(t_stack *stack)
{
	if (stack->a_len == 2)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	else if (stack->a_len == 3)
		three_sort(stack->a, 3);
	else if (stack->a_len == 4)
		four_sort(stack->a, 4);
	return (0);
}

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
	if (stack.a_len < 4)
		return (hard_sort(&stack));
	else
		find_order(&stack);
	return (0);
}
