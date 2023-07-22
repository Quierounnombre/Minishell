/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:28:33 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 11:49:23 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Gestiona los errores y en caso de ser necesario libera la memoria
@param shell la estructura general en caso de ser necesario liberarla
@param error_code el codigo de error
*/
void	ft_error(t_shell *shell, errno_t error_code)
{
	char	*s;

	if (error_code && shell)
	{
		s = strerror(error_code);
		perror(s);
	}
	exit(error_code);
}
