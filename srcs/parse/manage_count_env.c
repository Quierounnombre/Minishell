/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_count_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:27:07 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/11 12:37:10 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	count_env(t_shell *shell, char *ptr)
{
	int	count;

	count = 0;
	while (ptr[count])
	{
		if (ptr[count] == ' ' || ptr[count] == '\t')
		{
			space_tab(ptr, &count);
			shell->s_i.size_token++;
		}
		count++;
	}
}

static void	check_env(t_shell *shell, char *environment_variabl)
{
	char	*ptr;

	ptr = get_ptr(shell, environment_variabl);
	if (ptr)
		count_env(shell, &ptr[ft_strlen(environment_variabl)]);
}

int	manage_count_env(t_shell *shell, char *my_input, int *flag)
{
	int		count;
	char	*environment_variabl;

	count = 1;
	if (my_input[0] == '$')
	{
		*flag = 0;
		environment_variabl = NULL;
		if (my_input[count] != '?')
		{
			count += copy_env(shell, &my_input[count], &environment_variabl);
			if (environment_variabl)
			{
				*flag = 1;
				check_env(shell, environment_variabl);
				free(environment_variabl);
			}
		}
	}
	return (count);
}
