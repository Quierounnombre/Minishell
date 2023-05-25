/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation_nodo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:55:43 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/25 10:46:28 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
start_nodo hace malloc para variables del nodo y env del nuevo nodo apunta a env
create_node crea nodos nuevos los llena de informacion y crea una lista
new_nodo crea nuevo nodo y convierte conetent en t_cmd
*/
int	start_nodo(t_cmd *new_cmd)
{
	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (0);
	new_cmd->redirections = malloc(sizeof(int) * shell->size_input.size_redir);
	if (!new_cmd->redirections)
		return (0);
	new_cmd->type = malloc(sizeof(char *) * (shell->size_input.size_redir + 1));
	if (!new_cmd->type)
		return (0);
	new_cmd->env = env;
	return (1);
}

static t_list	*new_nodo(void *ptr)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (0);
	lst->content = ptr;
	lst->next = 0;
	return (lst);
}

void	create_node(t_shell *shell, char *my_input, int *count, t_cmd *new_cmd)
{
	t_list	*tmp;

	if (shell->size_input.size_redir == 0)
		new_cmd->redirections[0] = NO_REDIRECT;
	new_cmd->argv = malloc(sizeof(char *) * (shell->size_input.size_token + 1));
	if (!new_cmd->argv)
	{
		write (1, "hola\n", 5);
		//ft_error();
	}
	new_cmd->argv[shell->size_input.size_token] = NULL;
	copy_cmd_token(my_input, *count, new_cmd);
	shell->size_input.size_token = 0;
	tmp = ft_lstnew(new_cmd);
	ft_lstadd_back(&shell->cmds->current, tmp);
}
