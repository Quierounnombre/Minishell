/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:43:02 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/31 17:38:21 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Imprime el texto que se le indica por consola.
En el caso de tener la flag -n no imprime el salto de linea
*/
static void	print_echo(t_cmd *cmd, int i)
{
	while (cmd->argv[i])
	{
		printf("%s", cmd->argv[i]);
		i++;
		if (cmd->argv[i])
			printf(" ");
	}
}

void	echo(t_cmd *cmd)
{
	if (cmd->argv && cmd->argv[1] && ft_strcmp("-n", cmd->argv[1]))
		print_echo(cmd, 2);
	else
	{
		print_echo(cmd, 1);
		printf("\n");
	}
}
