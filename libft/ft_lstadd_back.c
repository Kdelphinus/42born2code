/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:52:22 by myko              #+#    #+#             */
/*   Updated: 2022/07/12 20:04:39 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*origin;

	origin = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next != 0)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = origin;
}
