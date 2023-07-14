/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/14 15:24:11 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	salida(void)
{
	system("leaks -q Minishell");
	system("lsof -c Minishell");
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	char	*input;
	int		i = 2;

	(void) argc;
	(void) argv;
	atexit(salida);
	shell = malloc (sizeof(t_shell));
	if (start(&shell, env))
	{
		while (i--)
		{
			input = readline("Minishell	");
			if (input && *input && parse(shell, input, env))
			{
				process_executer(shell);
			}
			free(input);
			input = NULL;
		}
	}
}
