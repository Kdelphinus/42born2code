/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:31:54 by myko              #+#    #+#             */
/*   Updated: 2022/08/10 17:30:35 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

static int	format_print(const char **format, va_list ap)
{
	int		size;
	char	fm;

	(*format)++;
	fm = *(*format);
	if (fm == 'c')
		size = write_c(ap);
	else if (fm == 's')
		size = write_s(ap);
	else if (fm == 'd')
		size = write_d(ap);
	else
		size = 0;
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
		else
		{
			write(1, format, 1);
			size++;
			format++;
		}
	}
	return (size);
}
