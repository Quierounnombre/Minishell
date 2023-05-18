/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/18 16:26:04 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Gestiona las redirecciones de input
static void	mng_input(t_shell *shell)
{
	t_cmd	*cmd;

	cmd = shell->cmds->current->content;
	if (cmd->redir_in->tipe != FT_RED_STD)
	{
		if (cmd->redir_in->tipe == FT_RED_IN)
			input_redirect(shell);
	}
}

//Gestiona las redirecciones de output
static void	mng_output(t_shell *shell)
{
	t_cmd	*cmd;

	cmd = shell->cmds->current->content;
	if (cmd->redir_out->tipe != FT_RED_STD)
	{
		if (cmd->redir_out->tipe == FT_RED_OUT)
			output_redirection(shell);
	}
}

/*
Gestiona las redirecciones dentro de un comando, tanto las de input
como las de output
@param t_shell Estructura general con la información
*/
void	mng_redirections(t_shell *shell)
{
	mng_input(shell);
	mng_output(shell);
}
