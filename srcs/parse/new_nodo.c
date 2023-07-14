/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_nodo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:30:06 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/13 19:30:18 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	start_new_nodo(t_shell *shell)
{
	shell->s_i.size_in = 0;
	shell->s_i.size_out = 0;
	shell->s_i.size_token = 0;
	shell->s_i.copy = 0;
	shell->s_i.ctoken = 0;
	shell->s_i.size_pipe = 0;
	shell->s_i.size_str = 0;
}

void	start_nodo(t_cmd *new_cmd)
{
	new_cmd->filepath = NULL;
	new_cmd->argv = NULL;
	new_cmd->redir_in = malloc(sizeof(t_red));
	if (!new_cmd->redir_in)
		exit (1);
	new_cmd->redir_in->tipe = FT_RED_STD;
	new_cmd->redir_out = malloc(sizeof(t_red));
	if (!new_cmd->redir_out)
		exit (1);
	new_cmd->redir_out->tipe = FT_RED_STD;
}
