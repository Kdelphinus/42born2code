/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:20:33 by myko              #+#    #+#             */
/*   Updated: 2022/12/17 17:25:38 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

long long	ft_charp_len(char **charpoint)
{
	long long	i;

	i = 0;
	while (charpoint[i])
		i++;
	return (i);
}

void	print_command(t_llist *orders)
{
	while (orders->order)
	{
		if (ft_strncmp(orders->order, "sa", 2) == 0 && \
			ft_strncmp(orders->next->order, "sb", 2) == 0)
			ft_putstr_fd("ss\n", STDOUT_FILENO);
		else if (ft_strncmp(orders->order, "sb", 2) == 0 && \
			ft_strncmp(orders->next->order, "sa", 2) == 0)
			ft_putstr_fd("ss\n", STDOUT_FILENO);
		else if (ft_strncmp(orders->order, "ra", 2) == 0 && \
			ft_strncmp(orders->next->order, "rb", 2) == 0)
			ft_putstr_fd("rr\n", STDOUT_FILENO);
		else if (ft_strncmp(orders->order, "rb", 2) == 0 && \
			ft_strncmp(orders->next->order, "ra", 2) == 0)
			ft_putstr_fd("rr\n", STDOUT_FILENO);
		else if (ft_strncmp(orders->order, "rra", 3) == 0 && \
			ft_strncmp(orders->next->order, "rrb", 2) == 0)
			ft_putstr_fd("rrr\n", STDOUT_FILENO);
		else if (ft_strncmp(orders->order, "rrb", 3) == 0 && \
			ft_strncmp(orders->next->order, "rra", 2) == 0)
			ft_putstr_fd("rrr\n", STDOUT_FILENO);
		else
			ft_putstr_fd(ft_strjoin(orders->order, "\n"), STDOUT_FILENO);
		orders = orders->next;
	}
}
