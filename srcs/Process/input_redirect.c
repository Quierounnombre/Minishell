/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:44:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/16 16:54:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Gestiona la apertura de la redirección del tipo '<' y en el caso de tener una
pipe cierra la entrada de este
@param shell la estructura general con toda la información relacionada
*/
void	input_redirect(t_shell *shell)
{
	int		fd_input;
	int		error_code;
	t_cmd	*cmd;

	cmd = shell->cmds->current->content;
	error_code = 0;
	fd_input = 0;
	fd_input = open(cmd->redir_in->file, O_RDONLY);
	if (fd_input > 0)
	{
		error_code = dup2(fd_input, STDIN_FILENO);
		if (error_code)
			ft_error(shell, error_code);
		cmd->redir_in->fd = fd_input;
	}
	else
		ft_error(shell, fd_input);
}
