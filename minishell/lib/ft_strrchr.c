/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:41:12 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 20:41:04 by juyojeon         ###   ########.fr       */
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
