/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:34 by myko              #+#    #+#             */
/*   Updated: 2023/01/04 20:54:02 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three_sort(int *stack, long long len, t_pivots *pivots)
{
	len--;
	if (stack[len - 2] < stack[len - 1] && stack[len - 1] < stack[len])
	{
		s_order(stack, 3, STACK_A);
		rr_order(stack, 3, STACK_A);
	}
	else if (stack[len - 1] < stack[len] && stack[len] < stack[len - 2])
		s_order(stack, 3, STACK_A);
	else if (stack[len - 2] > stack[len - 1] && stack[len] > stack[len - 2])
		r_order(stack, 3, STACK_A, pivots);
	else if (stack[len - 2] < stack[len - 1] && stack[len - 2] > stack[len])
	{
		s_order(stack, 3, STACK_A);
		r_order(stack, 3, STACK_A, pivots);
	}
	else if (stack[len - 2] < stack[len] && stack[len] < stack[len - 1])
	{
		r_order(stack, len, STACK_A, pivots);
		s_order(stack, len, STACK_A);
		rr_order(stack, len, STACK_A);
		s_order(stack, len, STACK_A);
	}
}

void	three_reverse_sort(t_stack *stack, t_pivots *pivots)
{
	int	len;

	len = stack->b_len - 1;
	if (stack->b[len] > stack->b[len - 2] && stack->b[len - 2] > stack->b[len - 1])
	{
		p_order(stack, STACK_A, pivots);
		s_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
	}
	else if (stack->b[len - 2] > stack->b[len] && stack->b[len] > stack->b[len -1])
	{
		r_order(stack->b, stack->b_len, STACK_B, pivots);
		s_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
		rr_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
	}
	else if (stack->b[len - 1] > stack->b[len] && stack->b[len] > stack->b[len - 2])
	{
		s_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
	}
	else if (stack->b[len - 2] > stack->b[len - 1] && stack->b[len - 1] > stack->b[len])
	{
		r_order(stack->b, stack->b_len, STACK_B, pivots);
		s_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		rr_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
	}
	else if (stack->b[len - 1] > stack->b[len - 2] && stack->b[len - 2] > stack->b[len])
	{
		r_order(stack->b, stack->b_len, STACK_B, pivots);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		rr_order(stack->b, stack->b_len, STACK_B);
		p_order(stack, STACK_A, pivots);
	}
	else
	{
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
	}
}
