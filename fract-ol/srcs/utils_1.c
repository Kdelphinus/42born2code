/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:01:05 by myko              #+#    #+#             */
/*   Updated: 2022/09/30 16:53:38 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 != *s2)
			return (0);
		if (*s1 == 0 && *s2 == 0)
			return (1);
		s1++;
		s2++;
	}
}

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

static int	sign_flag(char **s, int *flag)
{
	int	i;

	i = 0;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*flag *= -1;
		i++;
	}
	return (i);
}

double	str_to_double(char *s)
{
	int		len;
	int		i;
	int		flag;
	double	result;

	flag = 1;
	result = 0;
	len = ft_strlen(s);
	i = sign_flag(&s, &flag);
	while (*s)
	{
		if ('0' <= *s && *s <= '9')
			result = result * 10 + (*s - '0');
		else if (*s == '.')
			i = 0;
		else
			break ;
		i++;
		s++;
	}
	if (i == len)
		return (flag * result);
	return (flag * result / pow(10, i - 1));
}

int	fractal_draw(t_frac *frac)
{
	if (frac->c_argc == 1)
		return (0);
	if (ft_strcmp(frac->c_argv[1], "mandelbrot"))
		mandelbrot_draw(frac);
	else if (ft_strcmp(frac->c_argv[1], "julia"))
		julia_draw(frac);
	else if (ft_strcmp(frac->c_argv[1], "multibrot"))
		multibrot_draw(frac);
	else
		return (0);
	return (1);
}
