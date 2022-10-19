/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:40:41 by myko              #+#    #+#             */
/*   Updated: 2022/08/10 22:31:39 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// ft_printf.c
int		ft_printf(const char *format, ...);

// ft_printf_utils.c
int		ft_nbr_count(long long lnum);
int		ft_convert_base(long long lnum, const char *base, int flag);

// ft_printf_utils_2.c
void	ft_putunnbr(unsigned int num);
int		ft_putptr(unsigned long long ptr);

// ft_printf_write.c
int		write_c(va_list ap);
int		write_s(va_list ap);
int		write_d(va_list ap);
int		write_per(void);

// ft_printf_write_2.c
int		write_x(char fm, va_list ap);
int		write_u(va_list ap);
int		write_p(va_list ap);

#endif
