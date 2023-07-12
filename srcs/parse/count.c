/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:31:23 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/12 16:32:24 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_quotation_marks(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	(void) shell;
	while (my_input[count] == my_input[0])
	{
		count++;
		while (my_input[count] != my_input[0])
		{
			if (my_input[count] == '\0')
				break ;
			count++;
		}
		if (my_input[count] == my_input[0])
			count++;
	}
	return (count);
}

void	count_dollar(t_shell *shell, char *my_input, int *count)
{
	int	flag;

	flag = 0;
	*count += manage_count_env(shell, &my_input[*count], &flag);
	if (!ft_isalnum(my_input[*count]) && my_input[*count] != '?')
	{
		while (!ft_isalnum(my_input[*count]) && my_input[*count] != '?'
			&& my_input[*count] != ' ' && my_input[*count] != '\t'
			&& my_input[*count] != '\0' && my_input[*count] != '|'
			&& my_input[*count] != '<' && my_input[*count] != '>'
			&& my_input[*count] != '\"' && my_input[*count] != '\'')
		{
			if (my_input[*count] == '$')
				count += manage_count_env(shell, &my_input[*count], &flag);
			else
				count++;
		}
	}
}
