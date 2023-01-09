/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:59:38 by myko              #+#    #+#             */
/*   Updated: 2023/01/09 19:32:47 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	is_sort_checker(t_stack *stack)
{
	int			tmp;
	long long	len;

	if (stack->b_len)
		return (NOT_SORT);
	len = 0;
	tmp = stack->a[0];
	while (++len < stack->a_len)
	{
		if (tmp < stack->a[len])
			return (NOT_SORT);
		tmp = stack->a[len];
	}
	return (SORT);
}

static int	check_sort(t_stack *stack)
{
	int	flag;

	stack->b = (int *)malloc(sizeof(int) * stack->a_len);
	if (!stack->b)
		ft_error_checker();
	stack->b_len = 0;
	check_commands(stack);
	flag = is_sort_checker(stack);
	free(stack->arr);
	free(stack->b);
	free(stack->a);
	return (flag);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	if (argc == 2)
		stack_init_checker2(argv, &stack);
	else
		stack_init_checker1(argc, argv, &stack);
	arr_init_checekr(&stack, stack.a_len, STACK_A);
	quick_sort_checker(stack.arr, 0, stack.arr_len - 1);
	if (is_duplication_checker(stack.arr, stack.arr_len))
		ft_error_checker();
	if (check_sort(&stack) == SORT)
		return (print_ok());
	return (print_ko());
}
