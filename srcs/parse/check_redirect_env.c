/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirect_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:05:15 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/03 12:14:41 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	check_error_redirect(char *ptr, int *ptr_count, char *envir_var)
{
	if (!ptr)
	{
		ft_printf("Minishell $%s: ambiguous redirect\n", envir_var);
		return (false);
	}
	else
	{
		while (ptr[*ptr_count] != '\0')
		{
			if (ptr[*ptr_count] == ' ' || ptr[*ptr_count] == '\t')
			{
				ft_printf("Minishell %s: ambiguous redirect\n", envir_var);
				return (false);
			}
			*ptr_count += 1;
		}
	}
	return (true);
}

t_bool	check_redirect_env(t_shell *shell, char *input, int *count)
{
	int		ptr_count;
	char	*ptr;
	char	*environment_variabl;

	ptr_count = 0;
	environment_variabl = NULL;
	*count += copy_env(shell, &input[*count + 1], &environment_variabl);
	if (environment_variabl)
	{
		ptr = get_ptr(shell, environment_variabl);
		if (!check_error_redirect(ptr, &ptr_count, environment_variabl))
		{
			free(environment_variabl);
			return (false);
		}
		free (environment_variabl);
	}
	return (true);
}
