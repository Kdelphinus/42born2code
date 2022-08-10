/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:06:00 by myko              #+#    #+#             */
/*   Updated: 2022/08/10 21:46:40 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunnbr(unsigned int num)
{
	char	n;

	if (num > 9)
		ft_putunnbr(num / 10);
	n = num % 10 + '0';
	write(1, &n, 1);
}

static void	ft_putptr_2(unsigned long long ptr, int *cnt, char *base)
{
	if (ptr > 15)
		ft_putptr_2(ptr / 16, cnt, base);
	(*cnt)++;
	write(1, &base[ptr % 16], 1);
}

int	ft_putptr(unsigned long long ptr)
{
	int	cnt;

	cnt = 0;
	ft_putptr_2(ptr, &cnt, "0123456789abcdef");
	return (cnt);
}
