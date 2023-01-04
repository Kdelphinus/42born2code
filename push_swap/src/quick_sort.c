/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:24:46 by myko              #+#    #+#             */
/*   Updated: 2023/01/04 20:31:33 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_arg(int *arr, long long *i, long long *j)
{
	int	tmp;

	tmp = arr[*i];
	arr[*i] = arr[*j];
	arr[*j] = tmp;
	(*i)++;
	(*j)--;
}

void	quick_sort(int *arr, long long left, long long right)
{
	long long	pivot;
	long long	l;
	long long	r;

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
