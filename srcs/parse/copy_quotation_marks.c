/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_quotation_marks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:19:12 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/22 20:23:51 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
copy_simple_quotation_marks copia token de simple comilla
copy_doble_quotation_marks copia token de doble comilla
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