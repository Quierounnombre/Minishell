/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/15 17:25:58 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Documentación pls + esto no lo íbamos a meterlo en una función parse?

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;
	char	*my_input;

	if (start(&shell))
	{
		while (5)
		{
			my_input = readline("Minishell	");
			if (my_input)
			{
				path_function(env, &shell);
				separation(&shell, my_input);
			}
		}
	}
}
