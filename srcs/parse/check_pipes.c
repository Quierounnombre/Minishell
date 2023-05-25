/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:21:07 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/25 10:45:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
check_pipes revisa las comillas y si los pipes estan bieny la cantidad de redirecciones
quotation_marks revisa las comillas
check_pipe_end revisa si el pipe esta escrito bien
*/
static void	check_pipe_end(t_shell *shell, char *my_input, int *count)
{
	int	check_pipe;

	*count += 1;
	space_tab(my_input, count);
	check_pipe = *count;
	if (my_input[check_pipe] == '\0')
	{
		write (1, "hola\n", 5);
		//ft_error();
	}
	space_tab(my_input, count);
	if (my_input[check_pipe] == '|')
	{
		write (1, "hola\n", 5);
		//syntax_error_near_unexpected_token();
	}
	shell->size_input.size_pipe++;
}

int	check_pipes(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	shell->size_input.size_pipe = 1;
	shell->size_input.size_redir =  0;
	while (my_input[count] != '\0')
	{
		if (my_input[count] == '\"' || my_input[count] == '\'')
			quotation_marks(my_input, &count);
		if (my_input[count] == '>' || my_input[count] == '<')
		{
			if (my_input[count + 1] == '<' || my_input[count + 1] == '>')
				count++;
			shell->size_input.size_redir++;
		}
		if (my_input[count] == '|')
			check_pipe_end(shell, my_input, &count);
		count++;
	}
	if (shell->size_input.size_redir == 0)
		shell->size_input.size_redir++;
	return (1);
}
