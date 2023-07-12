/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/24 16:10:47 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	start_(t_shell *shell)
{
	shell->separate_path = NULL;
	shell->env = NULL;
	shell->cmds = malloc(sizeof(t_lstmng));
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	char	*input;

	(void) argc;
	(void) argv;
	shell = malloc (sizeof(t_shell));
	if (start_(shell))
	{
		while (argc && argv)
		{
			input = readline("Minishell	");
			if (parse(shell, input, env))
				printf("\n");
				//process_executer(shell);
		}
	}
}
