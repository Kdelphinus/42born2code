/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:37:26 by myko              #+#    #+#             */
/*   Updated: 2022/08/10 21:39:25 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	cnt;
	int	ft_cnt;

	ft_cnt = 0;
	cnt = 0;
	ft_cnt = ft_printf(" %p ", 16);
	printf("\n");
	cnt = ft_printf(" %p ", 16);
	printf("\n");
	printf("ft_printf cnt: %d\n", ft_cnt);
	printf("printf cnt: %d\n", cnt);
}
