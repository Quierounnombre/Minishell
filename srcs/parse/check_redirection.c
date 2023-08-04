/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:52:48 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 12:01:36 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	check_redirection(t_shell *shell, char *my_input, int *count)
{
	(*count)++;
	if (my_input[*count] == my_input[(*count) - 1])
		(*count)++;
	space_tab(my_input, count);
	if (!my_input[*count]
		|| is_greater_or_smaller(my_input[*count])
		|| is_pipe(my_input[*count]))
	{
		ft_printf("%s\n", "Minishell syntax error near unexpected token");
		return (false);
	}
	while (my_input[*count]
		&& !is_pipe(my_input[*count])
		&& !is_34_or_39(my_input[*count])
		&& !is_greater_or_smaller(my_input[*count]))
	{
		if (my_input[*count] == '$')
		{
			if (!check_redirect_env(shell, my_input, count))
				return (false);
		}
		*count += 1;
	}
	return (true);
}
