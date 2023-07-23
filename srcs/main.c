/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 20:31:13 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	seeleaks()
{
	system("leaks -q minishell");
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	char	*input;

	(void) argc;
	(void) argv;
	shell = malloc (sizeof(t_shell));
	if (start(&shell, env))
	{
		//atexit(&seeleaks);
		while (true)
		{
			input = readline("Minishell	");
			if (input)
			{
				add_history(input);
				if (input && parse(shell, input, env))
					process_executer(shell);
				free(input);
			}
		}
	}
}
