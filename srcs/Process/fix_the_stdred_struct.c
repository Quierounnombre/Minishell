/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_the_stdred_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:01:49 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 19:02:14 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fix_the_stdred_struct(t_child	*child, t_red *red)
{
	red = child->cmd->redir_in;
	while (red && red->next && red->tipe != FT_RED_STD)
	{
		child->cmd->redir_in->fd = open(child->cmd->redir_in->file,
				O_CREAT | O_TRUNC, 0644);
		close(child->cmd->redir_in->fd);
		child->cmd->redir_in = child->cmd->redir_in->next;
		free(red);
		red = child->cmd->redir_in;
	}
	red = child->cmd->redir_out;
	while (red && red->next && red->tipe != FT_RED_STD)
	{
		child->cmd->redir_out->fd = open(child->cmd->redir_out->file,
				O_CREAT | O_TRUNC, 0644);
		close(child->cmd->redir_out->fd);
		child->cmd->redir_out = child->cmd->redir_out->next;
		free(red);
		red = child->cmd->redir_out;
	}
}