/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:40:41 by myko              #+#    #+#             */
/*   Updated: 2022/08/10 17:30:55 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

// ft_printf.c
int		ft_printf(const char *format, ...);

// ft_printf_utils.c
int		ft_chr_count(const char *str, char chr);
int		ft_nbr_count(int num);

// ft_printf_write.c
int		write_c(va_list ap);
int		write_s(va_list ap);
int		write_d(va_list ap);

#endif
