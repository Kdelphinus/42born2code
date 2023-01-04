/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:28:27 by myko              #+#    #+#             */
/*   Updated: 2023/01/04 13:08:48 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	basic_sort_a(t_stack *stack, int len)
{
	if (len <= 1)
		return ;
	if (len == 2 && stack->a[stack->a_len - 1] > stack->a[stack->a_len - 2])
		s_order(stack->a, stack->a_len, STACK_A);
	if (len == 3)
		three_sort(stack->a, 3);
	return ;
}

void	basic_sort_b(int len, t_stack *stack, t_pivots *pivots)
{
	if (len == 0)
		return ;
	else if (len == 1)
	{
		p_order(stack, STACK_A, pivots);
		return ;
	}
	else if (stack->b[stack->b_len - 1] < stack->b[stack->b_len - 2])
		s_order(stack->b, stack->b_len, STACK_B);
	p_order(stack, STACK_A, pivots);
	p_order(stack, STACK_A, pivots);
	return ;
}

t_pivots	set_pivot(t_stack *stack, int goal)
{
	t_pivots	pivots;

	free(stack->arr);
	if (goal == STACK_A)
	{
		arr_init(stack, stack->a_len, STACK_A);
		quick_sort(stack->arr, 0, stack->a_len - 1);
	}
	else
	{
		arr_init(stack, stack->b_len, STACK_B);
		quick_sort(stack->arr, 0, stack->b_len - 1);
	}
	pivots.one = stack->arr[stack->arr_len * 2 / 3];
	pivots.two = stack->arr[stack->arr_len / 3];
	pivots.ra = 0;
	pivots.rb = 0;
	pivots.pa = 0;
	pivots.pb = 0;
	return (pivots);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
