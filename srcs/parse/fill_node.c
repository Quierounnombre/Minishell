/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:49:35 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/21 15:51:41 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function argv_with_qm si el argv tiene comillas contara todos los caracteres que tienen dentro
@function copy_argv copia el comando o el argumento
@function this_is_cmd_argv cuenta el tamaño del comando o del argumento y los copia
@function copy_cmd_token copia los comandos argumentos redirecciones
*/
static int	copy_qm(t_shell *shell, char *argv, char *my_input, int *count_copy)
{
	char	skip;
	int		count;

	count = 0;
	skip = my_input[count];
	count++;
	while (my_input[count] != skip)
	{
		if (my_input[count] == '$' && my_input[0] == '\"')
			count += exp_var_qm(shell, &my_input[count], argv, count_copy);
		else
		{
			argv[*count_copy] = my_input[count];
			count++;
			*count_copy += 1;
		}
	}
	if (my_input[count] == skip)
		count++;
	return (count);
}

static void	copy_argv(t_shell *shell, t_cmd *new_cmd, char *input, int *i)//i count_copy
{
	int		count;
	int		copy;//count_copy

	count = 0;
	copy = 0;
	while (input[count] != ' ' && input[count] != '\t' &&
		input[count] != '\0' && input[count] != '|' &&
		input[count] != '<' && input[count] != '>')
	{
		if (input[count] == '\"' || input[count] == '\'')
			count += copy_qm(shell, new_cmd->argv[*i], &input[count], &copy);

		if (input[count] == '$')
			count += exp_var_qm(shell, &input[count], new_cmd->argv[*i], &copy);
		if (input[count] != ' ' && input[count] != '\t' &&
			input[count] != '\0' && input[count] != '>' &&
			input[count] != '|' && input[count] != '<' &&
			input[count] != '\"' && input[count] != '\'')
		{
			new_cmd->argv[*i][copy] = input[count];
			count++;
			copy++;
		}
	}
	new_cmd->argv[*i][copy] = '\0';
}

static int	argv_with_qm(t_shell *shell, char *my_input, char skip, int *size)
{
	int	count;

	count = 1;
	while (my_input[count] != skip)
	{
		if (my_input[count] == '$' && my_input[0] == '\"')
			count += manage_count_env_qw(shell, &my_input[count], size);
		else
		{
			*size += 1;
			count++;
		}
	}
	if (my_input[count] == skip)
		count++;
	return (count);
}

static int	count_tam_argv(t_shell *shell, char *input, int *count)
{
	int	size;

	size = 0;
	while (input[*count] != ' ' && input[*count] != '\t' &&
		input[*count] != '>' && input[*count] != '\0' &&
		input[*count] != '|' && input[*count] != '<')
	{
		if (input[*count] == '\"' || input[*count] == '\'')
			*count += argv_with_qm(shell, &input[*count], input[*count], &size);
		if (input[*count] == '$')
			*count += manage_count_env_qw(shell, &input[*count], &size);
		if (input[*count] != ' ' && input[*count] != '\t' &&
			input[*count] != '\0' && input[*count] != '>' &&
			input[*count] != '|' && input[*count] != '<' &&
			input[*count] != '\"' && input[*count] != '\'')
		{
			size++;
			*count += 1;
		}
	}
	//space_tab(my_input, count);
	return (size);
}

static int	this_is_argv(t_shell *shell, t_cmd *new_cmd, char *my_input, int *i)//i count_token
{
	int	count;
	int	size;

	size = 0;
	count = 0;
	(void) shell;
	size = count_tam_argv(shell, my_input, &count);
	new_cmd->argv[*i] = malloc(sizeof(char) * (size + 1));
	if (!new_cmd->argv[*i])
		exit (1);
	copy_argv(shell, new_cmd, my_input, i);
	*i += 1;
	space_tab(my_input, &count);
	return (count);
}

void	ft_path(t_shell *shell, t_cmd *new_cmd)
{
	int		count;
	char	*ptr;
	char	**separate_path;
	char	*path_with_command;

	//ptr = NULL;
	count = 0;
	new_cmd->filepath = NULL;
	ptr = get_ptr(shell, "PATH");
	separate_path = ft_split(ptr, ':');
	path_with_command = ft_strdup(new_cmd->argv[0]);
	while (access(path_with_command, F_OK) == -1 && separate_path[count])
	{
		path_with_command = ft_strjoin(separate_path[count], "/");
		path_with_command = ft_strjoin(path_with_command, new_cmd->argv[0]);
		count++;
	}
	if (access(path_with_command, F_OK) == 0)
	{
		free(new_cmd->argv[0]);
		new_cmd->argv[0] = ft_strdup(path_with_command);
		new_cmd->filepath = ft_strdup(path_with_command);
	}
	free(path_with_command);
}

void	copy_cmd_token(t_shell *shell, t_cmd *new_cmd, char *input)
{
	int	count;
	int	count_token;

	count = 0;
	count_token = 0;
	while (input[count] != '|' && input[count] != '\0')
	{
		space_tab(input, &count);
		if (input[count] == '$')
			count += this_is_env(shell, new_cmd, &input[count], &count_token);
		if (input[count] == '<' || input[count] == '>')
			count += this_is_redirection(shell, new_cmd, &input[count]);
		if (input[count] != '\0' && input[count] != '|' &&
			input[count] != '$' && input[count] != '<' &&
			input[count] != '>')
			count += this_is_argv(shell, new_cmd, &input[count], &count_token);
	}
	ft_path(shell, new_cmd);
}
