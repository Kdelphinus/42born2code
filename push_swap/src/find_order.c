/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:11:40 by myko              #+#    #+#             */
/*   Updated: 2023/01/05 16:46:19 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_stack(t_stack *stack, t_pivots *pivots)
{
	int	i;

	i = -1;
	while (++i < min(pivots->ra, pivots->rb))
		double_order(stack, RR_ORDER, pivots);
	i = -1;
	while (++i < pivots->rb - pivots->ra)
		rr_order(stack->b, stack->b_len, STACK_B);
	i = -1;
	while (++i < pivots->ra - pivots->rb)
		rr_order(stack->a, stack->a_len, STACK_A);
}

void	a_to_b(t_stack *stack, long long r)
{
	t_pivots	pivots;

	if (is_sort(stack->a, stack->a_len))
		return ;
	pivots = set_pivot(stack, STACK_A, r);
	if (r <= 5)
	{
		basic_sort_a(stack, r, &pivots);
		return ;
	}
	while (--r >= 0)
	{
		if (stack->a[stack->a_len - 1] >= pivots.two)
			r_order(stack->a, stack->a_len, STACK_A, &pivots);
		else
		{
			p_order(stack, STACK_B, &pivots);
			if (stack->b[stack->b_len - 1] >= pivots.one)
				r_order(stack->b, stack->b_len, STACK_B, &pivots);
		}
	}
	reverse_stack(stack, &pivots);
	a_to_b(stack, pivots.ra);
	b_to_a(stack, pivots.rb);
	b_to_a(stack, pivots.pb - pivots.rb);
}

void	b_to_a(t_stack *stack, long long r)
{
	t_pivots	pivots;

	pivots = set_pivot(stack, STACK_B, r);
	if (r <= 5)
	{
		basic_sort_b(stack, r, &pivots);
		return ;
	}
	while (--r >= 0)
	{
		if (stack->b[stack->b_len - 1] < pivots.one)
			r_order(stack->b, stack->b_len, STACK_B, &pivots);
		else
		{
			p_order(stack, STACK_A, &pivots);
			if (stack->a[stack->a_len - 1] < pivots.two)
				r_order(stack->a, stack->a_len, STACK_A, &pivots);
		}
	}
	a_to_b(stack, pivots.pa - pivots.ra);
	reverse_stack(stack, &pivots);
	a_to_b(stack, pivots.ra);
	b_to_a(stack, pivots.rb);
}

void	find_order(t_stack *stack)
{
	stack->b = (int *)malloc(sizeof(int) * stack->a_len);
	if (!stack->b)
		ft_error();
	stack->b_len = 0;
	a_to_b(stack, stack->a_len);
}
