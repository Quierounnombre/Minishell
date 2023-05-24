/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:00:52 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/21 20:22:12 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	path_function(char **env, t_shell *main_struct)
{
	int		count;
	char	*path;

	count = 0;
	path = NULL;
	while (path == NULL && env[count] != NULL)
	{
		path = ft_strnstr(env[count], "PATH=", ft_strlen(env[count]));
		count++;
	}
	if (env[count] == NULL)
	{}
	main_struct->separate_path = ft_split(&path[5], ':');
}

void	variabl_function(char *my_input, int *count, t_cmd *new_cmd, int count_token)//añadir la funcion
{
	int		count_env;
	char	*variabl;

	count_env = 0;
	new_cmd->argv[] = NULL;
	while ((my_input[*count] == ' ' || my_input[*count] == '\t' ||
			my_input[*count] == '|' || my_input[*count] == '\0'))
	{
		*count += 1;
		count_env++;
	}
	variabl = malloc (sizeof(char) * (count_env + 1 ));
	*count -= count_env;
	count_env = 0;
	while ((my_input[*count] == ' ' || my_input[*count] == '\t' ||
			my_input[*count] == '|' || my_input[*count] == '\0'))
	{
		variabl[count_env] = my_input[*count];
		*count += 1;
		count_env++;
	}
	variabl[count_env] = '\0';
	count_env = 0;
	while (new_cmd->argv[] == NULL && new_cmd->env[count_env] != NULL)
	{
		new_cmd->argv[] = t_strnstr(new_cmd->env[count_env], variabl, ft_strlen(new_cmd->env[count_env]));
		count_env++;
	}
	free(variabl);
}
