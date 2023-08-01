/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:52:01 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/01 15:21:27 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Detiene la ejecución y sale de la shell, aparte imprime un exit al salir
@param shell, la estructura general a liberar
*/
void	ft_exit(t_shell *shell)
{
	ft_error(shell, 0);
}
