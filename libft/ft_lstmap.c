/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:01:30 by myko              #+#    #+#             */
/*   Updated: 2022/07/12 20:51:28 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*c_lst;
	t_list	*new;

	c_lst = 0;
	while (1)
	{
		new = ft_lstnew(f(lst->content));
		if (new == 0)
		{
			ft_lstclear(&c_lst, del);
			return (0);
		}
		ft_lstadd_back(&c_lst, new);
		lst = lst->next;
		if (lst == 0)
			return (c_lst);
	}
}
