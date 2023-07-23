/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:21:06 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 20:57:53 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_build_in(t_cmd *cmd, t_shell *shell)
{
	if (ftt_strcmp(cmd->argv[0], "echo"))//funciona
		echo(cmd);
	if (ftt_strcmp(cmd->argv[0], "cd"))
		ft_cd(cmd->argv[1], shell);
	if (ftt_strcmp(cmd->argv[0], "pwd"))//funciona
		ft_pwd(shell->env);
	if (ftt_strcmp(cmd->argv[0], "export"))
		ft_export(shell, cmd->argv[1]);
	if (ftt_strcmp(cmd->argv[0], "unset"))
		ft_unset(shell, cmd->argv[1]);
	if (ftt_strcmp(cmd->argv[0], "env"))//funciona
		ft_env(shell->env);
	if (ftt_strcmp(cmd->argv[0], "exit"))//funciona pero faltan cosas del $?
		ft_exit(shell);
}
