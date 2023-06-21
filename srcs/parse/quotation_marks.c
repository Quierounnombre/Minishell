/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotation_marks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:51:49 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/19 17:16:47 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function copy_quotation_marks compia el contenido de las comillas
@function this_is_quotation_marks revisa que comilla es y compia el contenido
*/
int	count_quotation(char *my_input, int *size, char skip)
{
	int	count;

	count = 0;
	while (my_input[count] == skip)
	{
		count++;
		while (my_input[count] != skip)
		{
			*size += 1;
			count++;
		}
		count++;
	}
	space_tab(my_input, &count);
	return (count);
}

int	this_is_quotation_marks(t_shell *shell, t_cmd *new_cmd, char *my_input, int *count_token)
{
	int	size;
	int	count;

	size = 0;
	count = 0;
	(void) shell;
	count = count_quotation(my_input, &size, my_input[count]);
	new_cmd->argv[*count_token] = malloc(sizeof(char) * (size + 1));
	if (!new_cmd->argv[*count_token])
		exit (1);
	count = 0;
	while (my_input[count + 1] != my_input[0])
	{
		new_cmd->argv[*count_token][count + 1] = my_input[count];
		count++;
	}
	new_cmd->argv[*count_token][count] = '\0';
	*count_token += 1;
	space_tab(my_input, &count);
	return (count);
}
