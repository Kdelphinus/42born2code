/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:11:40 by myko              #+#    #+#             */
/*   Updated: 2022/12/23 22:22:50 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	re_sort(t_stack *stack, int pivot)
{
	
}

void	find_order(t_stack *stack)
{
	int	pivot;

	stack->b = (int *)malloc(sizeof(int) * stack->a_len);
	if (!stack->b)
		ft_error();
	stack->b_len = 0;
	pivot = stack->arr[stack->arr_len / 2];
}
