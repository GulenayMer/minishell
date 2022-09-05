/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_def.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:29:57 by jrocha            #+#    #+#             */
/*   Updated: 2022/09/05 15:59:05 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_shell	*ms_shell_init(char **env, char **argv, int shlvl)
{
	t_shell	*shell;

	shell = ft_calloc(1, sizeof(t_shell));
	if (shell == NULL)
		return (NULL);
	shell->name = argv[0];
	shell->workenv = ms_env_create_work_env(shell, env);
	if (shell->workenv == NULL)
		ms_shell_cleanup(shell);
	shell->env = ms_env_init_env(shell);
	if (shell->env == NULL)
		ms_shell_cleanup(shell);
	shell->argv = argv;
	shell->shlvl = shlvl;
	ms_change_lvl(shell);
	shell->exitcode = 0;
	return (shell);
}

// CONTROLL NULL WHAT IF PATH IS NULL NEEDS TO BE FREED AT END?
char	**ms_cmd_path_creator(t_shell *shell)
{
	t_envvar	*line;
	t_node		*node;
	char		**path;


	path = NULL;
	node = ms_env_find_entry(shell->workenv, "PATH=");
	if (node == NULL)
	{
		path = ft_calloc(2, sizeof(char *));
		if (path == NULL)
			return (NULL);
		path[0] = ft_strdup(" ");
		path[1] = NULL;
	}
	else
	{
		line = (t_envvar *) node->data;
		if (line != NULL)
			path = ft_split(line->value, ':');
	}
	return (path);
}

t_cmd	*ms_cmd_init(t_shell *shell)
{
	t_cmd	*cmd;
	char	*prompt;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (cmd == NULL)
	{
		shell->exitcode = ALLOCATION_PROBLEM_EXIT;
		return (NULL);
	}
	cmd->path = ms_cmd_path_creator(shell);
	cmd->cmd_idx = 0;
	cmd->changes_state = 1;
	prompt = ms_prompt(shell);
	if (prompt == NULL)
		return (NULL);
	cmd->line = readline(prompt);
	free(prompt);
	shell->exitcode = EXIT_SUCCESS;
	return (cmd);
}
