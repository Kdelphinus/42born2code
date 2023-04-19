#include "minishell.h"

static void	ft_init_token_word(t_p_data *pdata, t_word *word)
{
	pdata->now = pdata->front;
	pdata->pipe_cnt = 0;
	pdata->front->cmd = NULL;
	pdata->front->cmd_type = EXTERN_FUNC;
	pdata->front->redir = NULL;
	pdata->front->next = NULL;
	ft_clear_word_struct(word);
	word->tmp_num = 0;
}

void	parsing(char *input, t_p_data *pdata, t_env_node *head)
{
	t_word	word;

	pdata->front = (t_token *)malloc(sizeof(t_token));
	if (!pdata->front)
		ft_allocation_error();
	ft_init_token_word(pdata, &word);
	while (word.break_flag == OFF)
	{
		tokenize(&input, pdata, &word, head);
		++input;
	}
}

void	tokenize(char **input, t_p_data *pdata, t_word *word, t_env_node *head)
{
	if (**input == '\0')
		ft_end_line_fin_hpwtt(pdata, word, head);
	else if (word->dq_stt == OFF && word->sq_stt == OFF && **input == '|')
		ft_add_new_token_hpwtt(pdata, word, head);
	else if ((word->sq_stt == ON && **input == '\'')
		|| (word->dq_stt == ON && **input == '\"'))
		ft_end_quoted_stt(pdata, *input, word, head);
	else if ((word->sq_stt == OFF && word->dq_stt == OFF)
		&& (**input == '\'' || **input == '\"'))
		ft_start_quoted_stt(pdata, **input, word, head);
	else if (word->sq_stt == OFF && **input == '$')
		ft_start_expansion_stt(pdata, input, word, head);
	else if (word->dq_stt == OFF && word->sq_stt == OFF
		&& (**input == '<' || **input == '>'))
		ft_start_redirect_stt(pdata, **input, word, head);
	else if (word->dq_stt == OFF && word->sq_stt == OFF && **input == ' ')
		ft_clean_new_word_hpwtt(pdata, word, head);
	else if (**input == '#' && word->word[0] == '\0'
		&& word->dq_stt == OFF && word->sq_stt == OFF)
		ft_handle_comment(word);
	else
		ft_add_or_start_new_char_in_word(pdata, **input, word, head);
}
