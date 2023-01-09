/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:17:10 by myko              #+#    #+#             */
/*   Updated: 2023/01/09 22:05:57 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	case_one(t_stack *stack, t_pivots *pivots)
{
	p_order(stack, STACK_B, pivots);
	s_order(stack, STACK_A);
	r_order(stack, STACK_A, pivots);
	r_order(stack, STACK_A, pivots);
	p_order(stack, STACK_A, pivots);
	rr_order(stack, STACK_A);
	rr_order(stack, STACK_A);
}

void	case_two(t_stack *stack)
{
	s_order(stack, STACK_A);
}

void	case_three(t_stack *stack, t_pivots *pivots)
{
	p_order(stack, STACK_B, pivots);
	r_order(stack, STACK_A, pivots);
	r_order(stack, STACK_A, pivots);
	p_order(stack, STACK_A, pivots);
	rr_order(stack, STACK_A);
	rr_order(stack, STACK_A);
}

void	case_four(t_stack *stack, t_pivots *pivots)
{
	r_order(stack, STACK_A, pivots);
	s_order(stack, STACK_A);
	rr_order(stack, STACK_A);
}

void	case_five(t_stack *stack, t_pivots *pivots)
{
	r_order(stack, STACK_A, pivots);
	r_order(stack, STACK_A, pivots);
	p_order(stack, STACK_B, pivots);
	rr_order(stack, STACK_A);
	rr_order(stack, STACK_A);
	p_order(stack, STACK_A, pivots);
}
