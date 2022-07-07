/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:45:54 by myko              #+#    #+#             */
/*   Updated: 2022/07/07 19:53:35 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ll(long long ln, int fd)
{
	char	n;

	if (ln > 9)
		ft_putnbr_ll(ln / 10, fd);
	n = ln % 10 + '0';
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	ln;

	ln = (long long)n;
	if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr_ll(ln, fd);
}
