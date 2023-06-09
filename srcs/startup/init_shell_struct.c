/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:01:43 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/13 19:17:04 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

//Inicializa los mngs
static t_bool	init_lstmng(t_shell *local_shell)
{
	if (ft_lstmngnew(NULL, &(local_shell->childs)))
	{
		if (ft_lstmngnew(NULL, &(local_shell->cmds)))
		{
			return (true);
		}
		free(local_shell->childs);
	}
	return (false);
}

/*
Almacena el struct de la shell
@param shell la dirección de memoria del struct
@param env el enviroment que se le asigna a la shell
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
