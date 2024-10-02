#include "minishell.h"

static int	handle_redir_input(t_redir *redir)
{
	int	fd;

	fd = open(redir->file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(redir->file_name, STDERR_FILENO);
		if (!access(redir->file_name, F_OK))
			ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		else
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		return (FALSE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (TRUE);
}

static int	handle_redir_here(t_redir *redir)
{
	dup2(redir->heredoc_fd, STDIN_FILENO);
	close(redir->heredoc_fd);
	return (TRUE);
}

static int	handle_redir_output(t_redir *redir)
{
	int	fd;

	if (access(redir->file_name, W_OK) && !access(redir->file_name, F_OK))
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(redir->file_name, STDERR_FILENO);
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		return (FALSE);
	}
	fd = open(redir->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(redir->file_name, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		return (FALSE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (TRUE);
}

static int	handle_redir_append(t_redir *redir)
{
	int	fd;

	if (access(redir->file_name, W_OK) && !access(redir->file_name, F_OK))
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(redir->file_name, STDERR_FILENO);
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		return (FALSE);
	}
	fd = open(redir->file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(redir->file_name, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		return (FALSE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (TRUE);
}

int	handle_redir(t_redir *redir)
{
	int	flag;

	while (redir != NULL)
	{
		if (redir->type == RE_INPUT)
			flag = handle_redir_input(redir);
		else if (redir->type == RE_OUTPUT)
			flag = handle_redir_output(redir);
		else if (redir->type == RE_APPEND)
			flag = handle_redir_append(redir);
		else if (redir->type == RE_HERE)
			flag = handle_redir_here(redir);
		if (flag == FALSE)
			return (FALSE);
		redir = redir->next;
	}
	return (TRUE);
}
