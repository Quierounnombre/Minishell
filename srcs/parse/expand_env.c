/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:44:36 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/16 18:00:44 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**protected_ft_split(char *ptr, char c)
{
	char	**argv_env;

	argv_env = NULL;
	argv_env = ft_split(ptr, c);
	if (!argv_env)
		exit(1);
	return (argv_env);
}

static int	check_spaces(t_cmd *new_cmd, char **argv_env, int *count_env,
	int *i)
{
	int	copy;

	copy = 0;
	if (argv_env[*count_env])
		*i += 1;
	while (argv_env[*count_env])
	{
		new_cmd->argv[*i] = argv_env[*count_env];
		*count_env += 1;
		if (argv_env[*count_env])
		{
			copy = ft_strlen(new_cmd->argv[*i]);
			*i += 1;
		}
	}
	return (copy);
}

static void	else_case(t_cmd *new_cmd, int *i, char **argv_env, int *copy)
{
	int	count_env;

	count_env = 0;
	if (argv_env)
	{
		new_cmd->argv[*i] = argv_env[count_env];
		*copy += ft_strlen(argv_env[count_env]);
	}
	else
		exit(1);
}

void	expand_env(char *ptr, t_cmd *new_cmd, int *i, int *copy)
{
	char	**argv_env;
	int		count_env;

	count_env = 0;
	argv_env = protected_ft_split(ptr, ' ');
	if (new_cmd && new_cmd->argv && new_cmd->argv[*i] && argv_env)
	{
		new_cmd->argv[*i][*copy] = '\0';
		ptr = new_cmd->argv[*i];
		if (ptr)
		{
			new_cmd->argv[*i] = ft_strjoin(ptr, argv_env[count_env]);
			if (!new_cmd->argv[*i])
				exit(1);
			*copy += ft_strlen(argv_env[count_env]);
			free(ptr);
			free(argv_env[count_env]);
		}
	}
	else
		else_case(new_cmd, i, argv_env, copy);
	count_env++;
	*copy += check_spaces(new_cmd, argv_env, &count_env, i);
	free(argv_env);
	*copy = ft_strlen(new_cmd->argv[*i]);
}
