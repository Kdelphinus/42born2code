/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:28:27 by myko              #+#    #+#             */
/*   Updated: 2023/01/09 22:05:32 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	basic_sort_a(t_stack *stack, long long len, t_pivots *pivots)
{
	if (len <= 1)
		return ;
	else if (len == 2 \
	&& stack->a[stack->a_len - 1] > stack->a[stack->a_len - 2])
		s_order(stack, STACK_A);
	else if (len == 3)
		three_sort(stack, stack->a_len, pivots);
	else if (len > 3)
		other_sort(stack, len, pivots);
	return ;
}

void	basic_sort_b(t_stack *stack, long long len, t_pivots *pivots)
{
	if (len == 0)
		return ;
	else if (len == 1)
		p_order(stack, STACK_A, pivots);
	else if (len == 2)
	{
		if (stack->b[stack->b_len - 1] < stack->b[stack->b_len - 2])
			s_order(stack, STACK_B);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
	}
	else if (len == 3)
		three_reverse_sort(stack, stack->b_len, pivots);
	else if (len > 3)
		other_reverse_sort(stack, len, pivots);
	return ;
}

t_pivots	set_pivot(t_stack *stack, int goal, long long len)
{
	t_pivots	pivots;

	free(stack->arr);
	if (goal == STACK_A)
	{
		arr_init(stack, len, STACK_A);
		quick_sort(stack->arr, 0, stack->arr_len - 1);
	}
	else
	{
		arr_init(stack, len, STACK_B);
		quick_sort(stack->arr, 0, stack->arr_len - 1);
	}
	pivots.one = stack->arr[stack->arr_len * 2 / 3];
	pivots.two = stack->arr[stack->arr_len / 3];
	pivots.ra = 0;
	pivots.rb = 0;
	pivots.pa = 0;
	pivots.pb = 0;
	return (pivots);
}

void	o_pivot(t_stack *stack, t_pivots *pivots, int goal, long long len)
{
	free(stack->arr);
	if (goal == STACK_A)
		arr_init(stack, len, STACK_A);
	else
		arr_init(stack, len, STACK_B);
	quick_sort(stack->arr, 0, stack->arr_len - 1);
	if (stack->arr_len % 2)
		pivots->one = stack->arr[stack->arr_len / 2];
	else
		pivots->one = stack->arr[stack->arr_len / 2 - 1];
	pivots->two = 0;
	pivots->ra = 0;
	pivots->rb = 0;
	pivots->pa = 0;
	pivots->pb = 0;
}

int	is_sort(int *stack, int len)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack[i];
	while (++i < len)
	{
		if (stack[i] > tmp)
			return (0);
		tmp = stack[i];
	}
	return (1);
}
