/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 01:29:34 by myko              #+#    #+#             */
/*   Updated: 2022/08/06 01:29:36 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	cnt;

	cnt = ft_printf("%d seoul %c %s\n", 42, 'K', "delphinus");
	printf("ft_printf cnt: %d\n", cnt);
	cnt = printf("%d seoul %c %s\n", 42, 'K', "delphiuns");
	printf("printf cnt: %d\n", cnt);
}
