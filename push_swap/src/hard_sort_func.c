/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:34 by myko              #+#    #+#             */
/*   Updated: 2023/01/04 13:12:40 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three_sort(int *stack, int len)
{
	len--;
	if (stack[len - 2] < stack[len - 1] && stack[len - 1] < stack[len])
	{
		s_order(stack, len, STACK_A);
		rr_order(stack, len, STACK_A);
	}
	else if (stack[len - 1] < stack[len] && stack[len] < stack[len - 2])
		s_order(stack, len, STACK_A);
	else if (stack[len - 2] > stack[len - 1] && stack[len] > stack[len - 2])
		r_order(stack, len, STACK_A, NULL);
	else if (stack[len - 2] < stack[len - 1] && stack[len - 2] > stack[len])
	{
		s_order(stack, len, STACK_A);
		r_order(stack, len, STACK_A, NULL);
	}
	else if (stack[len - 2] < stack[len] && stack[len] < stack[len - 1])
		rr_order(stack, len, STACK_A);
}

void	four_sort(int *stack, int len)
{
	(void)stack;
	len--;
}
