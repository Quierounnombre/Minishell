/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:39:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

static void	make_new_env(t_shell *shell, char *s, int size)
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

static	int	check_name(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isalnum(s[i]))
		{
			perror(s);
			free(s);
			return (false);
		}
		i++;
	}
	return (true);
}

static char	*load_target(char *s)
{
	char	*target;
	int		i;

	i = 0;
	while (s[i] != '=' && s[i])
		i++;
	target = NULL;
	target = (char *)malloc(sizeof(char) * (i + 1));
	if (target)
		ft_strlcpy(target, s, (i + 1));
	if (!check_name(target))
		return (NULL);
	i = 0;
	while (s[i] != '=' && s[i])
	{
		i++;
		if (s[i] == '\0')
			return (NULL);
	}
	return (target);
}

void	ft_export(t_shell *shell, char	*s)
{
	int		i;
	int		size_env;
	char	*target;

	target = NULL;
	size_env = 0;
	target = load_target(s);
	if (!target)
		return ;
	i = 0;
	while (shell->env[size_env])
		size_env++;
	i = find_string(shell->env, target);
	if (shell->env[i] == NULL)
		make_new_env(shell, s, size_env);
	else
	{
		free(shell->env[i]);
		shell->env[i] = ft_strdup(s);
		if (!shell->env[i])
			ft_error(shell, errno);
	}
	free(target);
}
