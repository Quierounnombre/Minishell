/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:16:52 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/03 12:30:09 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function this_is_env copia, busca y expande la variable
@function get_ptr busca la variable en env
@function expand_env expande la variable
@function strncmp_qm busca el nombre de la variable dentro de env
*/

static int	strncmp_qm(const char *s1, const char *s2)
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
	while (shell->env[count] && ev)
	{
		if (!(strncmp_qm(shell->env[count], ev)))
			return (shell->env[count]);
		count++;
	}
	return (NULL);
}
