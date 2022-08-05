#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	cnt;

	cnt = ft_printf("42 seoul %c %c\n", 'k', 'o');
	printf("ft_printf cnt: %d\n", cnt);
	cnt = printf("42 seoul %c %c\n", 'k', 'o');
	printf("printf cnt: %d\n", cnt);
}
