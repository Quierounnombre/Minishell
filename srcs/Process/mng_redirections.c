/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/13 15:57:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Gestiona las redirecciones de input
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

//Gestiona las redirecciones de output
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

/*
Gestiona las redirecciones dentro de un comando, tanto las de input
como las de output
@param cmd Comando a ejecutar
@param shell gestionar las redirecciones
*/
void	mng_redirections(t_cmd *cmd, t_shell *shell)
{
	mng_input(cmd, shell);
	mng_output(cmd, shell);
}
