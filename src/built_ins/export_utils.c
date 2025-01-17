/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:50:02 by jrocha            #+#    #+#             */
/*   Updated: 2022/09/21 21:33:10 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_node	*ms_env_find_entry(t_list *env, char *name)
{
	t_node		*node;
	t_node		*search;
	t_envvar	*line;
	int			i;

	node = NULL;
	search = env->first;
	while (search)
	{
		line = (t_envvar *) search->data;
		if (ft_strncmp(&line->name[ft_strlen(line->name) -1], "=", 1) == 0)
			i = 1;
		else
			i = 0;
		if (ft_strncmp(line->name, name, ft_strlen(line->name) - i) == 0)
		{
			node = search;
			break ;
		}
		search = search->next;
	}
	return (node);
}

int	ms_export_order(t_list *env)
{
	t_node		*node;
	t_envvar	*line;
	t_envvar	*nline;
	int			swap;

	swap = 0;
	node = env->first;
	while (node != env->last)
	{
		swap = 0;
		line = (t_envvar *) node->data;
		nline = (t_envvar *) node->next->data;
		if (ft_strncmp(line->name, nline->name,
				ft_short_strlen(line->name, nline->name)) > 0)
		{
			if (ms_env_swap_data(line, nline) == ALLOCATION_PROBLEM_EXIT)
				return (ALLOCATION_PROBLEM_EXIT);
			node = env->first;
			swap = 1;
		}
		if (swap == 0)
			node = node->next;
	}
	return (EXIT_SUCCESS);
}

int	ms_env_swap_data(t_envvar *line, t_envvar *nline)
{
	t_envvar	*temp;

	temp = ft_calloc(1, sizeof(t_envvar));
	if (temp == NULL)
		return (ALLOCATION_PROBLEM_EXIT);
	ft_memmove(temp, line, sizeof(t_envvar));
	ft_memmove(line, nline, sizeof(t_envvar));
	ft_memmove(nline, temp, sizeof(t_envvar));
	free(temp);
	return (EXIT_SUCCESS);
}

int	ms_var_check(t_shell *shell, char *called_from, char *newvar)
{
	int	i;
	int	first_check;
	int	check;

	first_check = 0;
	check = 0;
	i = 0;
	while (newvar[i] != '=' && newvar[i] != '\0')
	{
		if (newvar[i] == '=' || newvar[i] == '%' || newvar[i] == '?'
			|| ft_isdigit(newvar[0]) == 1 || newvar[i] == '-'
			|| newvar[i] == '$')
			first_check = 1;
		if (ft_isdigit(newvar[i]) != 1)
			check = 1;
		i += 1;
	}
	i += 2;
	if (first_check == 1 || check != 1)
	{
		shell->status = 1;
		printf(ERR_INV_ID, called_from, newvar);
		return (-1);
	}
	return (i);
}
