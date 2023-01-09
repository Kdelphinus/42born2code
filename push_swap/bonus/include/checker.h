/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:00:01 by myko              #+#    #+#             */
/*   Updated: 2023/01/09 15:09:24 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../../lib/libft.h"

# define BUFFER_SIZE 1024
# define INT_ERROR 2147483648

typedef struct s_stack {
	long long	a_len;
	long long	b_len;
	long long	arr_len;
	int				*a;
	int				*b;
	int				*arr;
}	t_stack;

typedef enum s_checker_num {
	SORT = 0,
	NOT_SORT,
	S_COMMAND,
	R_COMMAND,
	RR_COMMAND,
	STACK_A,
	STACK_B,
}	t_checker_num;

// stack_init_bonus.c
int			stack_init_checker1(int argc, char **argv, t_stack *stack);
int			stack_init_checker2(char **argv, int flag, t_stack *stack);
void		arr_init_checekr(t_stack *stack, long long len, int flag);

// quick_sort_bonus.c
void		quick_sort_checker(int *arr, long long left, long long right);

// run_commands_bonus.c
void		check_commands(t_stack *stack);

// commands_bonus.c
void		s_command(int *stack, long long len);
void		p_command(t_stack *stack, int goal);
void		r_command(int *stack, long long len);
void		rr_command(int *stack, long long len);
void		double_command(t_stack *stack, int command);

// utils_bonus.c
int			ft_error_checker(void);
int			print_ok(void);
int			print_ko(void);
long long	ft_charp_len(char **charpoint);
int			is_duplication_checker(int *arr, int num);

// ft_atoi_int_bonus.c
long long	ft_atoi_int_checker(const char *str);

// gnl_bonus.c
char		*get_next_line(int fd);

// gnl_utils_bonus.c
int			gnl_strlen(const char *s);
char		*gnl_strljoin(char *s1, char *s2, int s2_len);
int			gnl_strchr(char *s, char c);
char		*gnl_strdup(char *s1);
char		*char_free(char **line, char **c_line);

#endif
