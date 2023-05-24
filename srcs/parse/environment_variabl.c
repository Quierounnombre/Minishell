/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_variabl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:37:51 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/24 20:31:59 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
this_is_dollar gestiona $
*/

void	this_is_environment_variabl(t_cmd *new_cmd, char *my_input, int *count, int *count_token)
{
	int		env_tam;
	char	*environment_variabl;

	env_tam = 0;
	while (my_input[*count] != ' ' && my_input[*count] != '\t' &&
		my_input[*count] != '$' && my_input[*count] != '\0')
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
	while (my_input[*count] != ' ' && my_input[*count] != '\t' &&
		my_input[*count] != '\0' && my_input[*count] != '$')
	{
		environment_variabl[env_tam] = my_input[*count];
		env_tam++;
		*count += 1;
	}
	environment_variabl[env_tam] = '\0';
	Expand_Environment_Strings(new_cmd, my_input[*count], environment_variabl, &count_token);
}

static void	Expand_Environment_Strings(t_cmd *new_cmd, char *my_input, char *environment_variabl, int *count_token)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = NULL;
	while (new_cmd->argv[*count_token] == NULL && new_cmd->env[count])
	{
		ptr = ft_strnstr(env[count], environment_variabl, ft_strlen(env[count]));
		if (ptr)
			new_cmd->argv[*count_token] = ft_strdup(ptr);
		count++;
	}

}

int	this_is_dollar(char *my_input, int *count, t_cmd *new_cmd, int *count_token)
{
	(void)new_cmd, (void)count_token;
	if (my_input[*count + 1] == '?')
	{
		write (1, "hola\n", 5);
		//pipe_exit_code();
	}
	if (my_input[*count + 1] != '\0' && my_input[*count + 1] != ' ' &&
		my_input[*count + 1] != '\t' && (my_input[*count - 1] == '\t' ||
		my_input[*count - 1] == '\0') && *count - 1 == -1)
	{
		write (1, "hola\n", 5);
		count[*count + 1];
		//variabl_function(my_input, count, new_cmd, count_token);
		//this_is_environment_variabl(new_cmd, my_input, &count, &count_token);
		//*count_token += 1;
	}
	space_tab(my_input, count);
	return (1);
}
