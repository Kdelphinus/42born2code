/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_reverse_sort_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:26:22 by myko              #+#    #+#             */
/*   Updated: 2023/01/10 15:54:47 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_case_one(t_stack *stack, t_pivots *pivots)
{
	p_order(stack, STACK_A, pivots);
	s_order(stack, STACK_B);
	p_order(stack, STACK_A, pivots);
	p_order(stack, STACK_A, pivots);
}

void	reverse_case_two(t_stack *stack, t_pivots *pivots)
{
	r_order(stack, STACK_B, pivots, stack->b_len - 1);
	s_order(stack, STACK_B);
	p_order(stack, STACK_A, pivots);
	rr_order(stack, STACK_B);
	p_order(stack, STACK_A, pivots);
	p_order(stack, STACK_A, pivots);
}

void	reverse_case_three(t_stack *stack, t_pivots *pivots)
{
	s_order(stack, STACK_B);
	p_order(stack, STACK_A, pivots);
	p_order(stack, STACK_A, pivots);
	p_order(stack, STACK_A, pivots);
}

void	reverse_case_four(t_stack *stack, t_pivots *pivots)
{
	r_order(stack, STACK_B, pivots, stack->b_len - 1);
	s_order(stack, STACK_B);
	p_order(stack, STACK_A, pivots);
	p_order(stack, STACK_A, pivots);
	rr_order(stack, STACK_B);
	p_order(stack, STACK_A, pivots);
}

void	reverse_case_five(t_stack *stack, t_pivots *pivots)
{
	r_order(stack, STACK_B, pivots, stack->b_len - 1);
	p_order(stack, STACK_A, pivots);
	p_order(stack, STACK_A, pivots);
	rr_order(stack, STACK_B);
	p_order(stack, STACK_A, pivots);
}
