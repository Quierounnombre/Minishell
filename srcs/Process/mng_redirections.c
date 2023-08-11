/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:40:33 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	mng_input(t_cmd *cmd, t_shell *shell)
{
	if (cmd->redir_in->tipe != FT_RED_STD)
	{
		if (cmd->redir_in->tipe == FT_RED_IN)
			input_redirect(cmd, shell);
		if (cmd->redir_in->tipe == FT_RED_HEREDOC)
			input_redirect(cmd, shell);
	}
}

static void	mng_output(t_cmd *cmd, t_shell *shell)
{
	if (cmd->redir_out->tipe != FT_RED_STD)
	{
		if (cmd->redir_out->tipe == FT_RED_OUT)
			output_redirection(cmd, shell);
		if (cmd->redir_out->tipe == FT_RED_APPEND)
			output_append(cmd, shell);
	}
}

void	mng_redirections(t_cmd *cmd, t_shell *shell)
{
	if (cmd->redir_out)
		mng_output(cmd, shell);
	if (cmd->redir_in)
		mng_input(cmd, shell);
}
