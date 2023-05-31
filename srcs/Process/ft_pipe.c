/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:09:30 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/31 16:00:47 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Comproeba si se puede ejecutar un pipe
static t_bool	can_be_pipe(t_shell *shell)
{
	t_cmd	*cmd;
	t_cmd	*cmd_next;

	cmd = shell->cmds->current->content;
	if (shell->cmds->current->next)
	{
		cmd_next = shell->cmds->current->next->content;
		if (cmd->redir_out->tipe != FT_RED_STD)
			return (false);
		if (cmd_next->redir_in->tipe != FT_RED_STD)
			return (false);
		return (true);
	}
	return (false);
}

//Expulsa el output del archivo dentro del arrchivo pipe
static void	dump_into_file(t_shell *shell)
{
	int		fd;

	fd = open(shell->tube_file, O_WRONLY, O_TRUNC, O_CREAT);
	if (fd < 0)
		ft_error(shell, errno);
	dup2(fd, STDOUT_FILENO);
	cmd_executer(shell);
	close(fd);
}

//Lee de la nada, aka en el caso de que la pipe tenga una redicción
static void	read_from_trash(t_shell *shell)
{
	int		fd;
	t_cmd	*cmd_next;

	cmd_next = shell->cmds->current->next->content;
	fd = open(shell->tube_file, O_WRONLY, O_TRUNC, O_CREAT);
	if (fd < 0)
		ft_error(shell, errno);
	close(fd);
	cmd_next->redir_in->tipe = FT_RED_IN;
	cmd_next->redir_in->file = shell->tube_file;
}

/*
Ejecuta el siguiente comando de la lista y si procede vuelca su contenido en
el pipe_file, luego si corresponde modifica el input del siguiente comando
@param shell Estructura de uso general, en este caso para acceso a cmds y error
*/
void	ft_pipe(t_shell *shell)
{
	t_cmd	*cmd;
	t_cmd	*cmd_next;

	if (can_be_pipe(shell))
	{
		cmd = shell->cmds->current->content;
		dump_into_file(shell);
		cmd_next = shell->cmds->current->next->content;
		cmd_next->redir_in->tipe = FT_RED_IN;
		cmd_next->redir_in->file = shell->tube_file;
	}
	else
	{
		if (cmd_next->redir_in->tipe == FT_RED_STD)
			dump_into_file(shell);
		else if (cmd->redir_out->tipe == FT_RED_STD)
			read_from_trash(shell);
		cmd_executer(shell);
	}
}
