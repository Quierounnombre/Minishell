/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleancmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:35:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 11:57:04 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Libera la memoria reservada para un nodo comando
@param node el puntero del nodo de cmd a borrar
*/
void	ft_cleancmd(void *node)
{
	t_list	*lst;
	t_cmd	*cmd;
	char	*tmp_argv;

	lst = node;
	cmd = lst->content;
	while (*(cmd->argv))
	{
		tmp_argv = *cmd->argv;
		cmd->argv++;
		if (*tmp_argv)
			free(tmp_argv);
	}
	if (cmd->redir_in)
		free(cmd->redir_in);
	if (cmd->redir_out)
		free(cmd->redir_out);
	free(cmd);
	free(lst);
}
