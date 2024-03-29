/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:19:09 by myko              #+#    #+#             */
/*   Updated: 2022/07/08 13:21:12 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cs;
	char	cc;

	i = ft_strlen(s);
	cs = (char *)s;
	cc = (char)c;
	if (cc == 0)
		return (cs + i);
	while (--i >= 0)
	{
		if (cs[i] == cc)
			return (cs + i);
	}
	return (0);
}
