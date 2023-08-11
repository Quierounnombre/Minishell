/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:49:35 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/11 12:36:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_env(t_shell *shell, char *input, int *count)
{
	char	*ptr;
	int		ptr_count;
	char	*environment_variabl;

	ptr = NULL;
	ptr_count = 0;
	*count += 1;
	environment_variabl = NULL;
	*count += copy_env(shell, &input[*count], &environment_variabl);
	if (environment_variabl)
	{
		ptr = get_ptr(shell, environment_variabl);
		if (ptr)
			find_start_of_str(ptr, &ptr_count);
		if (ptr)
		{
			free(environment_variabl);
			return (&ptr[ptr_count]);
		}
		free(environment_variabl);
	}
	return (NULL);
}
