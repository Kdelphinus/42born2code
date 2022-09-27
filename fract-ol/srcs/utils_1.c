/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:01:05 by myko              #+#    #+#             */
/*   Updated: 2022/09/27 17:38:15 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] != s2[i])
			return (0);
		if (s1[i] == 0 && s2[i] == 0)
			return (1);
		i++;
	}
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

double	str_to_double(char *s)
{
	double	i;
	double	flag;
	double	result;

	i = 0;
	flag = 1;
	result = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			flag = -1;
		s++;
	}
	while (*s)
	{
		if (ft_isdigit(*s))
			result = result * 10 + (*s - '0');
		else if (*s == '.')
			i = 0;
		i++;
		s++;
	}
	return (flag * result / pow(10, i - 1));
}

int	kind_fractal(char *s)
{
	if (ft_strcmp(s, "mandelbrot"))
		return (1);
	else if (ft_strcmp(s, "julia"))
		return (2);
	return (0);
}
