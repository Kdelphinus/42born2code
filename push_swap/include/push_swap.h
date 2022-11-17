/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:14 by myko              #+#    #+#             */
/*   Updated: 2022/11/17 17:52:39 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft.h"

# define INT_ERROR 2147483648

typedef struct s_stack {
	long long	a_len;
	long long	b_len;
	int			*a;
	int			*b;
}	t_stack;

typedef enum s_stack_num {
	STACK_A = 0,
	STACK_B,
}	t_stack_num;

// ft_atoi_int.c
long long	ft_atoi_int(const char *str);

// order.c
void		s_order(int *stack, long long len);
void		p_order(t_stack *stack, long long goal);
void		r_order(int *stack, long long len);
void		rr_order(int *stack, long long len);

#endif
