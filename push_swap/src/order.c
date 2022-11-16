/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:58:44 by myko              #+#    #+#             */
/*   Updated: 2022/11/16 21:38:22 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_order(long long *stack, long long len)
{
	long long	tmp;

	if (len > 1)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}

void	p_order(t_stack *stack, long long goal)
{
	long long	tmp;

	if (goal == STACK_A && stack->b_len > 0)
	{
		tmp = stack->b[stack->b_len - 1];
		stack->b_len--;
		stack->a[stack->a_len] = tmp;
		stack->a_len++;
	}
	else if (goal == STACK_B && stack->a_len > 0)
	{
		tmp = stack->a[stack->a_len - 1];
		stack->a_len--;
		stack->b[stack->b_len] = tmp;
		stack->b_len++;
	}
}

void	r_order(long long *stack, long long len)
{
	long long	i;
	long long	tmp;

	i = -1;
	if (len > 2)
	{
		tmp = stack[0];
		while (++i < len - 1)
			stack[i] = stack[i + 1];
		stack[len - 1] = tmp;
	}
}

void	rr_order(long long *stack, long long len)
{
	long long	i;
	long long	tmp;

	i = -1;
	if (len > 2)
	{
		tmp = stack[len - 1];
		while (++i < len - 1)
			stack[i + 1] = stack[i];
		stack[0] = tmp;
	}
}
