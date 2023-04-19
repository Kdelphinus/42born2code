#include "minishell.h"

void	ft_allocation_error(void)
{
	write(2, "Allocation Error!\n", 18);
	exit(1);
}

void	ft_open_error(void)
{
	write(2, "Open system call Error!\n", 24);
	exit(1);
}
