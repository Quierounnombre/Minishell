/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:44:09 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/14 18:11:14 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Inicia un hijo y lo ejecuta
@param estructura con información de uso general
*/
void	fork_child(t_shell *shell)
{
	t_child	*child;
	pid_t	pid;

	child = shell->childs->current->content;
	pid = fork();
	if (!pid)
		ft_child(shell, child);
}
