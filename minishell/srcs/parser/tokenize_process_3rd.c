#include "minishell.h"

static void	ft_append_new_redirect_struct(t_p_data *pdata);
static int	ft_put_re_put_del_word(t_p_data *pdata, t_redir *new, \
t_word *word, int tmp_idx);

void	ft_start_redirect_stt(t_p_data *pdata, char input, \
	t_word *word, t_env_node *node)
{
	if (word->re_stt == ON && word->re_idx != word->word_idx
		&& ft_redirection_process(pdata, word) == 1)
		return ;
	if (word->ex_stt == ON)
		ft_expension_process(pdata, word, node, -1);
	(word->word)[++(word->word_idx)] = input;
	if (word->re_stt == OFF)
		word->re_idx = word->word_idx;
	word->re_stt = ON;
}

int	ft_redirection_process(t_p_data *pdata, t_word *word)
{
	t_redir	*new;
	int		tmp_idx;

	ft_append_new_redirect_struct(pdata);
	new = pdata->now->redir;
	while (new->next)
		new = new->next;
	tmp_idx = word->re_idx;
	if (word->word[word->re_idx] == '<')
	{
		if (word->word[++(word->re_idx)] == '<')
			new->type = RE_HERE;
		else
			new->type = RE_INPUT;
	}
	else if (word->word[++(word->re_idx)] == '>')
		new->type = RE_APPEND;
	else
		new->type = RE_OUTPUT;
	word->re_stt = OFF;
	if (new->type == RE_HERE)
		return (ft_redirect_here_doc(pdata, new, word));
	return (ft_put_re_put_del_word(pdata, new, word, tmp_idx));
}

static void	ft_append_new_redirect_struct(t_p_data *pdata)
{
	t_redir	*tmp;

	if (pdata->now->redir == NULL)
	{
		pdata->now->redir = (t_redir *)malloc_s(sizeof(t_redir));
		if (!pdata->now->redir)
			ft_allocation_error();
		pdata->now->redir->next = NULL;
		pdata->now->redir->heredoc_fd = -1;
		ft_memset(pdata->now->redir, '\0', PATH_MAX);
	}
	else
	{
		tmp = pdata->now->redir;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (t_redir *)malloc_s(sizeof(t_redir));
		if (!tmp->next)
			ft_allocation_error();
		tmp->next->next = NULL;
		ft_memset(tmp->next, '\0', PATH_MAX);
	}
}

static int	ft_is_right_redirection(t_p_data *pdata, t_word *word)
{
	char	c;

	c = word->word[word->re_idx];
	if (c == '`' || c == '&' || c == '(' || c == ')' || c == '<'
		|| c == '>' || c == '\0')
		ft_syntax_error(pdata, word);
	else if (c == '*' && word->word[word->re_idx + 1] == '\0')
		ft_syntax_error(pdata, word);
	else
		return (0);
	return (1);
}

static int	ft_put_re_put_del_word(t_p_data *pdata, t_redir *new, \
t_word *word, int tmp_idx)
{
	if (new->type == RE_APPEND)
		word->re_idx += 1;
	if (new->type != RE_HERE)
	{
		if (ft_is_right_redirection(pdata, word) == 1)
			return (1);
		ft_strlcpy(new->file_name, word->word + word->re_idx, PATH_MAX);
	}
	while (tmp_idx <= word->word_idx)
	{
		word->word[tmp_idx] = '\0';
		tmp_idx += 1;
	}
	return (0);
}
