/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:58:44 by myko              #+#    #+#             */
/*   Updated: 2023/01/05 21:55:50 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	s_order(int *stack, long long len, int flag)
{
	long long	tmp;

	if (len > 1)
	{
		tmp = stack[len - 1];
		stack[len - 1] = stack[len - 2];
		stack[len - 2] = tmp;
		if (flag == STACK_A)
			ft_putstr_fd("sa\n", STDOUT_FILENO);
		else if (flag == STACK_B)
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

void	r_order(int *stack, long long len, int flag, t_pivots *pivots)
{
	long long	i;
	int			tmp;

	i = len - 1;
	if (len > 1)
	{
		tmp = stack[len - 1];
		while (--i >= 0)
			stack[i + 1] = stack[i];
		stack[0] = tmp;
	}
	if (flag == STACK_A)
	{
		if (len > 1)
			ft_putstr_fd("ra\n", STDOUT_FILENO);
		pivots->ra++;
	}
	else if (flag == STACK_B)
	{
		if (len > 1)
			ft_putstr_fd("rb\n", STDOUT_FILENO);
		pivots->rb++;
	}
}

void	rr_order(int *stack, long long len, int flag)
{
	long long	i;
	int			tmp;

	if (len <= 1)
		return ;
	i = -1;
	tmp = stack[0];
	while (++i < len - 1)
		stack[i] = stack[i + 1];
	stack[len - 1] = tmp;
	if (flag == STACK_A)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	else if (flag == STACK_B)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	double_order(t_stack *stack, int order, t_pivots *pivots)
{
	if (order == S_ORDER)
	{
		s_order(stack->a, stack->a_len, DOUBLE_ORDER);
		s_order(stack->b, stack->b_len, DOUBLE_ORDER);
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	}
	else if (order == R_ORDER)
	{
		r_order(stack->a, stack->a_len, DOUBLE_ORDER, pivots);
		r_order(stack->b, stack->b_len, DOUBLE_ORDER, pivots);
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	}
	else if (order == RR_ORDER)
	{
		rr_order(stack->a, stack->a_len, DOUBLE_ORDER);
		rr_order(stack->b, stack->b_len, DOUBLE_ORDER);
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
	}
}
