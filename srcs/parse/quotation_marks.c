/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotation_marks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:33:59 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/22 20:21:26 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
quotation_marks revisa las comillas
simple_quotation_marks revisa simple comillas
doble_quotation_marks revisa doble comillas
*/
static void	simple_quotation_marks(char *my_input, int *count)
{
	int	number;
	int comillas;

	number = 0;
	comillas = *count;
	while (my_input[comillas] != '\0')//cuenta cantidad de comillas
		{
			if (my_input[comillas] == '\'')
				number++;
			comillas += 1;
		}
		if (number % 2 != 0)//revisa la cantidad de comillas
			return (0);
		while (my_input[*count] != '\'' && my_input[*count])//se pasa al final de las comilas
			*count += 1;
		*count += 1;
}

static void	double_quotation_marks(char *my_input, int *count)
{
	int	number;
	int comillas;

	number = 0;
	comillas = *count;
	while (my_input[comillas] != '\0')//cuenta cantidad de comillas
	{
		if (my_input[comillas] == '\"')
			number++;
		comillas++;
	}
	if (number % 2 == 0)//revisa la cantidad de comillas
		return (0);
	while (my_input[*count] != '\"' && my_input[*count])//se pasa al final de las comilas
		*count += 1;
	*count += 1;
}

void	quotation_marks(char *my_input, int *count)
{
	*count += 1;
	if (my_input[*count - 1] == '\'')
		simple_quotation_marks(my_input, count);
	if (my_input[*count - 1] == '\"')
		double_quotation_marks(my_input, count);
}
