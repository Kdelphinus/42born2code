/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:01:05 by myko              #+#    #+#             */
/*   Updated: 2022/10/06 17:39:13 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	sign_flag(char **s, int *flag)
{
	int	i;

	i = 0;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*flag *= -1;
		i++;
		(*s)++;
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

static int	kind_fractal(t_frac *frac)
{
	if (ft_strcmp(frac->c_argv[1], "mandelbrot"))
		frac->kind = 0;
	else if (ft_strcmp(frac->c_argv[1], "julia"))
		frac->kind = 1;
	else if (ft_strcmp(frac->c_argv[1], "multibrot"))
		frac->kind = 2;
	else if (ft_strcmp(frac->c_argv[1], "mandelbox"))
		frac->kind = 3;
	else if (ft_strcmp(frac->c_argv[1], "multicron"))
		frac->kind = 4;
	else if (ft_strcmp(frac->c_argv[1], "burning"))
		frac->kind = 5;
	else
		return (0);
	return (1);
}

int	fractal_draw(t_frac *frac)
{
	if (frac->c_argc == 1 || (frac->kind == -1 && !kind_fractal(frac)))
		return (0);
	if (frac->kind == 0)
		mandelbrot_draw(frac);
	else if (frac->kind == 1)
		julia_draw(frac);
	else if (frac->kind == 2)
		multibrot_draw(frac);
	else if (frac->kind == 3)
		mandelbox_draw(frac);
	else if (frac->kind == 4)
		multicron_draw(frac);
	else if (frac->kind == 5)
		burning_draw(frac);
	return (1);
}
