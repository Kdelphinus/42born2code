/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_func_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:34 by myko              #+#    #+#             */
/*   Updated: 2023/01/05 20:29:37 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three_sort(t_stack *stack, long long len, t_pivots *pivots)
{
	len--;
	if (stack->a[len - 2] < stack->a[len - 1] \
	&& stack->a[len - 1] < stack->a[len])
		case_one(stack, pivots);
	else if (stack->a[len - 1] < stack->a[len] \
	&& stack->a[len] < stack->a[len - 2])
		case_two(stack);
	else if (stack->a[len - 2] > stack->a[len - 1] \
	&& stack->a[len] > stack->a[len - 2])
		case_three(stack, pivots);
	else if (stack->a[len - 2] < stack->a[len - 1] \
	&& stack->a[len - 2] > stack->a[len])
		case_four(stack, pivots);
	else if (stack->a[len - 2] < stack->a[len] \
	&& stack->a[len] < stack->a[len - 1])
		case_five(stack, pivots);
}

void	three_reverse_sort(t_stack *stack, long long len, t_pivots *pivots)
{
	len--;
	if (stack->b[len] > stack->b[len - 2] \
	&& stack->b[len - 2] > stack->b[len - 1])
		reverse_case_one(stack, pivots);
	else if (stack->b[len - 2] > stack->b[len] \
	&& stack->b[len] > stack->b[len -1])
		reverse_case_two(stack, pivots);
	else if (stack->b[len - 1] > stack->b[len] \
	&& stack->b[len] > stack->b[len - 2])
		reverse_case_three(stack, pivots);
	else if (stack->b[len - 2] > stack->b[len - 1] \
	&& stack->b[len - 1] > stack->b[len])
		reverse_case_four(stack, pivots);
	else if (stack->b[len - 1] > stack->b[len - 2] \
	&& stack->b[len - 2] > stack->b[len])
		reverse_case_five(stack, pivots);
	else if (stack->b[len - 2] < stack->b[len - 1] \
	&& stack->b[len - 1] < stack->b[len])
	{
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
		p_order(stack, STACK_A, pivots);
	}
}
