/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:16:01 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/15 16:27:43 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_unset(t_cmd *cmd, t_shell *shell)
{
	int	i;

	i = 1;
	while (cmd->argv[i])
	{
		ft_unset(shell, cmd->argv[i]);
		i++;
	}
}

void	do_export(t_cmd *cmd, t_shell *shell)
{
	int	i;

	i = 1;
	if (cmd->argv[i] == NULL)
		sort_export(shell);
	else
	{
		while (cmd->argv[i])
		{
			if (cmd->argv[i][0] != '=')
				ft_export(shell, cmd->argv[i]);
			i++;
		}
	}
}
