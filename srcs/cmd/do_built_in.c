/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:21:06 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/15 19:44:06 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_build_in(t_shell *shell)
{
	t_cmd	*cmd;

	cmd = shell->cmds->current->content;
	if (!ft_strchr(cmd->filepath, '/'))
	{
		if (ft_strcmp(cmd->filepath, "echo"))
			echo(shell);
		if (ft_strcmp(cmd->filepath, "cd"))
			echo(shell);
		if (ft_strcmp(cmd->filepath, "pwd"))
			echo(shell);
		if (ft_strcmp(cmd->filepath, "export"))
			echo(shell);
		if (ft_strcmp(cmd->filepath, "unset"))
			echo(shell);
		if (ft_strcmp(cmd->filepath, "env"))
			echo(shell);
		if (ft_strcmp(cmd->filepath, "exit"))
			echo(shell);
	}
}
