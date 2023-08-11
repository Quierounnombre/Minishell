/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_count_env_qm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:16:12 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/11 12:36:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	count_env_qm(char *ptr, int *size)
{
	int	count;

	count = 0;
	while (ptr[count] != '\0')
	{
		count++;
		if (ptr[count] != '\0')
			*size += 1;
	}
}

static void	check_env_qm(t_shell *shell, char *environment_variabl, int *size)
{
	char	*ptr;

	ptr = get_ptr(shell, environment_variabl);
	if (ptr)
		count_env_qm(&ptr[ft_strlen(environment_variabl)], size);
}

int	manage_count_env_qm(t_shell *shell, char *my_input, int *size)
{
	int		count;
	char	*environment_variabl;

	count = 1;
	environment_variabl = NULL;
	if (my_input[count] == '?')
	{
		*size += ft_calclen2(shell->child_status);
		count++;
	}
	else
	{
		count += copy_env(shell, &my_input[count], &environment_variabl);
		if (environment_variabl)
		{
			check_env_qm(shell, environment_variabl, size);
			free(environment_variabl);
		}
	}
	return (count);
}
