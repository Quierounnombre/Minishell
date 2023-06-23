/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:59:30 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/26 15:00:48 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Localiza un str en un env
@param env el enviroment donde buscar
@param target el string a encontrar
@return la posición del string
*/
int	find_string(char **env, char *target)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(target, env[i], ft_strlen(target)))
			return (i);
		i++;
	}
	return (i);
}
