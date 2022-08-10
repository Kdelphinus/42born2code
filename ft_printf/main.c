/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:37:26 by myko              #+#    #+#             */
/*   Updated: 2022/08/10 22:11:53 by myko             ###   ########.fr       */
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
	ft_cnt = ft_printf("st/%pEgS<5rJ%sQ@+&L9)\rb%u%c!gf&~>Yb%Xk_*7&*)G8J%unqtr", (void
*)3300262879852515529, "Fy%B-V", 1991101000, -670111564, -107544612, 1582430379);
	printf("\n");
	cnt = printf("st/%pEgS<5rJ%sQ@+&L9)\rb%u%c!gf&~>Yb%Xk_*7&*)G8J%unqtr", (void
*)3300262879852515529, "Fy%B-V", 1991101000, -670111564, -107544612, 1582430379);
	printf("\n");
	printf("ft_printf cnt: %d\n", ft_cnt);
	printf("printf cnt: %d\n", cnt);
}
