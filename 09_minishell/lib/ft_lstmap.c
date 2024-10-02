/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:02:07 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/19 21:23:04 by juyojeon         ###   ########.fr       */
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
