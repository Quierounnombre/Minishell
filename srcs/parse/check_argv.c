/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:33:32 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/04 16:14:23 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_argv(t_shell *shell, t_cmd *new_cmd)
{
	if (shell->s_i.copy == 0)
		new_cmd->argv[shell->s_i.ctoken] = NULL;
	else if (new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] != '\0')
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
}
