/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:21:07 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/16 16:51:40 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	check_pipe_end(t_shell *shell, char *my_input, int *count)
{
	(*count)++;
	space_tab(my_input, count);
	if (!my_input[*count])
		return (false);
	space_tab(my_input, count);
	if (is_pipe(my_input[*count]))
		return (false);
	else
		shell->s_i.size_pipe++;
	return (true);
}

static t_bool	quotation_marks(char *my_input, int *count)
{
	char	skip;

	skip = my_input[*count];
	(*count)++;
	while (my_input[*count] && my_input[*count] != skip)
		(*count)++;
	if (my_input[*count] == skip)
	{
		(*count)++;
		return (true);
	}
	return (false);
}

static t_bool	check_special(t_shell *shell, char *my_input, int *count)
{
	if (is_34_or_39(my_input[*count]))
	{
		if (!(quotation_marks(my_input, count)))
			return (print_err(UNEXPECTED_TOKEN));
		space_tab(my_input, count);
	}
	if (is_greater_or_smaller(my_input[*count]))
	{
		if (!check_redirection(shell, my_input, count))
			return (false);
		space_tab(my_input, count);
	}
	if (is_pipe(my_input[*count]))
	{
		if (!check_pipe_end(shell, my_input, count))
			return (print_err(UNEXPECTED_TOKEN));
		space_tab(my_input, count);
	}
	return (true);
}

t_bool	check_pipes(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	shell->s_i.size_pipe = 1;
	space_tab(my_input, &count);
	if (is_pipe(my_input[count]))
		return (print_err("Minishell syntax error near unexpected token `|'"));
	while (my_input && my_input[count])
	{
		space_tab(my_input, &count);
		if (!check_special(shell, my_input, &count))
			return (false);
		if (!is_pipe(my_input[count]) && !is_34_or_39(my_input[count])
			&& !is_greater_or_smaller(my_input[count]) && my_input[count])
			count++;
	}
	return (true);
}
