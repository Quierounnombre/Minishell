/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:23:56 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/23 18:19:53 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Libera el env en caso de error
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

static void	local_copy_env(t_shell *shell, int target, char **local_env)
{
	int		i;
	int		correction;

	i = 0;
	correction = 0;
	while (shell->env[i])
	{
		if (i == target)
			correction = 1;
		else
		{
			local_env[i - correction] = NULL;
			local_env[i - correction] = ft_strdup(shell->env[i]);
			if (!local_env[i - correction])
				ft_error(shell, errno);
		}
		i++;
	}
	local_env[i - correction] = NULL;
}

//En caso de ser necesario genera un nuevo env
static void	make_new_env(t_shell *shell, int target, int size)
{
	char	**local_env;

	local_env = NULL;
	local_env = (char **)ft_calloc(sizeof(char *), (size));
	if (!local_env)
		ft_error(shell, errno);
	local_copy_env(shell, target, local_env);
	if (!free_clone_env(shell->env))
		shell->env = local_env;
}

static char	*load_target(char *s)
{
	char	*target;
	int		i;

	i = 0;
	while (s[i])
		i++;
	target = NULL;
	target = (char *)ft_calloc(sizeof(char), (i + 1));
	if (target)
		ft_strlcpy(target, s, i);
	return (target);
}

/*
Elimina una variable dada del env
@param shell porta el env actual y en caso de error para eliminar la shell
@param s la variable a eliminar
*/
void	ft_unset(t_shell *shell, char *s)
{
	int		i;
	int		size_env;
	char	*target;

	target = NULL;
	size_env = 0;
	target = load_target(s);
	if (!target)
		ft_error(shell, errno);
	i = 0;
	while (shell->env[size_env])
		size_env++;
	i = find_string(shell->env, target);
	if (shell->env[i] != NULL)
		make_new_env(shell, i, size_env);
	free(target);
}


