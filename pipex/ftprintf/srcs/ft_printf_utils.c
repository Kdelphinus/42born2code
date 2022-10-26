/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:13:43 by myko              #+#    #+#             */
/*   Updated: 2022/10/26 13:47:31 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_count(long long lnum)
{
	int			cnt;

	if (lnum == 0)
		return (1);
	cnt = 0;
	if (lnum < 0)
	{
		lnum *= -1;
		cnt++;
	}
	while (lnum)
	{
		lnum /= 10;
		cnt++;
	}
	return (cnt);
}

static int	cal_idx(long long lnum, int flag)
{
	if (flag)
	{
		lnum -= 15;
		if (lnum < 0)
			lnum *= -1;
	}
	return (lnum);
}

static int	cal_minus(int **nbr_p, int idx)
{
	int	size;
	int	*nbr;

	nbr = *nbr_p;
	size = 0;
	while (idx >= 0)
	{
		nbr[idx] = 15;
		idx--;
		size++;
	}
	idx = 7;
	while (idx >= 0)
	{
		nbr[idx]++;
		if (nbr[idx] < 16)
			break ;
		nbr[idx] = 0;
		idx--;
	}
	return (size);
}

int	ft_convert_base(long long lnum, const char *base, int flag)
{
	int	size;
	int	idx;
	int	*nbr;

	idx = 7;
	size = 0;
	nbr = (int *)ft_calloc(8, sizeof(int));
	if (nbr == 0)
		return (0);
	while (idx >= 0 && lnum)
	{
		nbr[idx--] = cal_idx(lnum % 16, flag);
		lnum /= 16;
		size++;
	}
	if (flag)
		size += cal_minus(&nbr, idx);
	idx = 8 - size;
	while (idx < 8)
		write(1, &base[nbr[idx++]], 1);
	free(nbr);
	return (size);
}
