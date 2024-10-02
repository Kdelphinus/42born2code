/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:01:20 by myko              #+#    #+#             */
/*   Updated: 2023/01/10 16:20:24 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*print_s_order(t_list *orders)
{
	if (orders->next && ft_strncmp(orders->content, "sa\n", 4) == 0 \
	&& ft_strncmp(orders->next->content, "sb\n", 4) == 0)
	{
		ft_putstr_fd("ss\n", STDOUT_FILENO);
		orders = orders->next;
	}
	else if (orders->next && ft_strncmp(orders->content, "sb\n", 4) == 0 \
	&& ft_strncmp(orders->next->content, "sa\n", 4) == 0)
	{
		ft_putstr_fd("ss\n", STDOUT_FILENO);
		orders = orders->next;
	}
	else
		ft_putstr_fd(orders->content, STDOUT_FILENO);
	return (orders->next);
}

static t_list	*print_r_order(t_list *orders)
{
	if (orders->next && ft_strncmp(orders->content, "ra\n", 4) == 0 \
	&& ft_strncmp(orders->next->content, "rb\n", 4) == 0)
	{
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		orders = orders->next;
	}
	else if (orders->next && ft_strncmp(orders->content, "rb\n", 4) == 0 \
	&& ft_strncmp(orders->next->content, "ra\n", 4) == 0)
	{
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		orders = orders->next;
	}
	else
		ft_putstr_fd(orders->content, STDOUT_FILENO);
	return (orders->next);
}

static t_list	*print_rr_order(t_list *orders)
{
	if (orders->next && ft_strncmp(orders->content, "rra\n", 5) == 0 \
	&& ft_strncmp(orders->next->content, "rrb\n", 5) == 0)
	{
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		orders = orders->next;
	}
	else if (orders->next && ft_strncmp(orders->content, "rrb\n", 5) == 0 \
	&& ft_strncmp(orders->next->content, "rra\n", 5) == 0)
	{
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		orders = orders->next;
	}
	else
		ft_putstr_fd(orders->content, STDOUT_FILENO);
	return (orders->next);
}

static t_list	*print_p_order(t_list *orders)
{
	ft_putstr_fd(orders->content, STDOUT_FILENO);
	return (orders->next);
}

void	print_order(t_list *orders)
{
	t_list	*origin;

	origin = orders;
	orders = orders->next;
	while (orders)
	{
		if (ft_strncmp(orders->content, "sa\n", 4) == 0 \
		|| ft_strncmp(orders->content, "sb\n", 4) == 0)
			orders = print_s_order(orders);
		else if (ft_strncmp(orders->content, "ra\n", 4) == 0 \
		|| ft_strncmp(orders->content, "rb\n", 4) == 0)
			orders = print_r_order(orders);
		else if (ft_strncmp(orders->content, "rra\n", 5) == 0 \
		|| ft_strncmp(orders->content, "rrb\n", 5) == 0)
			orders = print_rr_order(orders);
		else
			orders = print_p_order(orders);
	}
	ft_lstclear(&origin, char_null);
}
