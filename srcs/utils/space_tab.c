/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:54:51 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/02 14:55:31 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	space_tab(char *my_input, int *count)
{
	while (my_input[*count] == ' ' || my_input[*count] == '\t')
		(*count)++;
}
