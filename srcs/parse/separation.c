/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:05:28 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/15 17:16:50 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	separation(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	check_size(shell, my_input);
	while (my_input[count] != '\0')
	{
		space_tab(my_input, &count);
		if (my_input[count] == '\"' || my_input[count] == '\'')
		{
			write (1, "hola\n", 5);
			//token_entrecomillada(main_struct, my_input, &count);
		}
		if (my_input[count] == '|')
			check_pipe(shell, my_input, &count);
	}

}

void	token_entrecomillada(t_shell shell, char *my_input, int *count)
{
	int		meter;
	char	caracter;

	meter = 0;
	caracter = my_input[*count];
	*count += 1;
	/*while (my_input[*count] != caracter)
	{
		shell.input.
		*count++;
	}*/
}

/*
void	comando(char *my_input, char **separate_path)
{
	int		count;
	char	**command_array;
	char	*command;

	count = 0;
	command_array = ft_split_m(my_input, 32, 9);
	if(!command_array[0])
		error();
	command = ft_strdup(command_array[0]);
	while (access(command_array[0], F_OK) == -1 && separate_path[count])
	{
		
	}
}*/
