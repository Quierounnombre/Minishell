/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:57:56 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/21 21:45:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	is_built_in(t_cmd *cmd)
{
	if (cmd->argv[0] && !ft_strchr(cmd->argv[0], '/'))//no todos los built_in estan en el PATH, asi que algunos filepath estaran vacios
	{
		if (!ft_strcmp(cmd->argv[0], "echo"))
			return (true);
		if (!ft_strcmp(cmd->argv[0], "cd"))
			return (true);
		if (!ft_strcmp(cmd->argv[0], "pwd"))
			return (true);
		if (!ft_strcmp(cmd->argv[0], "export"))
			return (true);
		if (!ft_strcmp(cmd->argv[0], "unset"))
			return (true);
		if (!ft_strcmp(cmd->argv[0], "env"))
			return (true);
		if (!ft_strcmp(cmd->argv[0], "exit"))
			return (true);
	}
	return (false);
}
