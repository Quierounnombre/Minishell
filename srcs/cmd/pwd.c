/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:44:42 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/01 14:32:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Muestra por consola la variable de entorno PWD
@param env el enviroment donde buscar
*/
void	ft_pwd(char **env)
{
	char	*pwd;

	(void) env;
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
}
