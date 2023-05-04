/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:49:40 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/04 16:31:48 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*This method do a fork process, and store its pid in the lst, can return false
in the case that the lst cant be allocated @param shell is the global struct*/
t_bool	do_fork(t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (add_pid_to_lst(shell->childs, pid))
	{
		shell->self_pid = pid;
		return (true);
	}
	return (false);
}
