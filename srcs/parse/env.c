/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:16:52 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/29 20:08:00 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function this_is_env copia, busca y expande la variable
@function get_ptr busca la variable en env
@function expand_env expande la variable
@function strncmp_qm busca el nombre de la variable dentro de env
*/
static void	expand_env(t_shell *shell, t_cmd *new_cmd, char *ptr, int *coun_t)
{
	int		count;
	char	*temp;
	int		tam;

	count = 0;
	(void) shell;//coun_t copunt_token
	while (ptr[count] != '=')
		count++;
	if (ptr[count] == '=')
		count++;
	while (ptr[count] != '\0')
	{
		space_tab(ptr, &count);
		if (new_cmd->argv[*coun_t] != NULL)
		{
			temp = new_cmd->argv[*coun_t];
			new_cmd->argv[*coun_t] = ft_strjoin(temp,
				copy_token_env(ptr, &count));
			free(temp);
		}
		if (new_cmd->argv[*coun_t] == NULL)
			new_cmd->argv[*coun_t] = copy_token_env(ptr, &count);
		if (ptr[count] == ' ' || ptr[count] == '\t')
		{
			space_tab(ptr, &count);
			*coun_t += 1;
			tam = 0;
			while(ptr[count + tam] != ' ' && ptr[count + tam] != '\t'
				&& ptr[count + tam] != '\0')
				tam++;
			new_cmd->argv[*coun_t] = ft_calloc((tam + 1), sizeof(char));
		}
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
		new_cmd->argv[*count_token] = ft_itoa(shell->child_status);
		count++;
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
