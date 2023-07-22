/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:57:56 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 17:36:39 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	ftt_strcmp(char const *s1, char const *s2)// tu funcion ft_strcmp no va bien
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] || s2[i])
		return (0);
	return (1);
}

t_bool	is_built_in(t_cmd *cmd)
{
	if (cmd->argv[0])//los built_in los tenemos que hacer nosotros no el execv
	{
		if (ftt_strcmp(cmd->argv[0], "echo"))
			return (true);
		if (ftt_strcmp(cmd->argv[0], "cd"))
			return (true);
		if (ftt_strcmp(cmd->argv[0], "pwd"))
			return (true);
		if (ftt_strcmp(cmd->argv[0], "export"))
			return (true);
		if (ftt_strcmp(cmd->argv[0], "unset"))
			return (true);
		if (ftt_strcmp(cmd->argv[0], "env"))
			return (true);
		if (ftt_strcmp(cmd->argv[0], "exit"))
			return (true);
	}
	return (false);
}
