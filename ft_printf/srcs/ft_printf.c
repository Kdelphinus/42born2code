/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:31:54 by myko              #+#    #+#             */
/*   Updated: 2022/08/06 01:29:01 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

static int	format_print(const char **format, va_list ap)
{
	int		size;
	char	*str;
	char	chr;

	(*format)++;
	if (*(*format) == 'c')
	{
		chr = va_arg(ap, int);
		write(1, &chr, 1);
		size = 1;
	}
	else if (*(*format) == 's')
	{
		str = va_arg(ap, char *);
		write(1, str, ft_strlen(str));
		size = ft_strlen(str);
	}
	else if (*(*format) == 'd')
	{
		size = va_arg(ap, int);
		ft_putnbr_fd(size, 1);
		size = ft_nbr_count(size);
	}
	(*format)++;
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	va_list	ap;

	if (ft_chr_count(format, '%') == 0)
	{
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	}
	size = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			size += format_print(&format, ap);
		write(1, format, 1);
		size++;
		format++;
	}
	return (size);
}
