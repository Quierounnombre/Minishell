/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:02:32 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/02 15:40:25 by vicgarci         ###   ########.fr       */
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

static char	*should_get_path(t_cmd *new_cmd, t_shell *shell, int *count,
	char ***separate)
{
	char	*ptr;
	char	**separate_path;

	ptr = NULL;
	if (!is_built_in(new_cmd))
	{
		ptr = get_ptr(shell, "PATH");
		if (ptr)
		{
			find_start_of_str(ptr, count);
			separate_path = ft_split(&ptr[*count], ':');
			if (!separate_path)
				ptr = NULL;
			else
				*separate = separate_path;
			*count = 0;
		}
	}
	return (ptr);
}

static void	fill_argv(t_cmd *new_cmd, char *path_with_command)
{
	free(new_cmd->argv[0]);
	new_cmd->argv[0] = ft_strdup(path_with_command);
	new_cmd->filepath = path_with_command;
}

void	ft_path(t_shell *shell, t_cmd *new_cmd)
{
	int		count;
	char	*ptr;
	char	**separate_path;
	char	*path_with_command;
	char	*path_with_slash;

	count = 0;
	ptr = should_get_path(new_cmd, shell, &count, &separate_path);
	if (ptr)
	{
		path_with_command = ft_strdup(new_cmd->argv[0]);
		while (access(path_with_command, F_OK) == -1
			&& separate_path[count])
		{
			free(path_with_command);
			path_with_slash = ft_strjoin(separate_path[count], "/");
			path_with_command = ft_strjoin(path_with_slash,
					new_cmd->argv[0]);
			free(path_with_slash);
			count++;
		}
		if (access(path_with_command, F_OK) == 0)
			fill_argv(new_cmd, path_with_command);
		free_path(separate_path);
	}
}
