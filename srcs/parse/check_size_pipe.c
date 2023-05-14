/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:21:07 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/13 21:22:53 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_size_pipe(t_main main_struct, char *my_input)
{
	int		count;

	count = 0;
	main_struct.size_input.size_pipe = 1;
	while (my_input[count] != '\0')
	{
		if (my_input[count] == '\"' || my_input[count] == '\'')
			entrecomillada(my_input, &count);
		if (my_input[count] == "|")
			check_pipe(main_struct, my_input, &count);
		count++;
	}
	main_struct.input = malloc(sizeof(t_list) * (main_struct.size_input.size_pipe + 1));
	if (!main_struct.input)
		ft_error();
}

void	entrecomillada(char *my_input, int *count)
{
	if (my_input[*count] == '\'')
	{
		*count++;
		while (my_input[*count] != '\'' || my_input[*count])
			*count++;
		if (!my_input[*count])
			ft_error();
	}
	if (my_input[*count] == '\"')
	{
		*count++;
		while (my_input[*count] != '\"' || my_input[*count])
			*count++;
		if (!my_input[*count])
			ft_error();
	}
}

void	check_pipe(t_main main_struct, char *my_input, int *count)
{
	int		check_pipe;

	*count++;
	space_tab(my_input, count);
	check_pipe = *count;
	if (my_input[check_pipe] == '\0')
		ft_error();
	if (my_input[check_pipe] == '|')
		syntax_error_near_unexpected_token();
	main_struct.size_input.size_pipe++;
}