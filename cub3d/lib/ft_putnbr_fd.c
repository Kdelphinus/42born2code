/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:20:10 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/17 21:20:11 by jaekkang         ###   ########.fr       */
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
