/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:44:36 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/04 11:46:27 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

//WHY count_env, is its gonna be alwaays 0

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
	argv_env = ft_split(ptr, ' ');
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
	*copy = ft_strlen(new_cmd->argv[*i]);
}

	//No usas copy?? osea para que += si luego lo reasignas y en el proceso
	//no se hace nada