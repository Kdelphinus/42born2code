/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:01:05 by myko              #+#    #+#             */
/*   Updated: 2022/09/23 16:39:28 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	kind_fractal(char *s)
{
	if (ft_strcmp(s, "mandelbrot"))
		return (1);
	else if (ft_strcmp(s, "julia"))
		return (2);
	return (0);
}