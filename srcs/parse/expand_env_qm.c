/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_qm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:46:44 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 16:47:03 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	expand_env_qm(char *ptr, char *argv, int *count_copy)
{
	int	count_ptr;

	count_ptr = 0;
	while (ptr[count_ptr] != '=')
		count_ptr++;
	if (ptr[count_ptr] == '=')
		count_ptr++;
	while (ptr[count_ptr] != '\0')
	{
		argv[*count_copy] = ptr[count_ptr];
		count_ptr++;
		*count_copy += 1;
	}
}
