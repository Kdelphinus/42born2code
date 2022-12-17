/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:20:45 by myko              #+#    #+#             */
/*   Updated: 2022/12/17 16:21:58 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_init1(int argc, char **argv, t_stack *stack)
{
	long long	tmpn;
	long long	i;

	i = -1;
	stack->a = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack->a)
		ft_error();
	stack->a_len = argc - 1;
	while (++i < argc - 1)
	{
		tmpn = ft_atoi_int(argv[i + 1]);
		if (tmpn == INT_ERROR)
			ft_error();
		stack->a[stack->a_len - i - 1] = tmpn;
	}
	return ;
}

void	stack_init2(char **argv, t_stack *stack)
{
	char		**tmp;
	long long	tmpn;
	long long	i;
	long long	len;

	i = -1;
	tmp = ft_split(argv[1], ' ');
	if (ft_atoi_int(argv[1]) != INT_ERROR)
		return ;
	len = ft_charp_len(tmp);
	stack->a = (int *)malloc(sizeof(int) * len);
	if (!stack->a)
		ft_error();
	stack->a_len = len;
	while (++i < len)
	{
		tmpn = ft_atoi_int(tmp[i]);
		if (tmpn == INT_ERROR)
			ft_error();
		stack->a[len - i - 1] = tmpn;
	}
	return ;
}
