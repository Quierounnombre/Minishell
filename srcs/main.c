/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/25 10:39:44 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*s;
	t_shell	*shell;
	char	*input;

	if (start(&shell))
	{
		s = ft_open_file(shell);
		while (argc && argv)
		{
			input = readline("Minishell	");
			if (parse(shell, input, env))
				process_executer(shell);
		}
	}
}
