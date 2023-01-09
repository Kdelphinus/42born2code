/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_func_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:29:36 by myko              #+#    #+#             */
/*   Updated: 2023/01/09 22:04:45 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three_hard_sort(t_stack *stack, t_pivots *pivots)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2])
	{
		s_order(stack, STACK_A);
		rr_order(stack, STACK_A);
	}
	else if (stack->a[1] < stack->a[2] && stack->a[2] < stack->a[0])
		s_order(stack, STACK_A);
	else if (stack->a[0] > stack->a[1] && stack->a[2] > stack->a[0])
		r_order(stack, STACK_A, pivots);
	else if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2])
	{
		s_order(stack, STACK_A);
		r_order(stack, STACK_A, pivots);
	}
	else if (stack->a[0] < stack->a[2] && stack->a[2] < stack->a[1])
		rr_order(stack, STACK_A);
}

void	four_hard_sort(t_stack *stack, long long len, t_pivots *pivots)
{
	o_pivot(stack, pivots, STACK_A, len);
	while (--len >= 0 && pivots->pb < 2)
	{
		if (stack->a[stack->a_len - 1] >= pivots->one)
			r_order(stack, STACK_A, pivots);
		else
			p_order(stack, STACK_B, pivots);
	}
	basic_sort_a(stack, 2, pivots);
	basic_sort_b(stack, 2, pivots);
}

void	five_hard_sort(t_stack *stack, long long len, t_pivots *pivots)
{
	o_pivot(stack, pivots, STACK_A, len);
	while (--len >= 0 && pivots->pb < 2)
	{
		if (stack->a[stack->a_len - 1] >= pivots->one)
			r_order(stack, STACK_A, pivots);
		else
			p_order(stack, STACK_B, pivots);
	}
	three_hard_sort(stack, pivots);
	basic_sort_b(stack, pivots->pb, pivots);
}
