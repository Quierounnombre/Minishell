/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleancmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:35:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:42:09 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	clean_the_redirs(t_cmd *cmd);

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
		if (should_be_close(cmd->redir_in->fd))
			close(cmd->redir_in->fd);
		if (cmd->redir_in->tipe == FT_RED_HEREDOC)
			unlink(cmd->redir_in->file);
		free(cmd->redir_in->file);
		free(cmd->redir_in);
	}
	if (cmd->redir_out)
	{
		if (should_be_close(cmd->redir_out->fd))
			close(cmd->redir_out->fd);
		free(cmd->redir_out->file);
		free(cmd->redir_out);
	}
}
