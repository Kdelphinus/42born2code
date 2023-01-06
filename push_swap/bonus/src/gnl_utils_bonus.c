/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:55:31 by myko              #+#    #+#             */
/*   Updated: 2023/01/06 18:58:57 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strljoin(char *s1, char *s2, int s2_len)
{
	int		i;
	int		s1_len;
	char	*sj;

	i = -1;
	s1_len = 0;
	if (s1)
		s1_len = gnl_strlen(s1);
	sj = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (sj == 0)
		return (0);
	while (++i < s1_len)
		sj[i] = s1[i];
	free(s1);
	i = -1;
	while (++i < s2_len)
		sj[i + s1_len] = s2[i];
	sj[i + s1_len] = 0;
	return (sj);
}

int	gnl_strchr(char *s, char c)
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

char	*gnl_strdup(char *s1)
{
	int		i;
	int		s1_len;
	char	*s2;

	i = 0;
	s1_len = gnl_strlen(s1);
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

char	*char_free(char **line, char **c_line)
{
	free(*line);
	free(*c_line);
	return (0);
}
