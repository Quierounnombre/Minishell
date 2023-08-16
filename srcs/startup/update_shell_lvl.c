/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shell_lvl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:31 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/16 18:46:04 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	make_new_shlvl(t_shell *shell);
static t_bool	increase_shlvl(t_shell *shell, int pos_shell_lvl);

t_bool	update_shell_lvl(t_shell *shell)
{
	int		pos_shell_lvl;

	pos_shell_lvl = find_string(shell->env, "SHLVL");
	if (pos_shell_lvl == FT_INVALID_POS)
		return (make_new_shlvl(shell));
	else
		return (increase_shlvl(shell, pos_shell_lvl));
	return (false);
}

static t_bool	increase_shlvl(t_shell *shell, int pos_shell_lvl)
{
	int		value;
	char	*s;
	char	*s_value;

	s = shell->env[pos_shell_lvl];
	s += 6;
	value = ft_atoi(s);
	if (value < 0)
		value = 0;
	value++;
	s_value = ft_itoa(value);
	if (s_value)
	{
		s = ft_strjoin("SHLVL=", s_value);
		if (s)
		{
			free(s_value);
			free(shell->env[pos_shell_lvl]);
			shell->env[pos_shell_lvl] = s;
			return (true);
		}
		free(s_value);
	}
	return (false);
}

static t_bool	make_new_shlvl(t_shell *shell)
{
	int		size;
	int		value;
	char	*s;

	value = 1;
	size = 0;
	while (shell->env[size])
		size++;
	s = ft_itoa(value);
	if (!s)
		return (false);
	make_new_env(shell, s, size);
	free(s);
	return (true);
}
