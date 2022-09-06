/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha <jrocha@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:31:35 by jrocha            #+#    #+#             */
/*   Updated: 2022/09/06 10:35:26 by jrocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ms_free_seq(t_cmd *cmd)
{
	int	i;

	i = cmd->n_cmd - 1;
	while (i >= 0)
	{
		ms_free_args(cmd->seq[i]);
		i -= 1;
	}
	free(cmd->seq);
}

void	ms_free_args(char **args)
{
	int	i;

	i = ms_args_len(args) - 1;
	while (i >= 0)
	{
		if (args[i] != NULL)
			free(args[i]);
		i -= 1;
	}
	free(args);
}

int	ms_cmd_cleanup(t_cmd *cmd)
{
	if (cmd->line != NULL)
		free(cmd->line);
	if (cmd->cmd_name != NULL)
		free(cmd->cmd_name);
	if (cmd->seq != NULL)
		ms_free_seq(cmd);
	if (cmd->path != NULL)
		ms_free_args(cmd->path);
	if (cmd->curr_cmd != NULL)
		ms_free_args(cmd->curr_cmd);
	if (cmd->heredoc == 1)
		unlink("heredoc_aux.txt");
	close(cmd->pfd[0]);
	close(cmd->pfd[1]);
	close(cmd->temp_fd[0]);
	close(cmd->temp_fd[1]);
	free(cmd);
	return (EXIT_SUCCESS);
}

int	ms_shell_cleanup(t_shell *shell)
{
	if (shell->cmd != NULL)
		ms_cmd_cleanup(shell->cmd);
	if (shell->env != NULL)
		ms_free_args(shell->env);
	if (shell->workenv != NULL)
	{
		ms_list_data_cleaner(shell->workenv);
		list_destroyer(shell->workenv);
	}
	rl_clear_history();
	if (shell != NULL)
		free(shell);
	return (EXIT_SUCCESS);
}
