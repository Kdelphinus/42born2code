/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:02 by myko              #+#    #+#             */
/*   Updated: 2022/12/27 07:22:49 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

0 1 2
-----
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

static int	hard_sort(t_stack *stack)
{
	if (stack->a_len == 2)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	else
	{
		if (stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2])
		{
			ft_putstr_fd("ra\n", STDOUT_FILENO);
			ft_putstr_fd("ra\n", STDOUT_FILENO);
		}
		else if (stack->a[0] > stack->a[1])
		{}
	}
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
