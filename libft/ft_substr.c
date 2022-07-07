/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:42:18 by myko              #+#    #+#             */
/*   Updated: 2022/07/07 16:13:23 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*cp;

	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	cp = (char *)malloc(sizeof(char) * (len + 1));
	if (cp == 0)
		return (0);
	while (i < len && s[i + start])
	{
		cp[i] = s[i + start];
		i++;
	}
	cp[i] = 0;
	return (cp);
}
