/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:11:40 by myko              #+#    #+#             */
/*   Updated: 2022/12/27 00:07:30 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	basic_sort_a(int *sta, int len)
{
	if (len > 1 && sta[len - 1] > sta[len - 2])
		s_order(sta, len, STACK_A);
	return ;
}

static void	basic_sort_b(t_stack *stack)
{
	if (stack->b_len == 1)
	{
		p_order(stack, STACK_A);
		return ;
	}
	if (stack->b[stack->b_len - 1] < stack->b[stack->b_len - 2])
		s_order(stack->b, stack->b_len, STACK_B);
	p_order(stack, STACK_A);
	p_order(stack, STACK_A);
	return ;
}

static t_pivots	set_pivot(t_stack *stack, int goal)
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
	pivots.p = 0;
	return (pivots);
}

static int	min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

void	a_to_b(t_stack *stack, int r)
{
	int			i;
	t_pivots	pivots;

	if (r < 3)
	{
		basic_sort_a(stack->a, stack->a_len);
		return ;
	}
	pivots = set_pivot(stack, STACK_A);
	while (r--)
	{
		if (stack->a[stack->a_len - 1] >= pivots.two)
		{
			r_order(stack->a, stack->a_len, STACK_A);
			pivots.ra++;
		}
		else
		{
			p_order(stack, STACK_B);
			pivots.p++;
			if (stack->b[stack->b_len - 1] >- pivots.one)
			{
				r_order(stack->b, stack->b_len, STACK_B);
				pivots.rb++;
			}
		}
	}
	i = -1;
	while (++i < min(pivots.ra, pivots.rb))
		double_order(stack, RR_ORDER);
	i = -1;
	while (++i < pivots.rb - pivots.ra)
		rr_order(stack->b, stack->b_len, STACK_B);
	i = -1;
	while (++i < pivots.ra - pivots.rb)
		rr_order(stack->a, stack->a_len, STACK_A);
	a_to_b(stack, pivots.ra);
	b_to_a(stack, pivots.rb);
	b_to_a(stack, pivots.p - pivots.rb);
}

void	b_to_a(t_stack *stack, int r)
{
	int			i;
	t_pivots	pivots;

	if (r < 3)
	{
		basic_sort_b(stack);
		return ;
	}
	pivots = set_pivot(stack, STACK_B);
	while (r--)
	{
		if (stack->b[stack->b_len - 1] < pivots.one)
		{
			r_order(stack->b, stack->b_len, STACK_B);
			pivots.rb++;
		}
		else
		{
			p_order(stack, STACK_A);
			pivots.p++;
			if (stack->a[stack->a_len - 1] < pivots.two)
			{
				r_order(stack->a, stack->a_len, STACK_A);
				pivots.ra++;
			}
		}
	}
	a_to_b(stack, pivots.p - pivots.ra);
	i = -1;
	while (++i < min(pivots.ra, pivots.rb))
		double_order(stack, RR_ORDER);
	i = -1;
	while (++i < pivots.rb - pivots.ra)
		rr_order(stack->b, stack->b_len, STACK_B);
	i = -1;
	while (++i < pivots.ra - pivots.rb)
		rr_order(stack->a, stack->a_len, STACK_A);
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
