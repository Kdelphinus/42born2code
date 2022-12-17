/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:24:46 by myko              #+#    #+#             */
/*   Updated: 2022/12/17 20:16:09 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_llist	stack_sort(t_stack *stack)
{
	t_llist	orders;

	stack->a_len = 0;
	orders.order = malloc(sizeof(char) * 4);
	orders.order = "sa";
	orders.next = 0;
	return (orders);
}
