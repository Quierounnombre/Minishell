/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_variabl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:37:51 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/18 19:06:12 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	Expand_Environment_Strings(t_shell *shell, char *environment_variabl);

void	this_is_environment_variabl(t_shell *shell, char *my_input, int *count)
{
	int		env_tam;
	char	*environment_variabl;

	env_tam = 0;
	while (my_input[*count] != ' ' && my_input[*count] != '\t' && my_input[*count] != '\0')
	{
		env_tam++;
		*count += 1;
	}
	environment_variabl = malloc(sizeof(char) * (env_tam + 1));
	if (!environment_variabl)
	{
		write (1, "hola\n", 5);
		//ft_error();
	}
	*count -= env_tam;
	env_tam = 0;
	while (my_input[*count] != ' ' && my_input[*count] != '\t' && my_input[*count] != '\0')
	{
		environment_variabl[env_tam] = my_input[*count];
		env_tam++;
		*count += 1;
	}
	environment_variabl[env_tam] = '\0';
	Expand_Environment_Strings(shell, environment_variabl);
}

static void	Expand_Environment_Strings(t_shell *shell, char *environment_variabl)
{
	int	count;
	t_cmd *cmd;

	cmd = shell->cmds->current->content;
	count = 0;
	environment_variabl++;
	/*cmd->
	while ()*/
}