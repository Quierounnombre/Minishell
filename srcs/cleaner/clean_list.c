/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:28:35 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/23 20:36:07 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_list_redirection(t_red *redir)
{
	t_red	*temp;

	while (redir->next)
	{
		temp = redir;
		free(temp->file);
		free(temp->tipe);
		//free(redir->fd);
		redir->next = redir;
		free(temp);
	}
}

static void	free_commands(t_list *temp)
{
	int	count;

	count = 0;
	if ((t_cmd *)(temp->content)->filepath)
		free((t_cmd *)(temp->content)->filepath);
	while ((t_cmd *)(temp->content)->argv[count])
	{
		free((t_cmd *)(temp->content)->argv[count]);
		count++;
	}
	if ((t_cmd *)(temp->content)->redir_in)
		free_list_redirection((t_cmd *)(temp->content)->redir_in);
	if ((t_cmd *)(temp->content)->redir_out)
		free_list_redirection((t_cmd *)(temp->content)->redir_out);
	free(temp);
}

/*
@brief Limpia/libera los datos alocados del parseo
@param shell estructura de uso general
*/
void	clean_list(t_shell *shell)
{
	t_list	*temp;

	temp = NULL;
	while (shell->cmds->current->next != NULL)
	{
		temp = shell->cmds->current;
		shell->cmds->current->next = shell->cmds->current;
		free_commands(temp);
	}
}
