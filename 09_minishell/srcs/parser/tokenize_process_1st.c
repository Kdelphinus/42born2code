#include "minishell.h"

void	ft_end_line_fin_hpwtt(t_p_data *pdata, t_word *word, t_env_node *node)
{
	if (word->sq_stt == ON || word->dq_stt == ON)
	{
		ft_syntax_error(pdata, word);
		return ;
	}
	if (word->ex_stt == ON)
		ft_expension_process(pdata, word, node, -1);
	if (word->re_stt == ON && ft_redirection_process(pdata, word) == 1)
		return ;
	ft_handle_present_w_cmd_to_token(pdata, word);
	if (pdata->now->cmd == NULL && pdata->now->redir == NULL
		&& word->ex_idx == -1 && pdata->front->cmd)
	{
		ft_syntax_error(pdata, word);
		return ;
	}
	ft_clear_word_struct(word);
	word->break_flag = ON;
}

void	ft_add_new_token_hpwtt(t_p_data *pdata, t_word *word, t_env_node *node)
{
	t_token	*new_token;	

	if (word->ex_stt == ON)
		ft_expension_process(pdata, word, node, -1);
	if (word->re_stt == ON && ft_redirection_process(pdata, word) == 1)
		return ;
	ft_handle_present_w_cmd_to_token(pdata, word);
	if (pdata->now->cmd == NULL && pdata->now->redir == NULL
		&& word->ex_idx == -1)
	{
		ft_syntax_error(pdata, word);
		return ;
	}
	new_token = (t_token *)malloc_s(sizeof(t_token));
	if (!new_token)
		ft_allocation_error();
	ft_clear_word_struct(word);
	new_token->cmd = NULL;
	new_token->cmd_type = EXTERN_FUNC;
	new_token->redir = NULL;
	new_token->next = NULL;
	pdata->now->next = new_token;
	pdata->now = new_token;
	pdata->pipe_cnt += 1;
}

void	ft_end_quoted_stt(t_p_data *pdata, char *input, \
	t_word *word, t_env_node *node)
{
	char	tmp;

	tmp = *(input + 1);
	if (word->word_idx == -1 && (tmp == ' ' || tmp == '\0' || tmp == '|'))
		ft_handle_present_w_cmd_to_token(pdata, word);
	if (*input == '\'')
		word->sq_stt = OFF;
	else if (*input == '\"')
	{
		if (word->ex_stt == ON)
			ft_expension_process(pdata, word, node, -1);
		word->dq_stt = OFF;
	}
}

void	ft_start_quoted_stt(t_p_data *pdata, char input, \
t_word *word, t_env_node *node)
{
	if (word->ex_stt == ON)
		ft_expension_process(pdata, word, node, -1);
	if (input == '\'')
		word->sq_stt = ON;
	else if (input == '\"')
		word->dq_stt = ON;
}
