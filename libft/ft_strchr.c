/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:18:26 by myko              #+#    #+#             */
/*   Updated: 2022/07/08 04:50:55 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cs;

	i = 0;
	cs = (char *)s;
	while (cs[i])
	{
		if (cs[i] == (char)c)
			return (cs + i);
		i++;
	}
	if (cs[i] == (char)c)
		return (cs + i);
	return (0);
}
