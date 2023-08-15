/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:31:23 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/15 10:55:20 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	count_dollar(t_shell *shell, char *my_input, int *count)
{
	int	flag;

	flag = 0;
	(*count) += manage_count_env(shell, &my_input[*count], &flag);
	if (!ft_isalnum(my_input[*count]) && my_input[*count] != '?')
	{
		while (!ft_isalnum(my_input[*count]) && my_input[*count] != '?'
			&& my_input[*count] != ' ' && my_input[*count] != '\t'
			&& !is_pipe(my_input[*count])
			&& !is_greater_or_smaller(my_input[*count])
			&& !is_34_or_39(my_input[*count])
			&& my_input[*count])
		{
			if (my_input[*count] == '$'
				&& ft_strchr("| \t><", my_input[*count - 1]))
			{
				*count += manage_count_env(shell, &my_input[*count], &flag);
				shell->s_i.size_token++;
			}
			else
				(*count)++;
		}
	}
}
