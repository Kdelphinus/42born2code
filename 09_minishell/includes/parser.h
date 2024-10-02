#ifndef PARSER_H
# define PARSER_H

# define PATH_MAX 4096
# define ARG_MAX 262144
# define ON 1
# define OFF 0
# define HERE_DOC_SIGINT -123

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
}	t_env_node;

typedef enum e_type
{
	RE_INPUT,
	RE_HERE,
	RE_OUTPUT,
	RE_APPEND,
}	t_type;

typedef enum e_c_type
{
	EXTERN_FUNC,
	ECHO_FUNC,
	CD_FUNC,
	PWD_FUNC,
	EXPORT_FUNC,
	UNSET_FUNC,
	ENV_FUNC,
	EXIT_FUNC
}	t_c_type;

typedef struct s_redir
{
	t_type			type;
	char			file_name[PATH_MAX];
	int				heredoc_fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_token
{
	char			**cmd;
	t_c_type		cmd_type;
	t_redir			*redir;
	struct s_token	*next;
}	t_token;

typedef struct s_p_data
{
	int				pipe_cnt;
	struct s_token	*front;
	struct s_token	*now;
}	t_p_data;

typedef struct s_word
{
	int			sq_stt;
	int			dq_stt;
	int			ex_stt;
	int			ex_idx;
	int			re_stt;
	int			re_idx;
	int			tmp_num;
	int			break_flag;
	char		word[ARG_MAX];
	int			word_idx;
}	t_word;

void	parsing(char *input, t_p_data *pdata, t_env_node *head);

void	tokenize(char **input, t_p_data *pdata, t_word *word, t_env_node *head);
void	ft_clear_word_struct(t_word *word);
void	ft_handle_present_w_cmd_to_token(t_p_data *pdata, t_word *word);

void	ft_end_line_fin_hpwtt(t_p_data *pdata, t_word *word, t_env_node *node);
void	ft_add_new_token_hpwtt(t_p_data *pdata, t_word *word, t_env_node *node);
void	ft_end_quoted_stt(t_p_data *pdata, char *input, \
			t_word *word, t_env_node *node);
void	ft_start_quoted_stt(t_p_data *pdata, char input, \
			t_word *word, t_env_node *node);

void	ft_start_expansion_stt(t_p_data *pdata, char **input, \
			t_word *word, t_env_node *head);
void	ft_expension_process(t_p_data *pdata, t_word *word, \
			t_env_node *node, int i);
void	ft_start_redirect_stt(t_p_data *pdata, char input, \
			t_word *word, t_env_node *node);
int		ft_redirection_process(t_p_data *pdata, t_word *word);

void	ft_handle_comment(t_word *word);
void	ft_clean_new_word_hpwtt(t_p_data *data, t_word *word, t_env_node *head);
void	ft_add_or_start_new_char_in_word(t_p_data *pdata, char input, \
			t_word *word, t_env_node *node);
int		ft_redirect_here_doc(t_p_data *pdata, t_redir *new, t_word *word);
void	ft_here_doc_acting(t_redir *new, char *tmp);
void	ft_allocation_error(void);
void	ft_syntax_error(t_p_data *pdata, t_word *word);
void	ft_open_error(void);
void	ft_clear_all_pdata(t_p_data *pdata);

void	signal_handler(int sig);
void	signal_handler_for_parent(int sig);
void	signal_handler_for_heredoc(int sig);
void	ft_signal_init(void);
void	ft_signal_child(void);

#endif