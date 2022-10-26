/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:31:54 by myko              #+#    #+#             */
/*   Updated: 2022/10/26 13:47:40 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_print(const char **format, va_list ap)
{
	int		size;
	char	fm;

	(*format)++;
	fm = *(*format);
	size = -1;
	if (fm == 'c')
		size = write_c(ap);
	else if (fm == 's')
		size = write_s(ap);
	else if (fm == 'd' || fm == 'i')
		size = write_d(ap);
	else if (fm == '%')
		size = write_per();
	else if (fm == 'x' || fm == 'X')
		size = write_x(fm, ap);
	else if (fm == 'u')
		size = write_u(ap);
	else if (fm == 'p')
		size = write_p(ap);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	int		tmp;
	va_list	ap;

	size = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			tmp = format_print(&format, ap);
			if (tmp == -1)
				return (-1);
			size += tmp;
		}
		else
		{
			write(1, format, 1);
			size++;
		}
		format++;
	}
	va_end(ap);
	return (size);
}
