/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:16:52 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/19 17:10:31 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function this_is_env copia, busca y expande la variable
@function get_ptr busca la variable en env
@function expand_env expande la variable 
*/
static void	expand_env(t_shell *shell, t_cmd *new_cmd, char *ptr, int *coun_t)//coun_t copunt_token
{
	int	count;

	count = 0;
	(void) shell;
	while (ptr[count] != '=')
		count++;
	if (ptr[count] == '=')
		count++;
	while (ptr[count] != '\0')
	{
		space_tab(ptr, &count);
		new_cmd->argv[*coun_t] = copy_token_env(ptr, &count);
		*coun_t += 1;
	}
}

int	strncmp_qm(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s2 != '\0')
	{
		if (*s1 != *s2)
			return (((unsigned char)*s1 - (unsigned char)*s2));
		if (*s1 != '\0')
			s1++;
		if (*s2 != '\0')
			s2++;
	}
	if (*s1 != '=')
		return (1);
	return (0);
}

char	*get_ptr(t_shell *shell, char *ev)
{
	int		count;

	count = 0;
	(void) shell;
	while (shell->env[count] != NULL && ev != NULL)
	{
		if (!(strncmp_qm(shell->env[count], ev)))
			return (shell->env[count]);
		count++;
	}
	return (NULL);
}

int	this_is_env(t_shell *shell, t_cmd *new_cmd, char *input, int *count_token)
{
	int		count;
	char	*ptr;
	char	*environment_variabl;

	count = 1;
	environment_variabl = NULL;
	if (input[count] == '?')
	{
		new_cmd->argv[*count_token] = malloc(sizeof(char) * 3);
		new_cmd->argv[*count_token] = "$?";
		*count_token += 1;
	}
	else
	{
		count += copy_env(shell, &input[count], &environment_variabl);
		if (environment_variabl)
		{
			ptr = get_ptr(shell, environment_variabl);
			if (ptr)
				expand_env(shell, new_cmd, ptr, count_token);
			free (environment_variabl);
		}
	}
	return (count);
}







static void	count_env_qw(char *ptr, int *size)
{
	int	count;

	count = 0;
	while (ptr[count] != '\0')
	{
		*size += 1;
		count++;
	}
}

static void	check_env_qw(t_shell *shell, char *environment_variabl, int *size)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = get_ptr(shell, environment_variabl);
	if (ptr)
		count_env_qw(&ptr[ft_strlen(environment_variabl)], size);
}

int	manage_count_env_qw(t_shell *shell, char *my_input, int *size)
{
	int		count;
	char	*environment_variabl;

	count = 1;
	environment_variabl = NULL;
	if (my_input[count] == '?')
		size++;
	else
	{
		count += copy_env(shell, &my_input[count], &environment_variabl);
		check_env_qw(shell, environment_variabl, size);
		free(environment_variabl);
	}
	space_tab(my_input, &count);
	return (count);
}