/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/14 16:09:29 by vicgarci         ###   ########.fr       */
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
	while (s[i] != '\0' && s[i] != '=')
	{
		if (!ft_isalnum(s[i]) || ft_isdigit(s[i]))
		{
			ft_printf("%s: %s: '%s': %s\n",
				"Minishell",
				"export",
				s,
				"not a valid identifier");
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

	if (!check_name(s))
		return (NULL);
	i = 0;
	while (s[i] != '=' && s[i])
		i++;
	target = NULL;
	target = (char *)malloc(sizeof(char) * (i + 2));
	if (!target)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '=')
	{
		target[i] = s[i];
		i++;
	}
	target[i] = '\0';
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
