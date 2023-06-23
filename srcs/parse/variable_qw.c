/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_qw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:16:12 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/19 16:22:49 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function expand_variable_qw
*/
static void	expand_env_qw(char *ptr, char *argv, int *count_copy)
{
	int	count;
	int	count_ptr;

	count = 0;
	count_ptr = 0;
	while (ptr[count_ptr] != '=')
		count_ptr++;
	if (ptr[count_ptr] == '=')
		count_ptr++;
	while (ptr[count_ptr] != '\0')
	{
		argv[*count_copy] = ptr[count_ptr];
		count_ptr++;
		*count_copy += 1;
	}
}

int	exp_var_qm(t_shell *shell, char *my_input, char *argv, int *count_copy)
{
	char	*environment_variabl;
	char	*ptr;
	int		count;

	count = 1;
	ptr = NULL;
	environment_variabl = NULL;
	count += copy_env(shell, &my_input[count], &environment_variabl);
	if (environment_variabl)
	{
		ptr = get_ptr(shell, environment_variabl);
		if (ptr)
			expand_env_qw(ptr, argv, count_copy);
		free (environment_variabl);
	}
	return (count);
}
/*
static void	count_env_qw(t_shell *shell, char *ptr)
{
	int	count;

	count = 0;
	while (ptr[count] != '\0')
	{
		if (ptr[count] == ' ' || ptr[count] == '\t')
		{
			space_tab(ptr, &count);
			shell->size_input.size_token++;
		}
		count++;
	}
	shell->size_input.size_token++;
}

static void	check_env_qw(t_shell *shell, char *environment_variabl)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = NULL;
	while (ptr == NULL && shell->env[count] != NULL &&
		environment_variabl != NULL) 
	{
		ptr = ft_strnstr(shell->env[count], environment_variabl,
				ft_strlen(shell->env[count]));
		count++;
	}
	if (ptr)
		count_env_qw(shell, &ptr[ft_strlen(environment_variabl)]);
}

int	manage_count_env_qw(t_shell *shell, char *my_input)
{
	int		count;
	char	*environment_variabl;

	count = 1;
	environment_variabl = NULL;
	if (my_input[count] == '?')
		count++;
	else
	{
		count += copy_env(shell, &my_input[count], &environment_variabl);
		if (my_input[count] == '\"' && my_input[count + 1] == '\0')
			count++;
		check_env(shell, environment_variabl);
		free(environment_variabl);
	}
	space_tab(my_input, &count);
	return (count);
}*/