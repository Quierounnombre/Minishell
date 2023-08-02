/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_start_of_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:59:56 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/02 15:00:06 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_start_of_str(char *ptr, int *ptr_count)
{
	while (ptr[*ptr_count] != '=')
		*ptr_count += 1;
	if (ptr[*ptr_count] == '=')
		*ptr_count += 1;
}
