/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleancmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:35:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/13 19:39:28 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Libera la memoria reservada para un nodo comando
@param node el puntero del nodo de cmd a borrar
*/
void	ft_cleancmd(void *node)
{
	t_list	*lst;
	t_cmd	*cmd;
	char	**tmp_argv;

	lst = node;
	cmd = lst->content;
	while (cmd->argv)
	{
		tmp_argv = cmd->argv;
		cmd->argv++;
			write (2, "hla\n", 4);
		if (tmp_argv)
			free(tmp_argv);
	}
	free(cmd);
				write (2, "hooooooooola\n", 4);
	free(lst);
}
