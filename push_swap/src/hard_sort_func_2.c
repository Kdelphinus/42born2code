/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_func_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:36:42 by myko              #+#    #+#             */
/*   Updated: 2023/01/04 22:15:01 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    other_sort(t_stack *stack, long long len, t_pivots *pivots)
{
    int tmp;

    set_one_pivot(stack, pivots, STACK_A, len);
    while (--len >= 0)
    {
        if (stack->a[stack->a_len - 1] < pivots->one)
            r_order(stack->a, stack->a_len, STACK_A, pivots);
        else
            p_order(stack, STACK_B, pivots);
    }
    basic_sort_b(stack, pivots->pb, pivots);
    tmp = pivots->ra;
    while (--tmp >= 0)
        rr_order(stack->a, stack->a_len, STACK_A);
    basic_sort_a(stack, pivots->ra, pivots);
}

void    other_reverse_sort(t_stack *stack, long long len, t_pivots *pivots)
{
    int tmp;

    set_one_pivot(stack, pivots, STACK_B, len);
    while (--len >= 0)
    {
        if (stack->b[stack->b_len - 1] < pivots->one)
            r_order(stack->b, stack->b_len, STACK_B, pivots);
        else
            p_order(stack, STACK_A, pivots);
    }
    basic_sort_a(stack, pivots->pa, pivots);
    tmp = pivots->rb;
    while (--tmp >= 0)
        rr_order(stack->b, stack->b_len, STACK_B);
    basic_sort_b(stack, pivots->rb, pivots);
}
