/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/22 20:37:44 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	char	*input;

	(void) argc;
	(void) argv;
	shell = malloc(sizeof(t_shell));
	if (start_(shell))
	{
		while (1)
		{
			input = readline("Minishell	");
			if (parse(shell, input, env))
				process();
		}
	}
}
