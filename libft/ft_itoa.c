/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:49:54 by myko              #+#    #+#             */
/*   Updated: 2022/07/07 19:07:23 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_len(long long ln)
{
	int	i;

	if (ln == 0)
		return (1);
	i = 0;
	while (ln > 0)
	{
		ln /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			sign;
	int			size;
	char		*number;
	long long	ln;

	ln = (long long)n;
	sign = 0;
	if (ln < 0)
	{
		sign = 1;
		ln *= -1;
	}
	size = n_len(ln);
	number = (char *)malloc(sizeof(char) * (size + sign + 1));
	if (number == 0)
		return (0);
	number[size + sign] = 0;
	while (--size >= 0)
	{
		number[size + sign] = ln % 10 + '0';
		ln /= 10;
	}
	if (sign)
		number[size + sign] = '-';
	return (number);
}
