/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleancmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:35:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/02 14:40:03 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	clean_the_redirs(t_cmd *cmd);

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
	if (cmd->filepath)
		free(cmd->filepath);
	clean_the_redirs(cmd);
	free(cmd);
	free(lst);
}

static void	clean_the_redirs(t_cmd *cmd)
{
	if (cmd->redir_in)
	{
		close(cmd->redir_in->fd);
		if (cmd->redir_in->tipe == FT_RED_HEREDOC)
			unlink(cmd->redir_in->file);
		free(cmd->redir_in->file);
		free(cmd->redir_in);
	}
	if (cmd->redir_out)
	{
		close(cmd->redir_out->fd);
		free(cmd->redir_out->file);
		free(cmd->redir_out);
	}
}
