/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_qm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:33:59 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/04 16:54:38 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function copy_quotation_marks compia el contenido de las comillas
@function this_is_quotation_marks revisa que comilla es y compia el contenido
@function copy_qm copia el contenido de las comillas
*/

//copia el nombre de redireccion si esta entre comillas
int	copy_qm(t_shell *shell, char *argv, char *my_input, int *count_copy)
{
	char	skip;
	int		count;

	count = 1;
	skip = my_input[0];
	while (my_input[count] != skip && my_input[count] != '\0')
	{
		if (my_input[count] == '$' && my_input[0] == '\"')
		{
			if (!ft_isalnum(my_input[count + 1]) && my_input[count + 1] != '?'
				&& my_input[count] != skip)
				argv_alnum(argv, count_copy, &count);
			else
				count += exp_var_qm(shell, &my_input[count], argv, count_copy);
		}
		else
		{
			argv[*count_copy] = my_input[count];
			count++;
			*count_copy += 1;
		}
	}
	if (my_input[count] == skip)
		count++;
	return (count);
}
