/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:48:33 by myko              #+#    #+#             */
/*   Updated: 2023/01/05 21:59:05 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

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
	int	two;
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

// order_bonus.c
void	s_order(int *stack, long long len, int flag);
void	p_order(t_stack *stack, int goal, t_pivots *pivots);
void	r_order(int *stack, long long len, int flag, t_pivots *pivots);
void	rr_order(int *stack, long long len, int flag);
void	double_order(t_stack *stack, int order, t_pivots *pivots);

// get_next_line_bonus.c
char	*get_next_line(int fd);

// get_next_line_utils_bonus.c
int		ft_strlen(const char *s);
char	*ft_strljoin(char *s1, char *s2, int s2_len);
int		ft_strchr(char *s, char c);
char	*ft_strdup(char *s1);
char	*char_free(char **line, char **c_line);

#endif