/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/23 17:57:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	char	*input;

	(void) argc;
	(void) argv;
	if (start(&shell, env))
	{
		while (argc && argv)
		{
			input = readline("Minishell	");
			if (parse(shell, input, env))
				process_executer(shell);
		}
	}
}
