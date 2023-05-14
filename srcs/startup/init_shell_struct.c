/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:01:43 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/14 13:53:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	init_lstmng(t_shell *local_shell)
{
	t_list	*lst;

	lst = NULL;
	if (store_child(local_shell->self_pid, &lst))
	{
		if (ft_lstmngnew(lst))
			return (true);
		free(lst);
	}
	return (false);
}

/*
Almacena el struct de la shell
@param shell la dirección de memoria del struct
@return devuelve true, si almacena el struct, false si no
*/
t_bool	init_shell_struct(t_shell **shell)
{
	t_shell	*local_shell;

	local_shell = (t_shell *)malloc(sizeof(t_shell));
	if (local_shell)
	{
		local_shell->self_pid = getpid();
		if (init_lstmng(local_shell))
		{
			*shell = local_shell;
			return (true);
		}
		free(local_shell);
	}
	return (false);
}
