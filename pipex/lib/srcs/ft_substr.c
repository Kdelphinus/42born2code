/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:19:19 by myko              #+#    #+#             */
/*   Updated: 2022/07/08 13:37:31 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	sstart;
	char	*cp;

	i = 0;
	sstart = (size_t)start;
	s_len = ft_strlen(s);
	if (sstart >= s_len)
		return (ft_strdup(""));
	if (s_len - sstart < len)
		len = s_len - sstart;
	cp = (char *)malloc(sizeof(char) * len + 1);
	if (cp == 0)
		return (0);
	while (i < len && s[i + sstart])
	{
		cp[i] = s[i + sstart];
		i++;
	}
	cp[i] = 0;
	return (cp);
}
