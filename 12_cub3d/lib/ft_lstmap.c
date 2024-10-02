/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:19:27 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/17 21:19:28 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstclear_lstmap(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst == 0)
		return (0);
	while (*lst)
	{
		temp = *lst;
		del(temp->content);
		*lst = temp->next;
		free(temp);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	void	*temp_c;

	if (!lst)
		return (0);
	new = 0;
	while (lst)
	{
		temp_c = f(lst->content);
		if (!temp_c)
			return (ft_lstclear_lstmap(&new, del));
		temp = ft_lstnew(temp_c);
		if (!temp)
		{
			del(temp_c);
			return (ft_lstclear_lstmap(&new, del));
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
