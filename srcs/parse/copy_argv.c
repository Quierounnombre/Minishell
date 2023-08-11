/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:14:17 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:35:37 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	copy_variable(t_shell *shell, t_cmd *new_cmd, char *input, int *c)
{
	if (!ft_isalnum(input[*c + 1]) && input[*c + 1] != '?')
	{
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = input[*c];
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy + 1]
			= input[*c + 1];
		shell->s_i.copy += 2;
		*c += 2;
		while (!ft_strchr("| \t><$", input[*c]) && input[*c])
		{
			new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = input[*c];
			shell->s_i.copy += 1;
			*c += 1;
		}
	}
	if (input[*c] && input[*c + 1] == '?')
	{
		if (new_cmd->argv[shell->s_i.ctoken])
			new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
		*c += this_is_env(shell, new_cmd, &input[*c], &shell->s_i.ctoken);
		shell->s_i.copy = ft_strlen(new_cmd->argv[shell->s_i.ctoken]);
	}
	else if (input[*c])
		else_variable(shell, new_cmd, input, c);
}

void	copy_argv(t_shell *shell, t_cmd *new_cmd, char *input)
{
	int	c;
	int	*i;

	c = 0;
	i = &shell->s_i.ctoken;
	shell->s_i.copy = 0;
	while (input[c] != ' ' && input[c] != '\t' && input[c]
		&& !is_pipe(input[c]) && !is_greater_or_smaller(input[c]))
	{
		if (is_34_or_39(input[c]))
			c += copy_qm(shell, new_cmd->argv[*i], &input[c], &shell->s_i.copy);
		if (input[c] == '$')
			copy_variable(shell, new_cmd, input, &c);
		else if (input[c] != ' ' && input[c] != '\t' && input[c]
			&& !is_pipe(input[c]) && !is_greater_or_smaller(input[c])
			&& !is_34_or_39(input[c]) && input[c] != '$')
		{
			new_cmd->argv[*i][shell->s_i.copy] = input[c];
			c++;
			shell->s_i.copy++;
		}
	}
	check_argv(shell, new_cmd);
}
