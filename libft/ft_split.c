/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:18:20 by myko              #+#    #+#             */
/*   Updated: 2022/07/07 19:18:22 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] != c)
			i++;
		cnt++;
		while (s[i] == c)
			i++;
	}
	return (cnt);
}

char	**ft_str_input(char const *s, char **ss, char c)
{
	int	i;
	int	e;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	while (s[i] == c)
		i++;
	e = i;
	while (s[i])
	{
		while (s[e] != c)
			e++;
		ss[k] = (char *)malloc(sizeof(char) * (e - i + 2));
		if (ss[k] == 0)
			return (0);
		while (i < e)
			ss[k][j++] = s[i++];
		ss[k++][j] = 0;
		j = 0;
		while (s[i] == c)
			i++;
		e = i;
	}
	ss[k] = 0;
	return (ss);
}

char	**ft_split(char const *s, char c)
{
	int		w_cnt;
	char	**ss;

	w_cnt = word_count(s, c);
	if (w_cnt == 0)
		return (0);
	ss = (char **)malloc(sizeof(char *) * (w_cnt + 1));
	if (ss == 0)
		return (0);
	return (ft_str_input(s, ss, c));
}
