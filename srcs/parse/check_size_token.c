/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:23:22 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/13 21:47:08 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_size_token(t_main main_struct, char *my_input)
{
	int	count;
	int	start;
	int	count_pipe;

	count = 0;
	count_pipe = 0;
	main_struct.size_input.size_token = 0;
	while (my_input[count] != '\0')
	{
		size_special_token(main_struct, my_input, &count);
		if (my_input[count] == '|')
		{
			count++;
			start = count;
			main_struct.input[count_pipe].content = malloc(sizeof(char *) * (main_struct.size_input.size_token + 1));
			if (!main_struct.input[count_pipe].content)
				ft_error();
			count_pipe++;
			
			main_struct.size_input.size_token = 0;
			
		}
		else
			this_is_size_command_token(main_struct, my_input, &count);
	}
}

void	size_special_token(t_main main_struct, char *my_input, int *count)
{
	space_tab(my_input, &count);
	if (my_input[*count] == '\"' || my_input[*count] == '\'')
	{
		entrecomillada(my_input, &count);
		main_struct.size_input.size_token++;
	}
	if (my_input[*count] == '<' || my_input[*count] == '>')
		redirects(main_struct, my_input, &count);
	if (my_input[*count] == '$')
	{
		if (my_input[*count++] == '!')
			pipe_exit_code();
		if (my_input[*count] != '\0' && my_input[*count] != ' ' &&
			my_input[*count] != '\t')
			this_is_environment_variabl();
	}
}

void	this_is_size_command_token(t_main main_struct, char *my_input, int *count)
{
	while(my_input[*count] != ' ' || my_input[*count] != '\t')
		*count++;
	main_struct.size_input.size_token++;
}

void	redirects(t_main main_struct, char *my_input, int *count)
{
	if (my_input[*count] == '<' || my_input[*count + 1] != '<')
		REDIRECT_INPUT;
	if (my_input[*count] == '>' || my_input[*count + 1] != '>')
		REDIRECT_OUTPUT;
	if (my_input[*count] == '<' || my_input[*count + 1] == '<')
		HERE_DOC;
	if (my_input[*count] == '>' || my_input[*count + 1] == '>')
		MODO_APPEND;
	*count++;
	space_tab(my_input, count);
	while (my_input[*count] != ' ' && my_input[*count] != '\t')
	{

		*count++;
	}
}