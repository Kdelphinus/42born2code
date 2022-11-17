/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:02 by myko              #+#    #+#             */
/*   Updated: 2022/11/17 17:52:20 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
}

long long	ft_charp_len(char **charpoint)
{
	long long	i;

	i = 0;
	while (charpoint[i])
		i++;
	return (i);
}

int	stack_init2(char **argv, t_stack *stack)
{
	char		**tmp;
	long long	tmpn;
	long long	i;
	long long	len;

	i = -1;
	tmp = ft_split(argv[1], ' ');
	if (ft_atoi_int(argv[1]) != INT_ERROR)
		return (0);
	len = ft_charp_len(tmp);
	stack->a = (int *)malloc(sizeof(int) * len);
	if (!stack->a)
		return (ft_error());
	stack->a_len = len;
	while (++i < len)
	{
		tmpn = ft_atoi_int(tmp[i]);
		if (tmpn == INT_ERROR)
			return (ft_error());
		stack->a[len - i - 1] = tmpn;
	}
	return (0);
}

int	stack_init1(int argc, char **argv, t_stack *stack)
{
	long long	tmpn;
	long long	i;

	i = -1;
	stack->a = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack->a)
		return (ft_error());
	stack->a_len = argc - 1;
	while (++i < argc - 1)
	{
		tmpn = ft_atoi_int(argv[i + 1]);
		if (tmpn == INT_ERROR)
			return (ft_error());
		stack->a[stack->a_len - i - 1] = tmpn;
	}
	return (0);
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (stack_init2(argv, &stack))
			return (1);
	}
	else if (stack_init1(argc, argv, &stack))
		return (1);
	if (stack.a_len == 1)
		return (0);
	stack.b = (int *)malloc(sizeof(int) * stack.a_len);
	if (!stack.b)
		return (1);
	stack.b_len = 0;
	printf("basic\na: ");
	for (int i = 0; i < stack.a_len; i++)
		printf("%d ", stack.a[i]);
	printf("\n\ns_order\na: ");
	s_order(stack.a, stack.a_len);
	for (int i = 0; i < stack.a_len; i++)
		printf("%d ", stack.a[i]);
	printf("\n\ns_order\na: ");
	s_order(stack.a, stack.a_len);
	for (int i = 0; i < stack.a_len; i++)
		printf("%d ", stack.a[i]);
	printf("\n\np_order\na: ");
	p_order(&stack, STACK_B);
	p_order(&stack, STACK_B);
	p_order(&stack, STACK_B);
	for (int i = 0; i < stack.a_len; i++)
		printf("%d ", stack.a[i]);
	printf("\nb: ");
	for (int i = 0; i < stack.b_len; i++)
		printf("%d ", stack.b[i]);
	printf("\n");
	printf("\nr_order\na: ");
	r_order(stack.a, stack.a_len);
	r_order(stack.b, stack.b_len);
	for (int i = 0; i < stack.a_len; i++)
		printf("%d ", stack.a[i]);
	printf("\nb: ");
	for (int i = 0; i < stack.b_len; i++)
		printf("%d ", stack.b[i]);
	printf("\n");
	printf("\nrr_order\na: ");
	rr_order(stack.a, stack.a_len);
	rr_order(stack.b, stack.b_len);
	for (int i = 0; i < stack.a_len; i++)
		printf("%d ", stack.a[i]);
	printf("\nb: ");
	for (int i = 0; i < stack.b_len; i++)
		printf("%d ", stack.b[i]);
	printf("\n");
	return (0);
}
