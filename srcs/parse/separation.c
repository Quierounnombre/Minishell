/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:40:40 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/16 18:35:29 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_command_token(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	while (my_input[count] && !ft_strchr("| \t><", my_input[count]))
	{
		if (is_34_or_39(my_input[count]))
			count += count_quotation_marks(&my_input[count]);
		if (my_input[count] == '$')
			count_dollar(shell, my_input, &count);
		if (my_input[count] && !ft_strchr("| \t><", my_input[count])
			&& !is_34_or_39(my_input[count]))
			count++;
	}
	space_tab(my_input, &count);
	shell->s_i.size_token++;
	return (count);
}

static int	count_redirects(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	if (my_input[count] == '<')
		shell->s_i.size_in += 1;
	if (my_input[count] == '>')
		shell->s_i.size_out += 1;
	count++;
	if (is_greater_or_smaller(my_input[count]))
		count++;
	space_tab(my_input, &count);
	while (my_input[count] != ' ' && my_input[count] != '\t'
		&& my_input[count] && !is_pipe(my_input[count])
		&& !is_greater_or_smaller(my_input[count]))
		count++;
	space_tab(my_input, &count);
	return (count);
}

static void	count_size(t_shell *shell, char *input, int *count)
{
	space_tab(input, count);
	if (is_greater_or_smaller(input[*count]))
		*count += count_redirects(shell, &input[*count]);
	if (input[*count] && !is_pipe(input[*count])
		&& !is_greater_or_smaller(input[*count]))
		*count += count_command_token(shell, &input[*count]);
}

void	separation(t_shell *shell, char *my_input)
{
	int		count;
	int		start;
	t_cmd	*new_cmd;

	count = 0;
	set_s_i(shell);
	while (my_input[count])
	{
		start = count;
		while (!is_pipe(my_input[count]) && my_input[count])
			count_size(shell, my_input, &count);
		if (is_pipe(my_input[count]) || my_input[count] == '\0')
		{
			new_cmd = NULL;
			create_node(shell, new_cmd, &my_input[start]);
			if (is_pipe(my_input[count]))
				count++;
			set_s_i(shell);
		}
	}
}
