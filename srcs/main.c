/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/12 18:17:41 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	char	*input;

	(void) argc;
	(void) argv;
	shell = malloc (sizeof(t_shell));
	if (start(&shell, env))
	{
		while (true)
		{
			input = readline("Minishell	");
			ft_printf("HERE\n");
			if (parse(shell, input, env))
			{
				ft_printf("HER\n");
				process_executer(shell);
				ft_printf("HE\n");
			}
		}
	}
}
