/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:21:06 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 15:57:20 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	do_build_in(t_cmd *cmd, t_shell *shell)
{
	if (!ft_strchr(cmd->argv[0], '/'))
	{
	//	printf("holaaaaaaa1\n");
		//printf("0hola %s\n", cmd->argv[0]);
		if (ft_strcmp(cmd->argv[0], "echo"))
			echo(cmd);
		//printf("1hola %s\n", cmd->argv[0]);
		if (ft_strcmp(cmd->argv[0], "cd"))
			ft_cd(cmd->argv[1], shell);
		//printf("2hola %s\n", cmd->argv[0]);
		if (ft_strcmp(cmd->argv[0], "pwd"))
			ft_pwd(shell->env);
	//	printf("3hola %s\n", cmd->argv[0]);
		if (ft_strcmp(cmd->argv[0], "export"))
			ft_export(shell, cmd->argv[1]);
	//	printf("4hola %s\n", cmd->argv[0]);
		if (ft_strcmp(cmd->argv[0], "unset"))
			ft_unset(shell, cmd->argv[1]);
	//	printf("5hola %s\n", cmd->argv[0]);
		if (ft_strcmp(cmd->argv[0], "env"))
		{
		//	printf("hooooo\n");
			ft_env(shell->env);
		}
		//printf("6hola %s\n", cmd->argv[0]);
		if (ft_strcmp(cmd->argv[0], "exit"))
			ft_exit(shell);
		//printf("7hola %s\n", cmd->argv[0]);
	}
}
