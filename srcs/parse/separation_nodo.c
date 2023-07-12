/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation_nodo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:39:31 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/12 16:53:50 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function check_size_redir revisa si hay alguna redireccion
@function create_node creara el nodo lo llenara de informacion y lo añade a la
lista
*/
void	create_node(t_shell *shell, t_cmd *new_cmd, char *my_input)
{
	t_list	*tmp;

	shell->s_i.size_out = 0;
	shell->s_i.size_in = 0;
	new_cmd->argv = malloc(sizeof(char *) * (shell->s_i.size_token + 1));
	if (!new_cmd->argv)
		exit (1);
	new_cmd->argv[shell->s_i.size_token] = NULL;
	copy_cmd_token(shell, new_cmd, my_input);
	tmp = ft_lstnew(new_cmd);
	ft_lstadd_back(&shell->cmds->current, tmp);
}
