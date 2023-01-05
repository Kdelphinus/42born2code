/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_func_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:36:42 by myko              #+#    #+#             */
/*   Updated: 2023/01/05 18:39:52 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    hard_other_sort(t_stack *stack)
{
    t_pivots    pivots;

    stack->b = (int *)malloc(sizeof(int) * stack->a_len);
    if (!stack->b)
		ft_error();
    stack->b_len = 0;
    pivots = set_pivot(stack, STACK_A, stack->a_len);
    other_sort(stack, stack->a_len, &pivots);
}

void    other_sort(t_stack *stack, long long len, t_pivots *pivots)
{
    int tmp;

    set_one_pivot(stack, pivots, STACK_A, len);
    while (--len >= 0)
    {
        if (stack->a[stack->a_len - 1] < pivots->one)
            p_order(stack, STACK_B, pivots);
            // r_order(stack->a, stack->a_len, STACK_A, pivots);
        else
            r_order(stack->a, stack->a_len, STACK_A, pivots);
            // p_order(stack, STACK_B, pivots);
    }
    // basic_sort_b(stack, pivots->pb, pivots);
    tmp = pivots->ra;
    while (--tmp >= 0)
        rr_order(stack->a, stack->a_len, STACK_A);
    basic_sort_a(stack, pivots->ra, pivots);
    basic_sort_b(stack, pivots->pb, pivots);
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
