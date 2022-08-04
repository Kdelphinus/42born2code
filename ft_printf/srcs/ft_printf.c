/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:31:54 by myko              #+#    #+#             */
/*   Updated: 2022/08/04 22:07:36 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		cnt;
	va_list	ap;

	cnt = ft_chr_count((char *)format, '%') / 2 * 2;
	va_start(ap, format);
	if (cnt == 0)
	{
		write(1, format, ft_strlen((char *)format));
		return (ft_strlen((char *)format));
	}
	i = 0;
	while (g_form[i])
	{
		if (ft_strchr(format, g_form[i]))
			continue;
	}
	return (0);
}
