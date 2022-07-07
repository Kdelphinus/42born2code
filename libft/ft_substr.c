/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:19:19 by myko              #+#    #+#             */
/*   Updated: 2022/07/08 05:38:36 by myko             ###   ########.fr       */
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
	cp = (char *)malloc(sizeof(char) * (s_len - start) + 1);
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
