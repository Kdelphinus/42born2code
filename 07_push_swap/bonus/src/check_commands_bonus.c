/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:22:19 by myko              #+#    #+#             */
/*   Updated: 2023/01/10 17:05:50 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static void	run_command(char *str, t_stack *stack)
{
	if (ft_strncmp("sa\n", str, 3) == 0)
		s_command(stack->a, stack->a_len);
	else if (ft_strncmp("sb\n", str, 3) == 0)
		s_command(stack->b, stack->b_len);
	else if (ft_strncmp("ss\n", str, 3) == 0)
		double_command(stack, S_COMMAND);
	else if (ft_strncmp("pa\n", str, 3) == 0)
		p_command(stack, STACK_A);
	else if (ft_strncmp("pb\n", str, 3) == 0)
		p_command(stack, STACK_B);
	else if (ft_strncmp("ra\n", str, 3) == 0)
		r_command(stack->a, stack->a_len);
	else if (ft_strncmp("rb\n", str, 3) == 0)
		r_command(stack->b, stack->b_len);
	else if (ft_strncmp("rr\n", str, 3) == 0)
		double_command(stack, R_COMMAND);
	else if (ft_strncmp("rra\n", str, 4) == 0)
		rr_command(stack->a, stack->a_len);
	else if (ft_strncmp("rrb\n", str, 4) == 0)
		rr_command(stack->b, stack->b_len);
	else if (ft_strncmp("rrr\n", str, 4) == 0)
		double_command(stack, RR_COMMAND);
	else
		ft_error_checker();
}

void	check_commands(t_stack *stack)
{
	char	*str;

	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
			break ;
		run_command(str, stack);
		free(str);
	}
	free(str);
}
