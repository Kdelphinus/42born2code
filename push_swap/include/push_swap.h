/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:14 by myko              #+#    #+#             */
/*   Updated: 2022/12/27 00:32:58 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft.h"

# define INT_ERROR 2147483648

typedef struct s_stack {
	long long	a_len;
	long long	b_len;
	long long	arr_len;
	int			*a;
	int			*b;
	int			*arr;
}	t_stack;

typedef struct s_pivots {
	int	one;
	int two;
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_pivots;

typedef struct s_llist {
	char			*order;
	struct s_llist	*next;
}	t_llist;

typedef enum s_stack_num {
	STACK_A = 0,
	STACK_B,
	S_ORDER,
	R_ORDER,
	RR_ORDER,
	DOUBLE_ORDER,
}	t_stack_num;

// utils.c
int			ft_error(void);
int			is_duplication(int *arr, int num);
long long	ft_charp_len(char **charpoint);

// stack_init.c
int			stack_init1(int argc, char **argv, t_stack *stack);
int			stack_init2(char **argv, t_stack *stack);
void		arr_init(t_stack *stack, int len, int flag);

// find_order.c
void		find_order(t_stack *stack);
void		a_to_b(t_stack *stack, int r);
void		b_to_a(t_stack *stack, int r);

// quick_sort.c
void		quick_sort(int *arr, int left, int right);

// ft_atoi_int.c
long long	ft_atoi_int(const char *str);

// order.c
void		s_order(int *stack, long long len, int flag);
void		p_order(t_stack *stack, long long goal, t_pivots *pivots);
void		r_order(int *stack, long long len, int flag, t_pivots *pivots);
void		rr_order(int *stack, long long len, int flag);
void		double_order(t_stack *stack, int order, t_pivots *pivots);

#endif
