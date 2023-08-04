/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 11:43:08 by vicgarci         ###   ########.fr       */
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
	//atexit(&seeleaks);
	if (start(&shell, env))
	{
		g_shell = shell;
		while (true)
		{
			input = readline(PROMPT);
			if (input)
			{
				add_history(input);
				if (input && parse(shell, input))
					process_executer(shell);
				free(input);
			}
			else
				sig_d(shell);
		}
	}
}
