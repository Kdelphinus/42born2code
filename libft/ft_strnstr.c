/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:05:02 by myko              #+#    #+#             */
/*   Updated: 2022/07/06 21:22:09 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_partstrcmp(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	i = 0;
	while (needle[i])
	{
		if (needle[i] != haystack[i])
			return (0);
		i++;
	}
	if (i < n)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*r;

	i = 0;
	r = (char *)haystack;
	if (needle[0] == 0)
		return (r);
	while (i < len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_partstrcmp(haystack + i, needle, len - i + 1))
				return (r + i);
		}
		i++;
	}
	return (0);
}
