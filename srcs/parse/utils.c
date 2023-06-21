/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:55:04 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/19 17:24:54 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function recorre espacios y tabulaciones
@function start_new_nodo crea nuevo t_lstmng y reinicializa los contadores
@function start_nodo inicializa el nuevo nodo t_lstmng
*/
void	space_tab(char *my_input, int *count)
{
	while (my_input[*count] == ' ' || my_input[*count] == '\t')
		*count += 1;
}

void	start_new_nodo(t_shell *shell)
{
	shell->size_input.size_in = 0;
	shell->size_input.size_out = 0;
	shell->cmds = malloc(sizeof(t_lstmng));
	if (!shell->cmds)
		exit (1);
	shell->cmds->current = NULL;
	shell->size_input.size_token = 0;
}

void	start_nodo(t_cmd *new_cmd)
{
	new_cmd->filepath = NULL;
	new_cmd->argv = NULL;
	new_cmd->redir_in = NULL;
	new_cmd->redir_out = NULL;
}