/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:21:14 by myko              #+#    #+#             */
/*   Updated: 2022/08/10 17:55:12 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	write_c(va_list ap)
{
	char	chr;

	chr = va_arg(ap, int);
	if (chr < 0 || chr > 126)
		chr = 0;
	write(1, &chr, 1);
	return (1);
}

int	write_s(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	write_d(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	ft_putnbr_fd(num, 1);
	return (ft_nbr_count(num));
}

int	write_per(void)
{
	write(1, "%", 1);
	return (1);
}
