/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:55:04 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/25 10:46:36 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
recorre espacios y tabulaciones
*/
void	space_tab(char *my_input, int *count)
{
	while (my_input[*count] == ' ' || my_input[*count] == '\t')
		*count += 1;
}
