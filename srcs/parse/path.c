/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:00:52 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/15 17:16:06 by lyandriy         ###   ########.fr       */
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