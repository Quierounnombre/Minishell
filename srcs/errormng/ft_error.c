/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:28:33 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/01 15:07:05 by vicgarci         ###   ########.fr       */
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
	t_child		*child;

	if (error_code && shell)
	{
		child = shell->childs->current->content;
		perror(child->cmd->argv[0]);
	}
	exit(error_code);
}
