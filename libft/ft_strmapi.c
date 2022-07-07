/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:23:06 by myko              #+#    #+#             */
/*   Updated: 2022/07/07 19:35:00 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*ms;

	i = 0;
	size = ft_strlen(s);
	ms = (char *)malloc(sizeof(char) * (size + 1));
	if (ms == 0)
		return (0);
	while (i < size)
	{
		ms[i] = f(i, s[i]);
		i++;
	}
	ms[i] = 0;
	return (ms);
}
