/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation_nodo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:39:31 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/29 18:28:57 by lyandriy         ###   ########.fr       */
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

	shell->size_input.size_out = 0;
	shell->size_input.size_in = 0;
	new_cmd->argv = malloc(sizeof(char *) * (shell->size_input.size_token + 1));
	if (!new_cmd->argv)
		exit (1);
	new_cmd->argv[shell->size_input.size_token] = NULL;
	copy_cmd_token(shell, new_cmd, my_input);
	tmp = ft_lstnew(new_cmd);
	ft_lstadd_back(&shell->cmds->current, tmp);
	int i = 0;
	while (((t_cmd *)(shell->cmds->current->content))->argv[i] != NULL)
	{
		printf("filepath: %s\n", ((t_cmd *)(shell->cmds->current->content))->filepath);
		printf("%s\n", ((t_cmd *)(shell->cmds->current->content))->argv[i]);
		if (((t_cmd *)(shell->cmds->current->content))->redir_in)
			printf("%s\n", ((t_cmd *)(shell->cmds->current->content))->redir_in->file);
		i++;
	}
}
