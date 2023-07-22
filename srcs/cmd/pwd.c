/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:44:42 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 18:48:10 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Muestra por consola la variable de entorno PWD
@param env el enviroment donde buscar
*/
void	ft_pwd(char **env)
{
	int		i;
	char	*s;

	i = find_string(env, "PWD=");
	s = env[i];
	s += 4;
	ft_printf("%s\n", s);
}
