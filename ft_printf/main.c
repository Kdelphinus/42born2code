/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 01:29:34 by myko              #+#    #+#             */
/*   Updated: 2022/08/10 20:52:47 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	ft_cnt, cnt;

	ft_cnt = 0;
	cnt = 0;
	ft_cnt = ft_printf(" %X %X %X", -0, -420, -42);
	printf("\n");
	cnt = printf(" %X %X %X", -0, -420, -42);
	printf("\n");
	printf("ft_printf cnt: %d\n", ft_cnt);
	printf("printf cnt: %d\n", cnt);
}
