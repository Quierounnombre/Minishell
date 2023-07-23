/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:21:06 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/23 18:03:48 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_build_in(t_cmd *cmd, t_shell *shell)
{
	if (ft_strcmp(cmd->argv[0], "echo"))//funciona
		echo(cmd);
	if (ft_strcmp(cmd->argv[0], "cd"))//no funciona
		ft_cd(cmd->argv[1], shell);
	if (ft_strcmp(cmd->argv[0], "pwd"))//funciona
		ft_pwd(shell->env);
	if (ft_strcmp(cmd->argv[0], "export"))//falta export sin argumentos
		do_export(cmd, shell);
	if (ft_strcmp(cmd->argv[0], "unset"))//funciona
		do_unset(cmd, shell);
	if (ft_strcmp(cmd->argv[0], "env"))//funciona
		ft_env(shell->env);
	if (ft_strcmp(cmd->argv[0], "exit"))//funciona pero faltan cosas del $?
		ft_exit(shell);
}
