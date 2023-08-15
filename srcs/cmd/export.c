/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/15 16:26:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	check_name(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '=')
	{
		if (!ft_isalnum(s[i]) || ft_isdigit(s[i]))
		{
			ft_printf("%s: %s: '%s': %s\n",
				"Minishell",
				"export",
				s,
				"not a valid identifier");
			return (false);
		}
		i++;
	}
	return (true);
}

static char	*load_target(char *s)
{
	char	*target;
	int		i;

	if (!check_name(s))
		return (NULL);
	i = 0;
	while (s[i] != '=' && s[i])
		i++;
	target = NULL;
	target = (char *)malloc(sizeof(char) * (i + 2));
	if (!target)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '=')
	{
		target[i] = s[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}

void	ft_export(t_shell *shell, char	*s)
{
	int		i;
	int		size_env;
	char	*target;

	target = NULL;
	target = load_target(s);
	if (!target)
		return ;
	size_env = 0;
	while (shell->env[size_env])
		size_env++;
	i = 0;
	i = find_string(shell->env, target);
	if (i == FT_INVALID_POS)
		make_new_env(shell, s, size_env);
	else
	{
		free(shell->env[i]);
		shell->env[i] = ft_strdup(s);
		if (!shell->env[i])
			ft_error(shell, errno);
	}
	free(target);
}
