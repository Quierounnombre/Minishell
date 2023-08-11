/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cmd_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:01:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:35:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	manage_count_env_with_space(t_shell *shell, char *input, int *size)
{
	int		count;
	char	*ptr;
	char	*environment_variabl;

	count = 1;
	environment_variabl = NULL;
	count += copy_env(shell, &input[count], &environment_variabl);
	if (environment_variabl)
	{
		ptr = get_ptr(shell, environment_variabl);
		if (ptr)
			ptr_exists(ptr, size);
		free(environment_variabl);
	}
	return (count);
}

static int	count_tam_argv(t_shell *shell, char *input, int *c)
{
	int	size;

	size = 0;
	while (input[*c] != ' ' && input[*c] != '\t' && input[*c]
		&& !is_pipe(input[*c]) && !is_greater_or_smaller(input[*c]))
	{
		if (is_34_or_39(input[*c]))
			*c += argv_with_qm(shell, &input[*c], input[*c], &size);
		if (input[*c] == '$'
			&& !ft_isalnum(input[*c + 1]) && input[*c + 1] != '?')
		{
			size += 2;
			*c += 2;
		}
		else if (input[*c] == '$')
			*c += manage_count_env_with_space(shell, &input[*c], &size);
		else if (input[*c] != ' ' && input[*c] != '\t' && input[*c]
			&& !is_greater_or_smaller(input[*c]) && !is_pipe(input[*c])
			&& !is_34_or_39(input[*c]) && input[*c] != '$')
		{
			size++;
			*c += 1;
		}
	}
	return (size);
}

static int	this_is_argv(t_shell *shell, t_cmd *new_cmd, char *my_input)
{
	int	count;
	int	size;

	size = 0;
	count = 0;
	size = count_tam_argv(shell, my_input, &count);
	new_cmd->argv[shell->s_i.ctoken] = malloc(sizeof(char) * (size + 1));
	if (!new_cmd->argv[shell->s_i.ctoken])
		exit (1);
	copy_argv(shell, new_cmd, my_input);
	shell->s_i.ctoken += 1;
	space_tab(my_input, &count);
	return (count);
}

void	copy_cmd_token(t_shell *shell, t_cmd *new_cmd, char *input)
{
	int	count;

	count = 0;
	shell->s_i.ctoken = 0;
	while (!is_pipe(input[count]) && input[count])
	{
		space_tab(input, &count);
		if (is_greater_or_smaller(input[count]))
			count += this_is_redirection(shell, new_cmd, &input[count]);
		if (input[count] && !is_pipe(input[count])
			&& !is_greater_or_smaller(input[count]))
			count += this_is_argv(shell, new_cmd, &input[count]);
	}
	if (new_cmd->argv[0])
		ft_path(shell, new_cmd);
}
