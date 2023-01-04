/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_func_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:36:42 by myko              #+#    #+#             */
/*   Updated: 2023/01/04 21:25:37 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h> // TODO
void    other_sort(t_stack *stack, long long len, t_pivots *pivots)
{
    int tmp;

    pivots->one = stack->arr[stack->arr_len / 2];
    while (--len >= 0)
    {
        if (stack->a[stack->a_len - 1] < pivots->one)
            r_order(stack->a, stack->a_len, STACK_A, pivots);
        else
            p_order(stack, STACK_B, pivots);
    }
    basic_sort_b(stack, pivots->pb, pivots);
    tmp = pivots->ra;
    printf("\n\n\na:  ");
    for (int i = 0; i < stack->a_len; i++)
        printf("%d ", stack->a[i]);
    printf("\n");
    printf("\nb:  ");
    for (int i = 0; i < stack->b_len; i++)
        printf("%d ", stack->b[i]);
    printf("\n");
    printf("pb: %d ra: %d\n\n\n", pivots->pb, pivots->ra);
    while (--tmp >= 0)
        rr_order(stack->a, stack->a_len, STACK_A);
    basic_sort_a(stack, pivots->ra, pivots);
}

void    other_reverse_sort(t_stack *stack, long long len, t_pivots *pivots)
{
    int tmp;

    pivots->one = stack->arr[stack->arr_len / 2];
    while (--len >= 0)
    {
        if (stack->b[stack->b_len - 1] < pivots->one)
            r_order(stack->b, stack->b_len, STACK_A, pivots);
        else
            p_order(stack, STACK_A, pivots);
    }
    basic_sort_a(stack, pivots->pa, pivots);
    tmp = pivots->rb;
    printf("\n\n\na:  ");
    for (int i = 0; i < stack->a_len; i++)
        printf("%d ", stack->a[i]);
    printf("\n");
    printf("\nb:  ");
    for (int i = 0; i < stack->b_len; i++)
        printf("%d ", stack->b[i]);
    printf("\n");
    printf("pb: %d ra: %d\n\n\n", pivots->pb, pivots->ra);
    while (--tmp >= 0)
        rr_order(stack->b, stack->b_len, STACK_B);
    basic_sort_b(stack, pivots->rb, pivots);
}
