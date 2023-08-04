/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:49:35 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/04 15:35:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function argv_with_qm si el argv tiene comillas contara todos los caracteres
que tienen dentro
@function copy_argv copia el comando o el argumento
@function this_is_cmd_argv cuenta el tamaño del comando o del argumento
y los copia
@function copy_cmd_token copia los comandos argumentos redirecciones
*/
char	*find_env(t_shell *shell, char *input, int *count)
{
	char	*ptr;
	int		ptr_count;
	char	*environment_variabl;

	ptr = NULL;
	ptr_count = 0;
	*count += 1;
	environment_variabl = NULL;
	*count += copy_env(shell, &input[*count], &environment_variabl);
	if (environment_variabl)
	{
		ptr = get_ptr(shell, environment_variabl);
		if (ptr)
			find_start_of_str(ptr, &ptr_count);
		if (ptr)
		{
			free(environment_variabl);
			return (&ptr[ptr_count]);
		}
		free(environment_variabl);
	}
	return (NULL);
}
