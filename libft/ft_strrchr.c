/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:33:11 by myko              #+#    #+#             */
/*   Updated: 2022/07/07 15:35:01 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cs;

	i = ft_strlen(s);
	cs = (char *)s;
	if (c == 0)
		return (cs + i);
	while (--i >= 0)
	{
		if (cs[i] == c)
			return (cs + i);
	}
	return (0);
}
