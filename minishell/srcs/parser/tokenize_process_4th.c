#include "minishell.h"

static int	open_heredoc_fd(char *tmp, t_redir *new)
{
	int		i;
	int		fd;
	char	*tmp2;

	i = -1;
	while (access(tmp, F_OK) == 0)
	{
		tmp2 = ft_strdup_s(tmp);
		free_s(tmp);
		tmp = ft_strjoin(tmp2, "1");
		free_s(tmp2);
	}
	fd = open(tmp, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		ft_open_error();
	while (tmp[++i])
		new->file_name[i] = tmp[i];
	free_s(tmp);
	return (fd);
}

static int	ft_here_doc_pretreatment(t_p_data *pdata, \
t_redir *new, t_word *word)
{
	char	*str;
	char	*tmp;
	char	temp;

	word->re_idx += 1;
	temp = word->word[word->re_idx];
	if (temp == '>' || temp == '<' || temp == '(' || temp == ')'
		|| temp == '`' || temp == '&' || temp == '\0')
	{
		ft_syntax_error(pdata, word);
		return (1);
	}
	str = ft_itoa(++(word->tmp_num));
	if (!str)
		ft_allocation_error();
	tmp = ft_strjoin_s("/tmp/.tmp", str);
	free_s(str);
	new->heredoc_fd = open_heredoc_fd(tmp, new);
	return (0);
}

static int	empty_func(void)
{
	return (0);
}

static void	ft_here_doc_act(t_redir *new, char *tmp)
{
	rl_event_hook = &empty_func;
	rl_catch_signals = 0;
	signal(SIGINT, signal_handler_for_heredoc);
	ft_here_doc_acting(new, tmp);
	rl_event_hook = 0;
	rl_done = 0;
	signal(SIGINT, signal_handler);
}

int	ft_redirect_here_doc(t_p_data *pdata, t_redir *new, \
	t_word *word)
{
	char	*tmp;

	if (ft_here_doc_pretreatment(pdata, new, word) == 1)
		return (1);
	tmp = ft_strdup_s(word->word + word->re_idx);
	word->re_idx -= 2;
	while (word->word[word->re_idx])
		word->word[(word->re_idx)++] = '\0';
	ft_here_doc_act(new, tmp);
	close(new->heredoc_fd);
	if (g_exit_status == HERE_DOC_SIGINT)
	{
		free(tmp);
		g_exit_status = 1;
		return (1);
	}
	new->heredoc_fd = open(new->file_name, O_RDONLY);
	if (new->heredoc_fd == -1)
		ft_open_error();
	unlink(new->file_name);
	free_s(tmp);
	return (0);
}
