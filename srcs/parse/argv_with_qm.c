/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_with_qm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:12:25 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 16:12:53 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//tamaño de redireccion con el nombre que tiene comillas
int	argv_with_qm(t_shell *shell, char *my_input, char skip, int *size)
{
	int	count;

	count = 1;
	while (my_input[count] != skip && my_input[count] != '\0')
	{
		if (my_input[count] == '$' && my_input[0] == '\"')
		{
			if (!ft_isalnum(my_input[count + 1]) && my_input[count + 1] != '?'
				&& my_input[count] != skip)
			{
				*size += 1;
				count += 2;
			}
			else
				count += manage_count_env_qm(shell, &my_input[count], size);
		}
		else
		{
			*size += 1;
			count++;
		}
	}
	if (my_input[count] == skip)
		count++;
	return (count);
}
