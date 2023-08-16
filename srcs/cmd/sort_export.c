/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:35:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/16 19:57:45 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_formated_env(const char **env);
static void	sort_by_letter(char **env, int c);
static void	sort_env(char **env);

//	ft_printf("%s%s\n\n\n\n", EXPORT_STR,
//		"https://www.man7.org/linux/man-pages/man1/export.1p.html");

void	sort_export(t_shell *shell)
{
	t_shell	local_shell;
	char	**env;
	char	*s;

	local_shell.env = NULL;
	if (clone_env(shell->env, &local_shell))
	{
		sort_env(local_shell.env);
		print_formated_env((const char **)local_shell.env);
		env = local_shell.env;
		while (*env)
		{
			s = *env;
			env++;
			free(s);
		}
		free(local_shell.env);
	}
	else
		perror("export");
}

static void	print_formated_env(const char **env)
{
	while (*env)
	{
		ft_printf("declare -x \"%s\"\n", *env);
		env++;
	}
}

static void	sort_env(char **env)
{
	char	c;

	c = 'A';
	while (c != 'Z')
	{
		sort_by_letter(env, c);
		c++;
	}
}

static void	sort_by_letter(char **env, int c)
{
	char	*s;
	int		i;
	int		start;

	i = 0;
	while (env[i] && *(env[i]) <= c && ft_ismayus(c))
		i++;
	start = i;
	while (env[i] && ft_ismayus(c))
	{
		if (*(env[i]) == c)
		{
			s = env[start];
			env[start] = env[i];
			env[i] = s;
			start++;
			i = start;
		}
		else
			i++;
	}
}
