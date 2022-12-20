/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:24:46 by myko              #+#    #+#             */
/*   Updated: 2022/12/20 21:45:05 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h> // TODO debug

void	stack_sort(t_stack *stack, int left, int right)
{
	int	pivot;
	int	l;
	int r;
	int	tmp;

	l = left;
	r = right;
	pivot = stack->a[(l + r) / 2];
	while (l <= r)
	{
		while (stack->a[l] > pivot)
			l++;
		while (stack->a[r] < pivot)
			r--;
		if (l <= r)
		{
			tmp = stack->a[l];
			stack->a[l] = stack->a[r];
			stack->a[r] = tmp;
			l++;
			r--;
		}
	}
	if (left < r)
		stack_sort(stack, left, r);
	if (l < right)
		stack_sort(stack, l, right);
}
