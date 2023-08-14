/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:03:55 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/14 16:06:05 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	free_clone_env(char **env);

t_bool	clone_env(char **env, t_shell *shell)
{
	char	**local_env;
	int		i;

	local_env = NULL;
	i = 0;
	while (env[i])
		i++;
	local_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	if (!local_env)
		return (false);
	while (env[i])
	{
		local_env[i] = NULL;
		local_env[i] = ft_strdup(env[i]);
		if (!local_env[i])
			return (free_clone_env(local_env));
		i++;
	}
	local_env[i] = NULL;
	shell->env = local_env;
	return (true);
}

static t_bool	free_clone_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
	return (false);
}
