/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:49:40 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/29 12:50:26 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
This method do a fork process, and store its pid in the lst, can return false
in the case that the lst cant be allocated or the fork fail.
@param shell is the global struct
@return devuelve true si ha salido exitosamente, y false si da error
*/
t_bool	do_fork(t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
		return (true);
	if (pid == 0)
	{
		shell->self_pid = 0;
		return (true);
	}
	return (false);
}
