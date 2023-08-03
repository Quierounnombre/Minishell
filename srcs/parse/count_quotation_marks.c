/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_quotation_marks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:43:48 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/03 15:45:48 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_quotation_marks(char *my_input)
{
	int	count;

	count = 0;
	while (my_input[count] == my_input[0])
	{
		count++;
		while (my_input[count] != my_input[0])
		{
			if (!my_input[count])
				break ;
			count++;
		}
		if (my_input[count] == my_input[0])
			count++;
	}
	return (count);
}
