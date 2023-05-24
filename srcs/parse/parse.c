/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:51:33 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/24 18:44:29 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
parse revisa la entrada y si esta bien devuelve true
check_input revisa la string de entrada
*/
static int	check_input(t_shell *shell, char *my_input, char **env)
{
	if (check_pipes(shell, my_input))
		return (1);
	if (separation(shell, my_input, env))
		return (1);
	return (0);
}

int	parse(t_shell *shell, char *input, char **env)
{
	if (check_input(&shell, input, env))
		return (1);
	return (0);
}
