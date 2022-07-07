/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:19:09 by myko              #+#    #+#             */
/*   Updated: 2022/07/08 04:52:14 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cs;

	i = ft_strlen(s);
	cs = (char *)s;
	if ((char)c == 0)
		return (cs + i);
	while (--i >= 0)
	{
		if (cs[i] == (char)c)
			return (cs + i);
	}
	return (0);
}
