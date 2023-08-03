/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_nodo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:30:06 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/03 14:54:14 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	start_nodo(t_cmd *new_cmd)
{
	new_cmd->filepath = NULL;
	new_cmd->argv = NULL;
	new_cmd->redir_in = NULL;
	new_cmd->redir_out = NULL;
}
