/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:36:14 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/16 04:55:38 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursion_putnbr(int n, int fd)
{
	char	temp;

	if (n > 0)
	{
		ft_recursion_putnbr(n / 10, fd);
		temp = '0' + n % 10;
		write(fd, &temp, 1);
	}
	else if (n < 0)
	{
		ft_recursion_putnbr(n / 10, fd);
		temp = '0' - n % 10;
		write(fd, &temp, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	ft_recursion_putnbr(n, fd);
	if (n == 0)
		write(fd, "0", 1);
}
