/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:58:44 by myko              #+#    #+#             */
/*   Updated: 2023/01/06 18:49:53 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	s_command(int *stack, long long len)
{
	long long	tmp;

	if (len > 1)
	{
		tmp = stack[len - 1];
		stack[len - 1] = stack[len - 2];
		stack[len - 2] = tmp;
	}
}

void	p_command(t_stack *stack, int goal)
{
	int	tmp;

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

void	r_command(int *stack, long long len)
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
}

void	rr_command(int *stack, long long len)
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
}

void	double_command(t_stack *stack, int command)
{
	if (command == S_COMMAND)
	{
		s_command(stack->a, stack->a_len);
		s_command(stack->b, stack->b_len);
	}
	else if (command == R_COMMAND)
	{
		r_command(stack->a, stack->a_len);
		r_command(stack->b, stack->b_len);
	}
	else if (command == RR_COMMAND)
	{
		rr_command(stack->a, stack->a_len);
		rr_command(stack->b, stack->b_len);
	}
}
