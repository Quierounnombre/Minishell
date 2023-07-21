/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:16:52 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/21 18:38:50 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function this_is_env copia, busca y expande la variable
@function get_ptr busca la variable en env
@function expand_env expande la variable
@function strncmp_qm busca el nombre de la variable dentro de env
*/
/*void	space_in_env(char *ptr, int *count, int *coun_t, t_cmd *new_cmd)
{
	int	tam;

	tam = 0;
	space_tab(ptr, count);
	*coun_t += 1;
	while (ptr[*count + tam] != ' ' && ptr[*count + tam] != '\t'
		&& ptr[*count + tam] != '\0')
			tam++;
	new_cmd->argv[*coun_t] = ft_calloc((tam + 1), sizeof(char));
}*/

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

//busca la variable en env
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

//trata el $?
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
				new_cmd->argv[*count_t] = ft_strjoin(ptr, environment_variabl);
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
