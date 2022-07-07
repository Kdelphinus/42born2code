/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:26:09 by myko              #+#    #+#             */
/*   Updated: 2022/07/07 17:01:56 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_start(char const *s1, int check[])
{
	int	i;

	i = 0;
	while (check[(int)s1[i]])
		i++;
	return (i);
}

int	find_end(char const *s1, int check[], int s1_len)
{
	s1_len--;
	while (check[(int)s1[s1_len]])
		s1_len--;
	return (s1_len);
}

int	*init(char const *set)
{
	int	i;
	int	*check;

	i = -1;
	check = (int *)ft_calloc(128, sizeof(int));
	if (check == 0)
		return (0);
	while (set[++i])
	{
		if (check[(int)set[i]] == 0)
			check[(int)set[i]] = 1;
	}
	return (check);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	int		*check;
	char	*st;

	i = 0;
	check = init(set);
	if (check == 0)
		return (0);
	end = ft_strlen(s1);
	start = find_start(s1, check);
	end = find_end(s1, check, end);
	if (end - start + 1 <= 0)
		return (ft_strdup(""));
	st = (char *)malloc(sizeof(char) * (end - start + 2));
	if (st == 0)
		return (0);
	while (start <= end)
		st[i++] = s1[start++];
	st[i] = 0;
	return (st);
}
