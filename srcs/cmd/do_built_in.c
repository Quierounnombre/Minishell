/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:21:06 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:22:40 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_build_in(t_cmd *cmd, t_shell *shell)
{
	if (ft_strcmp(cmd->argv[0], "echo"))
		echo(cmd);
	if (ft_strcmp(cmd->argv[0], "cd"))
		ft_cd(cmd->argv[1], shell);
	if (ft_strcmp(cmd->argv[0], "pwd"))
		ft_pwd(shell->env);
	if (ft_strcmp(cmd->argv[0], "export"))
		do_export(cmd, shell);
	if (ft_strcmp(cmd->argv[0], "unset"))
		do_unset(cmd, shell);
	if (ft_strcmp(cmd->argv[0], "env"))
		ft_env(shell->env);
	if (ft_strcmp(cmd->argv[0], "exit"))
		ft_exit(shell);
}
