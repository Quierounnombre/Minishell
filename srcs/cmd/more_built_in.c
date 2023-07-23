/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:16:01 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/23 18:06:23 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_unset(t_cmd *cmd, t_shell *shell)
{
	int	i;

	i = 1;
	while (cmd->argv[i])//pueden haber varios variables con un unset
	{
		ft_unset(shell, cmd->argv[i]);//puede ser que no existe cmd->argv[1]
		i++;
	}
}

void	do_export(t_cmd *cmd, t_shell *shell)
{
	int	i;

	i = 1;
	while (cmd->argv[i])//pueden haber varios variables con un export
	{
		ft_export(shell, cmd->argv[i]);
		i++;
	}
	/*if (!cmd->argv[1])//si no existe cmd->argv[1], export saca la lista de env ordenada por orden alfabetico y mayusculas y minusculas
		export_sort_env(shell);*/
}