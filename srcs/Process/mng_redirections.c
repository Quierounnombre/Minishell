/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/05 12:50:55 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Gestiona las redirecciones de input
static void	mng_input(t_cmd *cmd)
{
	if (cmd->redir_in->tipe != FT_RED_STD)
	{
		if (cmd->redir_in->tipe == FT_RED_IN)
			input_redirect(cmd);
		if (cmd->redir_in->tipe == FT_RED_HEREDOC)
			input_redirect(cmd);
	}
}

//Gestiona las redirecciones de output
static void	mng_output(t_cmd *cmd)
{
	if (cmd->redir_out->tipe != FT_RED_STD)
	{
		if (cmd->redir_out->tipe == FT_RED_OUT)
			output_redirection(cmd);
		if (cmd->redir_out->tipe == FT_RED_APPEND)
			output_append(cmd);
	}
}

/*
Gestiona las redirecciones dentro de un comando, tanto las de input
como las de output
@param t_cmd Estructura general con la información
*/
void	mng_redirections(t_cmd *cmd)
{
	mng_input(cmd);
	mng_output(cmd);
}
