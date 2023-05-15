/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:56:24 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/15 16:04:09 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Inicializa todas las estructuras y elementos necesarios para el programa
@param shell recibe la dirección de memoria para cargar el puntero
@param env el enviroment que se le pasa a la shell
@return false en caso de error, true si todo esta bien
*/
t_bool	start(t_shell **shell, char **env)
{
	if (init_shell_struct(shell, env))
		return (true);
	return (false);
}
