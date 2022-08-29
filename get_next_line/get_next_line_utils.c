/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:55:31 by myko              #+#    #+#             */
/*   Updated: 2022/08/29 20:26:04 by myko             ###   ########.fr       */
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
	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	sj = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (sj == 0)
		return (0);
	while (i < s1_len)
	{
		sj[i] = s1[i];
		i++;
	}	
	free(s1);
	i = 0;
	while (i < s2_len)
	{
		sj[i + s1_len] = s2[i];
		i++;
	}
	sj[i + s1_len] = 0;
	return (sj);
}

int	ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
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
