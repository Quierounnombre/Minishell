/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/24 16:44:27 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*s;
	t_shell	*shell;
	char	*input;

	if (start(&shell, env))
	{
		s = ft_open_file(shell);
		while (argc && argv)
		{
			input = readline("Minishell	");
			if (parse(shell, input, env))
				process();
		}
	}
}
