#include "minishell.h"

static void	ft_find_cmd_type(t_p_data *pdata, char *new_word, int i);

static int	ft_pointers_len(char **input)
{
	int	i;

	i = 0;
	if (input == NULL)
		return (0);
	while (input[i])
		++i;
	return (i);
}

void	ft_clear_word_struct(t_word *word)
{
	word->dq_stt = OFF;
	word->sq_stt = OFF;
	word->ex_stt = OFF;
	word->ex_idx = -1;
	word->re_stt = OFF;
	word->re_idx = 0;
	word->word_idx = -1;
	word->break_flag = OFF;
	ft_memset(word->word, '\0', ARG_MAX);
}

void	ft_handle_present_w_cmd_to_token(t_p_data *pdata, t_word *word)
{
	char	**new_cmd;
	char	**temp;
	char	*new_word;
	int		i;

	if (word->word[0] == '\0' && word->sq_stt == OFF && word->dq_stt == OFF)
		return ;
	new_cmd = (char **)malloc_s(sizeof(char *) * \
		(ft_pointers_len(pdata->now->cmd) + 2));
	i = -1;
	while (++i < ft_pointers_len(pdata->now->cmd))
		new_cmd[i] = (pdata->now->cmd)[i];
	new_word = ft_strdup_s(word->word);
	if (i == 0)
		ft_find_cmd_type(pdata, new_word, -1);
	new_cmd[i] = new_word;
	new_cmd[i + 1] = NULL;
	temp = pdata->now->cmd;
	pdata->now->cmd = new_cmd;
	free_s(temp);
}

static void	ft_find_cmd_type(t_p_data *pdata, char *new_word, int i)
{
	char	*tmp;

	tmp = ft_strdup_s(new_word);
	while (tmp[++i])
		tmp[i] = ft_tolower(tmp[i]);
	if (!ft_strcmp(tmp, "echo"))
		pdata->now->cmd_type = ECHO_FUNC;
	else if (!ft_strcmp(tmp, "cd"))
		pdata->now->cmd_type = CD_FUNC;
	else if (!ft_strcmp(tmp, "pwd"))
		pdata->now->cmd_type = PWD_FUNC;
	else if (!ft_strcmp(tmp, "export"))
		pdata->now->cmd_type = EXPORT_FUNC;
	else if (!ft_strcmp(tmp, "unset"))
		pdata->now->cmd_type = UNSET_FUNC;
	else if (!ft_strcmp(tmp, "env"))
		pdata->now->cmd_type = ENV_FUNC;
	else if (!ft_strcmp(tmp, "exit"))
		pdata->now->cmd_type = EXIT_FUNC;
	else
		pdata->now->cmd_type = EXTERN_FUNC;
	free_s(tmp);
}

void	ft_clear_all_pdata(t_p_data *pdata)
{
	t_redir	*tmp;
	int		i;

	pdata->pipe_cnt = 0;
	while (pdata->front)
	{
		pdata->now = pdata->front;
		while (pdata->front->redir)
		{
			tmp = pdata->front->redir;
			pdata->front->redir = pdata->front->redir->next;
			free_s(tmp);
		}
		if (pdata->front->cmd)
		{
			i = -1;
			while (pdata->front->cmd[++i])
				free_s(pdata->front->cmd[i]);
			free_s(pdata->front->cmd);
		}
		pdata->front = pdata->front->next;
		free_s(pdata->now);
	}
	pdata->now = NULL;
}
