/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:18:26 by myko              #+#    #+#             */
/*   Updated: 2022/07/08 13:19:39 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
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
			return (&cs[i]);
		i++;
	}
	if (cs[i] == cc)
		return (&cs[i]);
	return (0);
}
