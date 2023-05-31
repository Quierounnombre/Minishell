/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:43:02 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/31 15:02:46 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Imprime el texto que se le indica por consola.
En el caso de tener la flag -n no imprime el salto de linea
*/
void	echo(t_shell *shell)
{
	t_cmd	*cmd;

	cmd = shell->cmds->current->content;
	if (ft_strcmp("-n", cmd->argv[1]))
		ft_printf("%s", cmd->argv[2]);
	else
		ft_printf("%s\n", cmd->argv[1]);
}
