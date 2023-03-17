/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:55:45 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/16 03:27:34 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert_to_c(char *str, int nbr, int nbr_len)
{
	int			nbr_idx;
	const char	*base = "0123456789";

	nbr_idx = nbr_len - 1;
	if (nbr < 0)
	{
		while (nbr != 0)
		{
			str[nbr_idx] = base[-(nbr % 10)];
			nbr_idx--;
			nbr /= 10;
		}
	}
	else if (nbr > 0)
	{
		while (nbr != 0)
		{
			str[nbr_idx] = base[nbr % 10];
			nbr_idx--;
			nbr /= 10;
		}
	}
	else
		str[0] = '0';
}

static int	ft_len_of_int(int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr <= 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa(int n)
{
	char	*str_int;
	int		nbr_len;

	nbr_len = ft_len_of_int(n);
	str_int = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!str_int)
		return (0);
	str_int[nbr_len] = '\0';
	ft_convert_to_c(str_int, n, nbr_len);
	if (n < 0)
		*str_int = '-';
	return (str_int);
}
