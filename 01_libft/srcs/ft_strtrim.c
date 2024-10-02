/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:19:14 by myko              #+#    #+#             */
/*   Updated: 2022/07/20 18:20:04 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start(char const *s1, int check[])
{
	int	i;

	i = 0;
	while (s1[i] && check[(int)s1[i]])
		i++;
	return (i);
}

static size_t	find_end(char const *s1, int check[], int s1_len)
{
	s1_len--;
	while (check[(int)s1[s1_len]])
	{
		if (s1_len == 0)
			return (0);
		s1_len--;
	}
	return (s1_len);
}

static void	init(char const *set, int check[])
{
	int	i;

	i = -1;
	while (++i < 128)
		check[i] = 0;
	i = -1;
	while (set[++i])
	{
		if (check[(int)set[i]] == 0)
			check[(int)set[i]] = 1;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	start;
	size_t	end;
	int		check[128];
	char	*st;

	i = 0;
	init(set, check);
	end = ft_strlen(s1);
	if (end == 0)
		return (ft_strdup(""));
	start = find_start(s1, check);
	end = find_end(s1, check, end);
	if (end <= start)
		return (ft_strdup(""));
	st = (char *)malloc(sizeof(char) * (end - start + 2));
	if (st == 0)
		return (0);
	while (start <= end)
		st[i++] = s1[start++];
	st[i] = 0;
	return (st);
}
