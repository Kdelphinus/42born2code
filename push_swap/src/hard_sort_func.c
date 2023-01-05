/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:34 by myko              #+#    #+#             */
/*   Updated: 2023/01/05 20:12:09 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three_sort(t_stack *stack, long long len, t_pivots *pivots)
{
	len--;
	if (stack->a[len - 2] < stack->a[len - 1] \
	&& stack->a[len - 1] < stack->a[len])
	{
		p_order(stack, STACK_B, pivots);
		s_order(stack->a, stack->a_len, STACK_A);
		r_order(stack->a, stack->a_len, STACK_A, pivots);
		r_order(stack->a, stack->a_len, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		rr_order(stack->a, stack->a_len, STACK_A);
		rr_order(stack->a, stack->a_len, STACK_A);
	}
	else if (stack->a[len - 1] < stack->a[len] \
	&& stack->a[len] < stack->a[len - 2])
		s_order(stack->a, stack->a_len, STACK_A);
	else if (stack->a[len - 2] > stack->a[len - 1] \
	&& stack->a[len] > stack->a[len - 2])
	{
		p_order(stack, STACK_B, pivots);
		r_order(stack->a, stack->a_len, STACK_A, pivots);
		r_order(stack->a, stack->a_len, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		rr_order(stack->a, stack->a_len, STACK_A);
		rr_order(stack->a, stack->a_len, STACK_A);
	}
	else if (stack->a[len - 2] < stack->a[len - 1] \
	&& stack->a[len - 2] > stack->a[len])
	{
		r_order(stack->a, stack->a_len, STACK_A, pivots);
		s_order(stack->a, stack->a_len, STACK_A);
		rr_order(stack->a, stack->a_len, STACK_A);
	}
	else if (stack->a[len - 2] < stack->a[len] \
	&& stack->a[len] < stack->a[len - 1])
	{
		r_order(stack->a, len, STACK_A, pivots);
		r_order(stack->a, len, STACK_A, pivots);
		p_order(stack, STACK_B, pivots);
		rr_order(stack->a, stack->a_len, STACK_A);
		rr_order(stack->a, stack->a_len, STACK_A);
		p_order(stack, STACK_A, pivots);
	}
}

void	three_reverse_sort(t_stack *stack, long long len, t_pivots *pivots)
{
	len--;
	if (stack->b[len] > stack->b[len - 2] \
	&& stack->b[len - 2] > stack->b[len - 1])
	{
		p_order(stack, STACK_A, pivots);
		s_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
	}
	else if (stack->b[len - 2] > stack->b[len] \
	&& stack->b[len] > stack->b[len -1])
	{
		r_order(stack->b, stack->b_len, STACK_B, pivots);
		s_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
		rr_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
	}
	else if (stack->b[len - 1] > stack->b[len] \
	&& stack->b[len] > stack->b[len - 2])
	{
		s_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
	}
	else if (stack->b[len - 2] > stack->b[len - 1] \
	&& stack->b[len - 1] > stack->b[len])
	{
		r_order(stack->b, stack->b_len, STACK_B, pivots);
		s_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		rr_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
	}
	else if (stack->b[len - 1] > stack->b[len - 2] \
	&& stack->b[len - 2] > stack->b[len])
	{
		r_order(stack->b, stack->b_len, STACK_B, pivots);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		rr_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
	}
	else if (stack->b[len - 2] < stack->b[len - 1] \
	&& stack->b[len - 1] < stack->b[len])
	{
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
	}
}
