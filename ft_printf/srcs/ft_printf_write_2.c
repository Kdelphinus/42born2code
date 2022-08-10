/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:52:54 by myko              #+#    #+#             */
/*   Updated: 2022/08/10 21:43:13 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_x(char fm, va_list ap)
{
	int			flag;
	int			num;
	long long	lnum;

	flag = 0;
	num = va_arg(ap, int);
	lnum = (long long)num;
	if (lnum < 0)
	{
		flag = 1;
		lnum *= -1;
	}
	if (lnum == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (fm == 'X')
		return (ft_convert_base(lnum, "0123456789ABCDEF", flag));
	return (ft_convert_base(lnum, "0123456789abcdef", flag));
}

int	write_u(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	ft_putunnbr(num);
	return (ft_nbr_count(num));
}

int	write_p(va_list ap)
{
	int		size;
	void	*ptr;

	size = 2;
	ptr = va_arg(ap, void *);
	write(1, "0x", 2);
	size += ft_putptr((unsigned long long)ptr);
	return (size);
}
