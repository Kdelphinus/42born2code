/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:18:54 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/17 21:18:56 by jaekkang         ###   ########.fr       */
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
