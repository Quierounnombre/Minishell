/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:57:56 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/15 19:13:04 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	is_built_in(t_shell *shell)
{
	t_cmd	*cmd;

	cmd = shell->cmds->current->content;
	if (!ft_strchr(cmd->filepath, '/'))
	{
		if (ft_strcmp(cmd->filepath, "echo"))
			return (true);
		if (ft_strcmp(cmd->filepath, "cd"))
			return (true);
		if (ft_strcmp(cmd->filepath, "pwd"))
			return (true);
		if (ft_strcmp(cmd->filepath, "export"))
			return (true);
		if (ft_strcmp(cmd->filepath, "unset"))
			return (true);
		if (ft_strcmp(cmd->filepath, "env"))
			return (true);
		if (ft_strcmp(cmd->filepath, "exit"))
			return (true);
	}
	return (false);
}