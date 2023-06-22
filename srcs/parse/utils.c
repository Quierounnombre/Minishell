/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:55:04 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/22 20:33:42 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function recorre espacios y tabulaciones
@function start_new_nodo crea nuevo t_lstmng y reinicializa los contadores
@function start_nodo inicializa el nuevo nodo t_lstmng
@function lstadd_back_nodo crea la lista de redirecciones
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

void	lstadd_back_nodo(t_red **lst, t_red *new)
{
	t_red	*tmp;

	if (!lst)
		return ;
	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

void	ft_path(t_shell *shell, t_cmd *new_cmd)
{
	int		count;
	char	*ptr;
	char	**separate_path;
	char	*path_with_command;

	count = 0;
	new_cmd->filepath = NULL;
	ptr = get_ptr(shell, "PATH");
	separate_path = ft_split(ptr, ':');
	path_with_command = ft_strdup(new_cmd->argv[0]);
	while (access(path_with_command, F_OK) == -1 && separate_path[count])
	{
		path_with_command = ft_strjoin(separate_path[count], "/");
		path_with_command = ft_strjoin(path_with_command, new_cmd->argv[0]);
		count++;
	}
	if (access(path_with_command, F_OK) == 0)
	{
		free(new_cmd->argv[0]);
		new_cmd->argv[0] = ft_strdup(path_with_command);
		new_cmd->filepath = ft_strdup(path_with_command);
	}
	free(path_with_command);
}
