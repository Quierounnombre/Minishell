/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:09:07 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/23 16:14:17 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Borra el archivo con el nombre/ruta del file
@param shell estructura general en caso de error
@param file archivo a ser eliminado
*/
void	ft_delete_file(t_shell *shell, char *file)
{
	if (unlink(file))
		ft_error(shell, errno);
}
