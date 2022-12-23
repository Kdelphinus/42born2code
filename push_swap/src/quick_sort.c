/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:24:46 by myko              #+#    #+#             */
/*   Updated: 2022/12/23 20:04:29 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_arg(int *arr, int *i, int *j)
{
	int	tmp;

	tmp = arr[*i];
	arr[*i] = arr[*j];
	arr[*j] = tmp;
	(*i)++;
	(*j)--;
}

void	quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int	l;
	int r;

	l = left;
	r = right;
	pivot = arr[(l + r) / 2];
	while (l <= r)
	{
		while (arr[l] > pivot)
			l++;
		while (arr[r] < pivot)
			r--;
		if (l <= r)
			swap_arg(arr, &l, &r);
	}
	if (left < r)
		quick_sort(arr, left, r);
	if (l < right)
		quick_sort(arr, l, right);
}
