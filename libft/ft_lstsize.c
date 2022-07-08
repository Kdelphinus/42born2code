/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:37:56 by myko              #+#    #+#             */
/*   Updated: 2022/07/08 13:42:09 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*nt;

	cnt = 0;
	nt = lst;
	while (nt -> next)
	{
		nt = nt -> next;
		cnt++;
	}
	return (cnt);
}
