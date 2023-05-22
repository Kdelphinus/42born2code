/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:22:14 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/17 21:22:15 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	temp;
	size_t	s_len;

	temp = (char)c;
	s_len = ft_strlen(s);
	while (s_len > 0)
	{
		if (s[s_len] == temp)
			return ((char *)s + s_len);
		s_len--;
	}
	if (*s == temp)
		return ((char *)s);
	else
		return (0);
}
