/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:44:42 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 17:26:56 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Muestra por consola la variable de entorno PWD
@param env el enviroment donde buscar
*/
void	ft_pwd(char **env)
{
	int	i;
	int	count;

	count = 0;
	i = find_string(env, "PWD=");
	find_start_of_str(env[i], &count);
	ft_printf("%s\n", &env[i][count]);
}
/*
- imprimias PWD=/Users/lyandriy/Desktop/Minishell en vez de /Users/lyandriy/Desktop/Minishell
- exit (0) tiene que hacerlo solo si esta ejecutandose en el hijo
*/