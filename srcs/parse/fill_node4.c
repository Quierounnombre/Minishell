/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:44:36 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/16 18:40:55 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_variable(t_shell *shell, t_cmd *new_cmd, char *input, int *c)
{
	if (!ft_isalnum(input[*c + 1]) && input[*c + 1] != '?')
	{
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = input[*c];
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy + 1]
			= input[*c + 1];
		shell->s_i.copy += 2;
		*c += 2;
	}
	if (input[*c + 1] == '?')
	{
		if (new_cmd->argv[shell->s_i.ctoken])
			new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
		*c += this_is_env(shell, new_cmd, &input[*c], &shell->s_i.ctoken);
		shell->s_i.copy = ft_strlen(new_cmd->argv[shell->s_i.ctoken]);
	}
	else
		else_variable(shell, new_cmd, input, c);
}

void	copy_argv(t_shell *shell, t_cmd *new_cmd, char *input)
{
	int	c;
	int	*i;

	c = 0;
	i = &shell->s_i.ctoken;
	shell->s_i.copy = 0;
	while (input[c] != ' ' && input[c] != '\t' && input[c] != '\0'
		&& input[c] != '|' && input[c] != '<' && input[c] != '>')
	{
		if (input[c] == '\"' || input[c] == '\'')
			c += copy_qm(shell, new_cmd->argv[*i], &input[c], &shell->s_i.copy);
		if (input[c] == '$')
			copy_variable(shell, new_cmd, input, &c);
		else if (input[c] != ' ' && input[c] != '\t' && input[c] != '\0'
			&& input[c] != '>' && input[c] != '|' && input[c] != '<'
			&& input[c] != '\"' && input[c] != '\'' && input[c] != '$')
		{
			new_cmd->argv[*i][shell->s_i.copy] = input[c];
			c++;
			shell->s_i.copy++;
		}
	}
	check_argv(shell, new_cmd);
}

int	check_spaces(t_cmd *new_cmd, char **argv_env, int *count_env, int *i)
{
	int	copy;

	copy = 0;
	if (argv_env[*count_env])
		*i += 1;
	while (argv_env[*count_env])
	{
		new_cmd->argv[*i] = argv_env[*count_env];
		*count_env += 1;
		//printf("%d\n", argv_env[*count_env]);
		if (argv_env[*count_env])
		{
			copy = ft_strlen(new_cmd->argv[*i]);
			*i += 1;
		}
	}
	return (copy);
}

void	expand_env(char *ptr, t_cmd *new_cmd, int *i, int *copy)
{
	char	**argv_env;
	int		count_env;

	count_env = 0;
	argv_env = ft_split(ptr, ' ');
	if (new_cmd->argv[*i])
	{
		new_cmd->argv[*i][*copy] = '\0';
		ptr = new_cmd->argv[*i];
		if (ptr)
		{
			new_cmd->argv[*i] = ft_strjoin(ptr, argv_env[count_env]);
			*copy += ft_strlen(argv_env[count_env]);
			free(ptr);
		}
	}
	else
	{
		new_cmd->argv[*i] = argv_env[count_env];
		*copy += ft_strlen(argv_env[count_env]);
	}
	count_env++;
	*copy += check_spaces(new_cmd, argv_env, &count_env, i);
	*copy = ft_strlen(new_cmd->argv[*i]);
}

void	ptr_exists(char *ptr, int *size)
{
	int	count_ptr;

	count_ptr = 0;
	while (ptr[count_ptr] != '=')
		count_ptr++;
	if (ptr[count_ptr] == '=')
		count_ptr++;
	while (ptr[count_ptr] != '\0')
	{
		if (ptr[count_ptr] == ' ' || ptr[count_ptr] == '\t')
			break ;
		count_ptr++;
		*size += 1;
	}	
}
