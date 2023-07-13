/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/13 18:15:59 by lyandriy         ###   ########.fr       */
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

	(void) argc;
	(void) argv;
	atexit(salida);
	shell = malloc (sizeof(t_shell));
	if (start(&shell, env))
	{
		while (true)
		{
			input = readline("Minishell	");
			if (parse(shell, input, env))
				process_executer(shell);
		}
	}
}
