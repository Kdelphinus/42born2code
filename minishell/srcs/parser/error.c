#include "minishell.h"

void	ft_syntax_error(t_p_data *pdata, t_word *word)
{
	write(2, "syntax Error!\n", 14);
	word->break_flag = ON;
	ft_clear_all_pdata(pdata);
}
