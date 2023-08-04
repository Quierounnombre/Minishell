/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:33:29 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/04 15:53:41 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	copy_str(t_shell *shell, t_cmd *new_cmd, char *input, int *c)
{
	char	*ptr;
	char	*tex_argv;

	ptr = NULL;
	if (new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] != '\0')
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
	ptr = new_cmd->argv[shell->s_i.ctoken];
	tex_argv = copy_tex_argv(input, c);
	new_cmd->argv[shell->s_i.ctoken] = ft_strjoin(ptr, tex_argv);
	shell->s_i.copy = ft_strlen(new_cmd->argv[shell->s_i.ctoken]);
	free(ptr);
	free(tex_argv);
}

static void	copy_var_qm(t_shell *shell, t_cmd *new_cmd, char *input, int *c)
{
	char	*ptr;
	char	*copy_text;

	ptr = NULL;
	copy_text = copy_text_qm(shell, input, c);
	if (new_cmd->argv[shell->s_i.ctoken])
	{
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
		ptr = new_cmd->argv[shell->s_i.ctoken];
		new_cmd->argv[shell->s_i.ctoken] = ft_strjoin(ptr, copy_text);
		free(copy_text);
		free(ptr);
	}
	else
		new_cmd->argv[shell->s_i.ctoken] = copy_text;
	shell->s_i.copy = ft_strlen(new_cmd->argv[shell->s_i.ctoken]);
}

static void	variable_exit_code(t_shell *shell, t_cmd *new_cmd, int *c)
{
	char	*temp;
	char	*ptr;

	ptr = NULL;
	temp = ft_itoa(shell->child_status);
	if (temp && new_cmd->argv[shell->s_i.ctoken])
	{
		if (new_cmd->argv[shell->s_i.ctoken])
			new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
		ptr = new_cmd->argv[shell->s_i.ctoken];
		new_cmd->argv[shell->s_i.ctoken] = ft_strjoin(ptr, temp);
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
		if (ptr)
			expand_env(ptr, new_cmd, &shell->s_i.ctoken, &shell->s_i.copy);
	}
}

// busca la variable en env y la copia y divide en argv
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
