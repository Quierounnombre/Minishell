/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleancmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:35:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/10 19:41:34 by vicgarci         ###   ########.fr       */
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
	char	**init_argv;
	
	lst = node;
	cmd = lst->content;
	init_argv = cmd->argv;
	if (cmd->argv)
	{
		while (*(cmd->argv))
		{
			tmp_argv = *cmd->argv;
			cmd->argv++;
			if (*tmp_argv)
				free(tmp_argv);
		}
		free(init_argv);
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
		if (cmd->redir_in->tipe == FT_RED_HEREDOC)
			unlink(cmd->redir_in->file);
		free(cmd->redir_in->file);
		free(cmd->redir_in);
	}
	if (cmd->redir_out)
	{
		free(cmd->redir_out->file);
		free(cmd->redir_out);
	}
}