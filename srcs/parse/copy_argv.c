/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:14:17 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/16 19:35:20 by lyandriy         ###   ########.fr       */
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

int	variable_type(char *input, t_shell *shell, t_cmd *new_cmd, int *i)
{
	int	c;

	c = 0;
	if (is_34_or_39(input[c + 1]))
	{
		c++;
		c += copy_qm(shell, new_cmd->argv[*i], &input[c], &shell->s_i.copy);
	}
	else
		copy_variable(shell, new_cmd, input, &c);
	return (c);
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
			c += variable_type(&input[c], shell, new_cmd, i);
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
