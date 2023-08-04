/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_exists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:12:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 11:15:58 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//cuenta la longitud de argv que es una variable con espacios,
//lo cuenta hasta el primer espacio que encuentra
void	ptr_exists(char *ptr, int *size)
{
	int	count_ptr;

	count_ptr = 0;
	while (ptr[count_ptr] != '=')
		count_ptr++;
	if (ptr[count_ptr] == '=')
		count_ptr++;
	while (ptr[count_ptr])
	{
		if (ptr[count_ptr] == ' ' || ptr[count_ptr] == '\t')
			break ;
		count_ptr++;
		*size += 1;
	}	
}
