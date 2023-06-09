/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:51:33 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/12 18:52:04 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function parse revisa la entrada y si esta bien devuelve true
*/
int	parse(t_shell *shell, char *input, char **env)
{
	shell->env = env;
	if (!check_pipes(shell, input))
		return (0);
	separation(shell, input);
	return (1);
}
