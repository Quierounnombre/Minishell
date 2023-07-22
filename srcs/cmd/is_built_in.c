/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:57:56 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 18:34:43 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	is_built_in(t_cmd *cmd)
{
	if (cmd->argv[0])
	{
		if (ft_strcmp(cmd->argv[0], "echo"))
			return (true);
		if (ft_strcmp(cmd->argv[0], "cd"))
			return (true);
		if (ft_strcmp(cmd->argv[0], "pwd"))
			return (true);
		if (ft_strcmp(cmd->argv[0], "export"))
			return (true);
		if (ft_strcmp(cmd->argv[0], "unset"))
			return (true);
		if (ft_strcmp(cmd->argv[0], "env"))
			return (true);
		if (ft_strcmp(cmd->argv[0], "exit"))
			return (true);
	}
	return (false);
}
