/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:33:29 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/12 16:38:02 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	copy_str(t_shell *shell, t_cmd *new_cmd, char *input, int *c)
{
	char	*ptr;

	ptr = NULL;
	if (new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] != '\0')
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
	ptr = new_cmd->argv[shell->s_i.ctoken];
	new_cmd->argv[shell->s_i.ctoken] = ft_strjoin(ptr, copy_tex_argv(input, c));
	shell->s_i.copy = ft_strlen(new_cmd->argv[shell->s_i.ctoken]);
	free(ptr);
}

static void	copy_var_qm(t_shell *shell, t_cmd *new_cmd, char *input, int *c)
{
	char	*ptr;

	ptr = NULL;
	if (new_cmd->argv[shell->s_i.ctoken])
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
	ptr = new_cmd->argv[shell->s_i.ctoken];
	new_cmd->argv[shell->s_i.ctoken]
		= ft_strjoin(ptr, copy_text_qm(shell, input, c));
	shell->s_i.copy = ft_strlen(new_cmd->argv[shell->s_i.ctoken]);
	free(ptr);
}

static void	variable_exit_code(t_shell *shell, t_cmd *new_cmd, int *c)
{
	char	*temp;
	char	*ptr;

	ptr = NULL;
	temp = ft_itoa(shell->child_status);
	if (new_cmd->argv[shell->s_i.ctoken])
	{
		if (new_cmd->argv[shell->s_i.ctoken])
			new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
		ptr = new_cmd->argv[shell->s_i.ctoken];
		new_cmd->argv[shell->s_i.ctoken]
			= ft_strjoin(new_cmd->argv[shell->s_i.ctoken], temp);
		shell->s_i.copy = ft_strlen(new_cmd->argv[shell->s_i.ctoken]);
		free(ptr);
		free(temp);
	}
	else
		new_cmd->argv[shell->s_i.ctoken] = ft_itoa(shell->child_status);
	*c += 2;
}

static void	copy_next_var(t_shell *shell, t_cmd *new_cmd, char *input, int *c)
{
	char	*ptr;

	ptr = NULL;
	if (!ft_isalnum(input[*c + 1]) && input[*c + 1] != '?')
	{
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = input[*c];
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy + 1] = input[*c + 1];
		shell->s_i.copy += 2;
		*c += 2;
	}
	else if (input[*c + 1] == '?')
		variable_exit_code(shell, new_cmd, c);
	else
	{
		ptr = find_env(shell, input, c);
		expand_env(ptr, new_cmd, &shell->s_i.ctoken, &shell->s_i.copy);
	}
}

void	else_variable(t_shell *shell, t_cmd *new_cmd, char *input, int *c)
{
	char	*ptr;

	ptr = NULL;
	ptr = find_env(shell, input, c);
	if (ptr)
		expand_env(ptr, new_cmd, &shell->s_i.ctoken, &shell->s_i.copy);
	if (input[*c] != ' ' && input[*c] != '\t'
		&& input[*c] != '\0' && input[*c] != '>'
		&& input[*c] != '|' && input[*c] != '<')
	{
		while (input[*c] != ' ' && input[*c] != '\t' && input[*c] != '\0'
			&& input[*c] != '>' && input[*c] != '|' && input[*c] != '<')
		{
			if (input[*c] != '$' && input[*c] != '\"' && input[*c] != '\'')
				copy_str(shell, new_cmd, input, c);
			if (input[*c] == '$')
				copy_next_var(shell, new_cmd, input, c);
			if (input[*c] == '\"' || input[*c] == '\'')
				copy_var_qm(shell, new_cmd, input, c);
		}
	}
}
