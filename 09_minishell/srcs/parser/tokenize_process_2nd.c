#include "minishell.h"

void	ft_start_expansion_stt(t_p_data *pdata, char **input, \
t_word *word, t_env_node *node)
{
	int		i;
	char	*tmp;

	i = -1;
	if (word->re_stt == ON && !ft_strncmp(word->word + word->re_idx, "<<", 2))
		(word->word)[++(word->word_idx)] = '$';
	else if (*(*input + 1) == '?')
	{
		(*input) += 1;
		tmp = ft_itoa(g_exit_status);
		while (tmp[++i])
			word->word[++(word->word_idx)] = tmp[i];
		free_s(tmp);
	}
	else
	{
		if (word->ex_stt == ON)
			ft_expension_process(pdata, word, node, -1);
		(word->word)[++(word->word_idx)] = '$';
		word->ex_stt = ON;
		word->ex_idx = word->word_idx;
	}
}

void	ft_expension_process(t_p_data *pdata, t_word *word, \
	t_env_node *node, int i)
{
	char	*tmp;

	while (node)
	{	
		if (ft_strcmp(word->word + word->ex_idx + 1, node->key) == 0)
		{
			tmp = node->value;
			break ;
		}
		node = node->next;
	}
	word->word_idx = word->ex_idx - 1;
	while (word->word[++(word->word_idx)])
		word->word[word->word_idx] = '\0';
	word->word_idx = word->ex_idx - 1;
	word->ex_stt = OFF;
	if (!node || !tmp)
		return ;
	while (tmp[++i])
	{
		if (tmp[i] == ' ')
			ft_clean_new_word_hpwtt(pdata, word, node);
		else
			ft_add_or_start_new_char_in_word(pdata, tmp[i], word, node);
	}
}
