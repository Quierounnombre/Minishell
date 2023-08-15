/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:59:30 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/15 11:40:31 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ftt_strncmp(const char *s1, const char *s2, size_t n)
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
	if (env)
	{
		while (env[i])
		{
			if (!ftt_strncmp(target, env[i], ft_strlen(target)))
				return (i);
			i++;
		}
	}
	return (FT_INVALID_POS);
}
