/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:55:31 by myko              #+#    #+#             */
/*   Updated: 2022/08/25 13:40:32 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strljoin(char *s1, const char *s2, int s2_len)
{
	int		i;
	int		s1_len;
	char	*sj;

	i = 0;
	s1_len = ft_strlen(s1);
	sj = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (sj == 0)
		return (0);
	while (i < s1_len)
	{
		sj[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		sj[i + s1_len] = s2[i];
		i++;
	}
	sj[i + s1_len] = 0;
	free(s1);
	return (sj);
}

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;
	char	*cs;

	i = 0;
	cc = (char)c;
	cs = (char *)s;
	while (cs[i])
	{
		if (cs[i] == cc)
			return (i);
		i++;
	}
	if (cs[i] == cc)
		return (i);
	return (-1);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		s1_len;
	char	*s2;

	i = 0;
	s1_len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (s2 == 0)
		return (0);
	while (i < s1_len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
