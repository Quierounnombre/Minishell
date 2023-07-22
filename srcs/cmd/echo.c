/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:43:02 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 18:35:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Imprime el texto que se le indica por consola.
En el caso de tener la flag -n no imprime el salto de linea
*/
void	echo(t_cmd *cmd)
{
	int	i;

	if (ft_strcmp("-n", cmd->argv[1]))
	{
		i = 2;
		while (cmd->argv[i])
		{
			printf("%s ", cmd->argv[i]);
			i++;
		}
	}
	else
	{
		i = 1;
		while (cmd->argv[i])
		{
			printf("%s ", cmd->argv[i]);
			i++;
		}
		printf("\n");
	}
}
