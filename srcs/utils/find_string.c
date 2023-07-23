/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:59:30 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/23 16:52:50 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Localiza un str en un env
@param env el enviroment donde buscar
@param target el string a encontrar
@return la posición del string
*/
int	ftt_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if (*s1 != *s2)
			return (((unsigned char)*s1 - (unsigned char)*s2));
		n--;
		if (*s1 != '\0')
			s1++;
		if (*s2 != '\0')
			s2++;
	}
	if (*s2 != '=')
		return (1);
	return (0);
}

int	find_string(char **env, char *target)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ftt_strncmp(target, env[i], ft_strlen(target)))//coun la funcion anterior habia un problema, eliminaba la var cuando nombre no coincidia, la he modificado un poco
			return (i);
		i++;
	}
	return (i);
}
