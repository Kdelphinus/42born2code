/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:19:04 by myko              #+#    #+#             */
/*   Updated: 2022/07/08 03:20:55 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_partstrcmp(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i])
	{
		if (needle[i] != haystack[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;
	size_t	h_len;
	char	*r;

	i = 0;
	r = (char *)haystack;
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return (r);
	if (len < n_len || h_len < n_len)
		return (0);
	while (i <= len - n_len && r[i])
	{
		if (r[i] == needle[0])
		{
			if (ft_partstrcmp(r + i, needle))
				return (r + i);
		}
		i++;
	}
	return (0);
}
