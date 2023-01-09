/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:58:44 by myko              #+#    #+#             */
/*   Updated: 2023/01/09 22:19:16 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_order(t_stack *stack, int flag)
{
	long long	tmp;

	if (flag == STACK_A && stack->a_len > 1)
	{
		tmp = stack->a[stack->a_len - 1];
		stack->a[stack->a_len - 1] = stack->a[stack->a_len - 2];
		stack->a[stack->a_len - 2] = tmp;
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		tmp = stack->b[stack->b_len - 1];
		stack->b[stack->b_len - 1] = stack->b[stack->b_len - 2];
		stack->b[stack->b_len - 2] = tmp;
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	}
}

void	p_order(t_stack *stack, int goal, t_pivots *pivots)
{
	int	tmp;

	if (goal == STACK_A)
		pivots->pa++;
	else if (goal == STACK_B)
		pivots->pb++;
	if (goal == STACK_A && stack->b_len > 0)
	{
		tmp = stack->b[stack->b_len - 1];
		stack->b_len--;
		stack->a[stack->a_len] = tmp;
		stack->a_len++;
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
	else if (goal == STACK_B && stack->a_len > 0)
	{
		tmp = stack->a[stack->a_len - 1];
		stack->a_len--;
		stack->b[stack->b_len] = tmp;
		stack->b_len++;
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
}

void	r_order(t_stack *stack, int flag, t_pivots *pivots)
{
	long long	i;
	int			tmp;

	if (flag == STACK_A)
	{
		pivots->ra++;
		if (stack->a_len > 1)
		{
			i = stack->a_len - 1;
			tmp = stack->a[i];
			while (--i >= 0)
				stack->a[i + 1] = stack->a[i];
			stack->a[0] = tmp;
			ft_putstr_fd("ra\n", STDOUT_FILENO);
		}
	}
	else if (flag == STACK_B)
	{
		pivots->rb++;
		if (stack->b_len > 1)
		{
			i = stack->b_len - 1;
			tmp = stack->b[i];
			while (--i >= 0)
				stack->b[i + 1] = stack->b[i];
			stack->b[0] = tmp;
			ft_putstr_fd("rb\n", STDOUT_FILENO);
		}
	}
}

void	rr_order(t_stack *stack, int flag)
{
	long long	i;
	int			tmp;

	i = -1;
	if (flag == STACK_A && stack->a_len > 1)
	{
		tmp = stack->a[0];
		while (++i < stack->a_len - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[stack->a_len - 1] = tmp;
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		tmp = stack->b[0];
		while (++i < stack->b_len - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[stack->b_len - 1] = tmp;
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	}
}

void	double_order(t_stack *stack, int order, t_pivots *pivots)
{
	if (order == S_ORDER)
	{
		s_order(stack, STACK_A);
		s_order(stack, STACK_B);
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	}
	else if (order == R_ORDER)
	{
		r_order(stack, STACK_A, pivots);
		r_order(stack, STACK_B, pivots);
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	}
	else if (order == RR_ORDER)
	{
		rr_order(stack, STACK_A);
		rr_order(stack, STACK_B);
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
	}
}
