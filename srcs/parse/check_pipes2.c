/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:51:51 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/12 16:52:41 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_error_redirect(char *ptr, int *ptr_count, char *envir_var)
{
	if (!ptr)
	{
		ft_printf("Minishell %s: ambiguous redirect\n", envir_var);
		return (0);
	}
	else
	{
		while (ptr[*ptr_count] != '\0')
		{
			if (ptr[*ptr_count] == ' ' || ptr[*ptr_count] == '\t')
			{
				ft_printf("Minishell %s: ambiguous redirect\n", envir_var);
				return (0);
			}
			*ptr_count += 1;
		}
	}
	return (1);
}

int	check_redirect_env(t_shell *shell, char *input, int *count)
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
			return (0);
		free (environment_variabl);
	}
	return (1);
}
