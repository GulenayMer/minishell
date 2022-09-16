/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:22:34 by mgulenay          #+#    #+#             */
/*   Updated: 2022/09/15 21:31:22 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char **prepare_lexer(char **lexer);
/* count number of words in a string */
/* static int	count_words(char *str)
{
	int		i;
	int		nb_words;
	char	c;

 	if (ft_strlen(str) > 0)
		c = str[0];
	nb_words = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == ' ' || str[i] == '\t') && c != ' ')
			nb_words += 1;
		c = str[i];
		i++;
	}
	return (nb_words);
} */

/* print number of words in each lexer[nb_cmd] */
/* void	print_nb_words(t_shell *shell)
{
	int j;
	int c;

	j = 0;
	while (j < shell->cmd->n_cmd)
	{
		c = count_words(shell->lexer[j]);
		printf("index [%d] has [%d] words\n", j, c);
		j++;
	}
} */

static int	ms_is_in_quotes(char *str, size_t idx, int c)
{
	int		quotes_flag;
	int		index;
	size_t	i;

	i = 0;
	quotes_flag = 0;
	index = 0;
	while (i < idx)
	{
		if ((str[i] == SQ || str[i] == DQ) && quotes_flag == 0)
		{
			quotes_flag = 1;
			break ;
		}
		i++;
	}
	i++;
	while (i < ft_strlen(str))
	{
		if ((str[i] == SQ || str[i] == DQ) && quotes_flag == 1)
		{
			index += i;
			quotes_flag = 0;
			break ;
		}
		i++;
	}
	i = index - 1;
	while (i < ft_strlen(str))
	{
		if (str[i] == c && quotes_flag == 0)
		{
			quotes_flag = 1;
			break ;
		}
		i--;
	}
	return (quotes_flag);
}

char	*remove_white_spaces(char *str)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	while (str[i] != '\0')
	{
		if ((str[i] == ' ' && str[i + 1] == ' ') != 0
			&& ms_is_in_quotes(str, i, ' ') == 0)
		{
			i++;
			continue ;
		}
		new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	str = ft_strdup(new_str);
	free(new_str);
	return (str);
}

static char	**break_quotes(t_shell *shell, char *str)
{
	int		i;
	int		j;
	int		k;
	char	**new;
	int		count;

	i = 0;
	j = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && ms_is_in_quotes(str, i, str[i]) == 0)
			count++;
		i++;
	}
	new = ft_calloc(count + 1, sizeof(char *));
	if (new == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (k < count)
	{
		if ((str[i] == ' ' && ms_is_in_quotes(str, i, ' ') == 0)
			|| str[i] == '\0')
		{
			new[k] = ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(new[k], &str[i - j], j + 1);
			new[k] = (char *)ms_dollar_check(shell, new[k]);
			new[k] = check_quotes_pre_lexer(new[k]);
			k++;
			j = -1;
		}
		j++;
		i++;
	}
	new[k] = NULL;
	return (new);
}

/* char	**get_each_word(char *str)
{
	char	**words;
	int		len;
	int		num_words;
	size_t	i;
	size_t	num_chars;

	len = count_words(str);
	num_words = 0;
	num_chars = 0;
	i = 0;
	words = ft_calloc(len + 1, sizeof(char *));
	while (num_words < len)
	{
		words[num_words] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			words[num_words][num_chars] = str[i];
			num_chars += 1;
			i++;
		}
		if(str[i] == ' ' || str[i] == '\t' || num_chars == ft_strlen(&str[i]))
		{
			words[num_words][num_chars] = '\0';
			num_chars = 0;
		}
		i++;
		num_words++;
	}
	words[num_words] = NULL;
	return (words);
} */
/* {
	char	**words;
	int		len;
	size_t	i;

	len = count_words(str);
	int num_words = 0;
	size_t num_chars = 0;
	i = 0;
	words = ft_calloc(len + 1, sizeof(char *));
	while (num_words < len)
	{
		words[num_words] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			words[num_words][num_chars] = str[i];
			num_chars += 1;
			i++;
		}
		if(str[i] == ' ' || str[i] == '\t' || num_chars == ft_strlen(&str[i]))
		{
			words[num_words][num_chars] = '\0';
			num_chars = 0;
		}
		i++;
		num_words++;
	}
	words[num_words] = NULL;
	return (words);
} */

static char	**prepare_lexer(char **lexer)
{
	int		len;
	int		i;
	char	**new;

	i = 0;
	len = ms_args_len(lexer);
	new = ft_calloc(len + 1, sizeof(char *));
	while (i < len)
	{
		new[i] = remove_white_spaces(lexer[i]);
		i += 1;
	}
	ms_free_args(lexer);
	return (new);
}

char	***create_seq_from_lexer(t_shell *shell)
{
	int	j;

	j = 0;
	shell->lexer = prepare_lexer(shell->lexer);
	shell->cmd->seq = ft_calloc(ms_args_len(shell->lexer) + 1, sizeof(char *));
	while (j < shell->cmd->n_cmd)
	{
		shell->cmd->seq[j] = break_quotes(shell, shell->lexer[j]);
		j++;
	}
	shell->cmd->seq[j] = NULL;
	return (shell->cmd->seq);
}
