/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:01:51 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/15 12:19:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	free_clone_env(char **env);

void	make_new_env(t_shell *shell, char *s, int size)
{
	char	**local_env;
	int		i;

	i = 0;
	local_env = NULL;
	local_env = (char **)ft_calloc(sizeof(char *), (size + 2));
	if (!local_env)
		ft_error(shell, errno);
	while (shell->env[i])
	{
		local_env[i] = NULL;
		local_env[i] = ft_strdup(shell->env[i]);
		if (!local_env[i])
			ft_error(shell, errno);
		i++;
	}
	local_env[i] = NULL;
	local_env[i] = ft_strdup(s);
	if (!local_env[i])
		ft_error(shell, errno);
	i++;
	local_env[i] = NULL;
	if (!free_clone_env(shell->env))
		shell->env = local_env;
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
