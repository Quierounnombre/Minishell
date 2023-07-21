/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:35:20 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/21 18:35:14 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_path(char **separate_path)
{
	int	i;

	i = 0;
	while (separate_path[i])
	{
		free(separate_path[i]);
		i++;
	}
}

void	fill_argv(t_cmd *new_cmd, char *path_with_command)
{
	free(new_cmd->argv[0]);
	new_cmd->argv[0] = ft_strdup(path_with_command);
	//new_cmd->filepath = ft_strdup(path_with_command);
	new_cmd->filepath = path_with_command;
}
//67
void	ft_path(t_shell *shell, t_cmd *new_cmd)
{
	int		count;
	char	*ptr;
	char	**separate_path;
	char	*path_with_command;
	char	*path_with_slash;

	count = 0;
	ptr = get_ptr(shell, "PATH");
	if (ptr)
	{
		separate_path = ft_split(ptr, ':');
		path_with_command = ft_strdup(new_cmd->argv[0]);
		while (access(path_with_command, F_OK) == -1 && separate_path[count])
		{
			free(path_with_command);
			path_with_slash = ft_strjoin(separate_path[count], "/");
			path_with_command = ft_strjoin(path_with_slash, new_cmd->argv[0]);
			free(path_with_slash);
			count++;
		}
		if (access(path_with_command, F_OK) == 0)
			fill_argv(new_cmd, path_with_command);
		//free(path_with_command);
		free_path(separate_path);
	}
}
