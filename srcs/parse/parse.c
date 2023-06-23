/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:51:33 by lyandriy          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/19 15:57:59 by lyandriy         ###   ########.fr       */
=======
/*   Updated: 2023/05/25 10:48:10 by vicgarci         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function parse revisa la entrada y si esta bien devuelve true
*/
int	parse(t_shell *shell, char *input, char **env)
{
	if (!check_pipes(shell, input))
		return (0);
	shell->env = env;
	separation(shell, input);
	return (1);
}
/*
static void	check_input(t_shell *shell, char *my_input, char **env)
{
	check_pipes(shell, my_input);
	shell->env = env;
	separation(shell, my_input);
}

void	parse(t_shell *shell, char *input, char **env)
{
<<<<<<< HEAD
	check_input(shell, input, env);
=======
	if (check_input(shell, input, env))
		return (1);
	return (0);
>>>>>>> master
}
*/