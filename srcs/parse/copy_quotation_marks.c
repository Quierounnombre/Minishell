/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_quotation_marks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:19:12 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/24 17:38:52 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
copy_simple_quotation_marks copia token de simple comilla
copy_doble_quotation_marks copia token de doble comilla
this_is_quotation_marks gestiona comillas
*/
void	copy_simple_quotation_marks(char *my_input, int *count, char *content)
{
	int lenght_token;

	lenght_token = 0;
	while(my_input[*count] != '\'')
	{
		lenght_token++;
		*count += 1;
	}
	content = malloc(sizeof(char) * (lenght_token + 1));
	*count -= lenght_token;
	lenght_token = 0;
	while(my_input[*count] != '\'')
	{
		content[lenght_token] = my_input[*count];
		*count += 1;
		lenght_token++;
	}
}

void	copy_doble_quotation_marks(char *my_input, int *count, char *content)
{
	int lenght_token;

	lenght_token = 0;
	while(my_input[*count] != '\"')
	{
		lenght_token++;
		*count += 1;
	}
	content = malloc(sizeof(char) * (lenght_token + 1));
	*count -= lenght_token;
	lenght_token = 0;
	while(my_input[*count] != '\"')
	{
		content[lenght_token] = my_input[*count];
		*count += 1;
		lenght_token++;
	}
}

int	this_is_quotation_marks(char *my_input, int *count, t_cmd *new_cmd, int *count_token)
{
	*count += 1;
	if (my_input[*count - 1] == '\'')
		copy_simple_quotation_marks(my_input, count, new_cmd->argv[*count_token]);
	if (my_input[*count - 1] == '\"')
		copy_doble_quotation_marks(my_input, count, new_cmd->argv[*count_token]);
	*count += 1;
	*count_token += 1;
	space_tab(my_input, count);
	return (1);
}
