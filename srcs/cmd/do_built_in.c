/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:21:06 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/06 14:43:31 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_build_in(t_cmd *cmd, t_shell *shell)
{
	if (!ft_strchr(cmd->filepath, '/'))
	{
		if (ft_strcmp(cmd->filepath, "echo"))
			echo(cmd);
		if (ft_strcmp(cmd->filepath, "cd"))
			ft_cd(cmd->argv[1], shell);
		if (ft_strcmp(cmd->filepath, "pwd"))
			ft_pwd(shell->env);
		if (ft_strcmp(cmd->filepath, "export"))
			ft_export(shell, cmd->argv[1]);
		if (ft_strcmp(cmd->filepath, "unset"))
			ft_unset(shell, cmd->argv[1]);
		if (ft_strcmp(cmd->filepath, "env"))
			ft_env(shell->env);
		if (ft_strcmp(cmd->filepath, "exit"))
			ft_exit(shell);
	}
}
