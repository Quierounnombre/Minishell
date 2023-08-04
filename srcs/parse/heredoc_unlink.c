/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_unlink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:53:31 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 16:53:54 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc_unlink(t_shell *shell)
{
	t_cmd	*ptr_cmd;

	shell->cmds->current = shell->cmds->lst_head;
	while (shell->cmds->current)
	{
		ptr_cmd = shell->cmds->current->content;
		if (ptr_cmd->redir_in)
		{
			while (ptr_cmd->redir_in
				&& ptr_cmd->redir_in->tipe == FT_RED_HEREDOC)
			{
				unlink(ptr_cmd->redir_in->file);
				ptr_cmd->redir_in = ptr_cmd->redir_in->next;
			}
		}
		shell->cmds->current = shell->cmds->current->next;
	}
}
