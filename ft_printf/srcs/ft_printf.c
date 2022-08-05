/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:31:54 by myko              #+#    #+#             */
/*   Updated: 2022/08/05 19:34:16 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	format_print(const char **format, va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	(*format)++;
	if (*(*format) == 'c')
		write(1, &num, 1);
	(*format)++;
	return (1);
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
