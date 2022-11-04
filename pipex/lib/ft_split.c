/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:18:20 by myko              #+#    #+#             */
/*   Updated: 2022/11/04 09:02:32 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s, int i, char c)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = find_start(s, 0, c);
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		cnt++;
		i = find_start(s, i, c);
	}
	return (cnt);
}

static char	**null_guard(char **ss, int k)
{
	while (--k >= 0)
		free(ss[k]);
	free(ss);
	return (0);
}

static char	**ft_str_input(char const *s, char **ss, char c)
{
	int	i;
	int	e;
	int	k;
	int	j;

	k = 0;
	i = find_start(s, 0, c);
	while (s[i])
	{
		e = i;
		while (s[e] && s[e] != c)
			e++;
		ss[k] = (char *)malloc(sizeof(char) * (e - i) + 1);
		if (ss[k] == 0)
			return (null_guard(ss, k));
		j = 0;
		while (i < e)
			ss[k][j++] = s[i++];
		ss[k++][j] = 0;
		i = find_start(s, i, c);
	}
	ss[k] = 0;
	return (ss);
}

char	**ft_split(char const *s, char c)
{
	int		w_cnt;
	char	**ss;

	w_cnt = word_count(s, c);
	ss = (char **)malloc(sizeof(char *) * (w_cnt + 1));
	if (ss == 0)
		return (0);
	if (w_cnt == 0)
	{
		ss[0] = 0;
		return (ss);
	}
	return (ft_str_input(s, ss, c));
}
