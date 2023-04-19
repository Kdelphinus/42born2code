#include "minishell.h"

void	ft_handle_comment(t_word *word)
{
	word->break_flag = ON;
}

void	ft_clean_new_word_hpwtt(t_p_data *pdata, t_word *word, t_env_node *node)
{
	if (word->ex_stt == ON)
		ft_expension_process(pdata, word, node, -1);
	if (word->re_stt == ON)
	{
		if (!ft_strcmp(word->word + word->re_idx, ">")
			|| !ft_strcmp(word->word + word->re_idx, "<")
			|| !ft_strcmp(word->word + word->re_idx, ">>")
			|| !ft_strcmp(word->word + word->re_idx, "<<"))
			return ;
		if (ft_redirection_process(pdata, word) == 1)
			return ;
	}
	ft_handle_present_w_cmd_to_token(pdata, word);
	ft_clear_word_struct(word);
}

void	ft_add_or_start_new_char_in_word(t_p_data *pdata, char input, \
t_word *word, t_env_node *node)
{
	if (word->ex_stt == ON && input != '_' && !ft_isalnum(input))
		ft_expension_process(pdata, word, node, -1);
	word->word[++(word->word_idx)] = input;
}
