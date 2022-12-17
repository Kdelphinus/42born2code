/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:14 by myko              #+#    #+#             */
/*   Updated: 2022/12/17 20:14:32 by myko             ###   ########.fr       */
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

typedef struct s_llist {
	char			*order;
	struct s_llist	*next;
}	t_llist;

typedef enum s_stack_num {
	STACK_A = 0,
	STACK_B,
}	t_stack_num;

// utils.c
int			ft_error(void);
void		print_command(t_llist *orders);
long long	ft_charp_len(char **charpoint);

// stack_init.c
int			stack_init1(int argc, char **argv, t_stack *stack);
int			stack_init2(char **argv, t_stack *stack);

// stack_sort.c
t_llist		stack_sort(t_stack *stack);

// ft_atoi_int.c
long long	ft_atoi_int(const char *str);

// order.c
void		s_order(int *stack, long long len);
void		p_order(t_stack *stack, long long goal);
void		r_order(int *stack, long long len);
void		rr_order(int *stack, long long len);

#endif
