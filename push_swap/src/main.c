/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:02 by myko              #+#    #+#             */
/*   Updated: 2023/01/09 15:00:34 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	p_sort(t_stack *stack)
{
	t_pivots	pivots;

	pivots = set_pivot(stack, STACK_A, stack->a_len);
	stack->b = (int *)malloc(sizeof(int) * stack->a_len);
	if (!stack->b)
		ft_error();
	stack->b_len = 0;
	if (stack->a_len == 2)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	else if (stack->a_len == 3)
		three_hard_sort(stack, &pivots);
	else if (stack->a_len == 4)
		four_hard_sort(stack, 4, &pivots);
	else if (stack->a_len == 5)
		five_hard_sort(stack, 5, &pivots);
	else
		a_to_b(stack, stack->a_len);
	free(stack->arr);
	free(stack->b);
	free(stack->a);
}

int	main(int argc, char **argv)
{
	int		flag;
	t_stack	stack;

	if (argc == 1)
		return (0);
	if (argc == 2)
		flag = stack_init2(argv, 1, &stack);
	else
		flag = stack_init1(argc, argv, &stack);
	if (stack.a_len == 1 || flag)
	{
		free(stack.a);
		return (0);
	}
	arr_init(&stack, stack.a_len, STACK_A);
	quick_sort(stack.arr, 0, stack.arr_len - 1);
	if (is_duplication(stack.arr, stack.arr_len))
		ft_error();
	p_sort(&stack);
	return (0);
}
