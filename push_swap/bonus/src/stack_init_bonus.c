/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:20:45 by myko              #+#    #+#             */
/*   Updated: 2023/01/09 19:31:59 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	stack_init_checker1(int argc, char **argv, t_stack *stack)
{
	long long	tmpn;
	long long	i;

	i = -1;
	stack->a = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack->a)
		ft_error_checker();
	stack->a_len = argc - 1;
	while (++i < argc - 1)
	{
		tmpn = ft_atoi_int_checker(argv[i + 1]);
		if (tmpn == INT_ERROR)
			ft_error_checker();
		stack->a[stack->a_len - i - 1] = tmpn;
	}
}

void	stack_init_checker2(char **argv, t_stack *stack)
{
	char		**tmp;
	long long	tmpn;
	long long	i;
	long long	len;

	i = -1;
	tmp = ft_split(argv[1], ' ');
	len = ft_charp_len(tmp);
	stack->a = (int *)malloc(sizeof(int) * len);
	if (!stack->a)
		ft_error_checker();
	stack->a_len = len;
	while (++i < len)
	{
		tmpn = ft_atoi_int_checker(tmp[i]);
		free(tmp[i]);
		if (tmpn == INT_ERROR)
			ft_error_checker();
		stack->a[len - i - 1] = tmpn;
	}
	free(tmp);
}

void	arr_init_checekr(t_stack *stack, long long len, int flag)
{
	int	i;

	stack->arr_len = len;
	stack->arr = (int *)malloc(sizeof(int) * len);
	if (!stack->arr)
		ft_error_checker();
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
