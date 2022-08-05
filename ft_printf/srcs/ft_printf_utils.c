/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:13:43 by myko              #+#    #+#             */
/*   Updated: 2022/08/06 01:27:22 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chr_count(const char *str, char chr)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == chr)
			cnt++;
		str++;
	}
	return (cnt);
}

int	ft_nbr_count(int num)
{
	int			cnt;
	long long	lnum;

	if (num == 0)
		return (1);
	cnt = 0;
	lnum = (long long)num;
	if (lnum < 0)
	{
		lnum *= -1;
		cnt++;
	}
	while (lnum)
	{
		lnum /= 10;
		cnt++;
	}
	return (cnt);
}
