/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:20:45 by myko              #+#    #+#             */
/*   Updated: 2023/01/05 18:46:55 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_init1(int argc, char **argv, t_stack *stack)
{
	int			flag;
	long long	tmpn;
	long long	i;

	i = -1;
	flag = 1;
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
		if (i > 0 && stack->a[stack->a_len - i] > tmpn)
			flag = 0;
	}
	return (flag);
}

int	stack_init2(char **argv, t_stack *stack)
{
	int			flag;
	char		**tmp;
	long long	tmpn;
	long long	i;
	long long	len;

	i = -1;
	flag = 1;
	tmp = ft_split(argv[1], ' ');
	len = ft_charp_len(tmp);
	if (len == 0)
		ft_error();
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
		if (i > 0 && stack->a[stack->a_len - i] > tmpn)
			flag = 0;
	}
	return (flag);
}

void	arr_init(t_stack *stack, long long len, int flag)
{
	int	i;

	stack->arr_len = len;
	stack->arr = (int *)malloc(sizeof(int) * len);
	if (!stack->arr)
		ft_error();
	i = -1;
	if (flag == STACK_A)
	{
		while (++i < len)
			stack->arr[i] = stack->a[stack->a_len - i - 1];
	}
	else
	{
		while (++i < len)
			stack->arr[i] = stack->b[stack->b_len - i - 1];
	}
}
