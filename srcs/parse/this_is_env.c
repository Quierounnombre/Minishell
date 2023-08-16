/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_is_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:29:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/16 12:38:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*protected_ft_strjoin(char *s1, char *s2)
{
	char	*r;

	r = NULL;
	r = ft_strjoin(s1, s2);
	if (!r)
		exit(1);
	return (r);
}

int	this_is_env(t_shell *shell, t_cmd *new_cmd, char *input, int *count_t)
{
	int		count;
	char	*ptr;
	char	*environment_variabl;

	count = 1;
	environment_variabl = NULL;
	if (input[count] == '?')
	{
		environment_variabl = ft_itoa(shell->child_status);
		if (environment_variabl)
		{
			if (new_cmd->argv[*count_t])
			{
				ptr = new_cmd->argv[*count_t];
				new_cmd->argv[*count_t] = protected_ft_strjoin(ptr,
						environment_variabl);
				free(ptr);
			}
			else
				new_cmd->argv[*count_t] = environment_variabl;
			free(environment_variabl);
		}
		count++;
	}
	return (count);
}
