/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_token_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:47:04 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/14 20:21:51 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

ckeck_token_length(t_shell main_struct, char *my_input, int count, int count_pipe)
{
	int	count_token;
	int	lenght_token;

	count_token = 0;
	lenght_token = 0;
	while (count >= 0 || my_input[count] != '|')
		count--;
	if (my_input[count] == '|')
		count++;
	while (my_input[count] != '|')
	{
		space_tab(my_input, &count);
		lenght_token++;
		count++;
		if (my_input[count] == ' ' || my_input[count] == '\t' || my_input[count] == '|')
		{
			main_struct.input[count_pipe].content[count_token] = malloc(sizeof(char) * (lenght_token + 1));
			count -= lenght_token;
			copy_token(main_struct, my_input, main_struct.input[count_pipe].content[count_token], &count);
			lenght_token = 0;
			count_token++;
		}
	}
}

void	copy_token(t_shell main_struct, char *my_input, char *content, int *count)
{
	int	lenght_token;

	lenght_token = 0;
	while (my_input[*count] != ' ' && my_input[*count] != '\t' && my_input[*count] != '|')
	{
		while
		 (my_input[*count] == '\"' || my_input[*count] == '\'')
			*count += 1;
		content[lenght_token] = my_input[*count];
		*count += 1;
		lenght_token++;
	}
	content[lenght_token] = '\0';
}
