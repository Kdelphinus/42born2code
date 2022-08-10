/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 01:29:34 by myko              #+#    #+#             */
/*   Updated: 2022/08/10 17:19:40 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ft_cnt, cnt;

	ft_cnt = 0;
	cnt = 0;
	ft_cnt = ft_printf(" NULL %s NULL", NULL);
	printf("\n");
	cnt = printf(" NULL %s NULL", NULL);
	printf("\n");
	printf("ft_printf cnt: %d\n", ft_cnt);
	printf("printf cnt: %d\n", cnt);
}
