/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:49:35 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/21 18:31:36 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function argv_with_qm si el argv tiene comillas contara todos los caracteres
que tienen dentro
@function copy_argv copia el comando o el argumento
@function this_is_cmd_argv cuenta el tamaño del comando o del argumento
y los copia
@function copy_cmd_token copia los comandos argumentos redirecciones
*/
/*char	*find_env(t_shell *shell, char *input, int *count)//49
{
	char	*ptr;
	int		ptr_count;
	char	*environment_variabl;

	ptr = NULL;
	ptr_count = 0;
	*count += 1;
	environment_variabl = NULL;
	*count += copy_env(shell, &input[*count], &environment_variabl);//50//malloc_13
	if (environment_variabl)
	{
		ptr = get_ptr(shell, environment_variabl);//51
		if (ptr)
			find_start_of_str(ptr, &ptr_count);//52
	}
	if (ptr)///?????
	{
		free(environment_variabl);
		return (&ptr[ptr_count]);
	}
	if (environment_variabl)
		free(environment_variabl);
	return (NULL);
}*/

char	*find_env(t_shell *shell, char *input, int *count)
{
	char	*ptr;
	int		ptr_count;
	char	*environment_variabl;

	ptr = NULL;
	ptr_count = 0;
	*count += 1;
	environment_variabl = NULL;
	*count += copy_env(shell, &input[*count], &environment_variabl);
	if (environment_variabl)
	{
		ptr = get_ptr(shell, environment_variabl);
		if (ptr)
			find_start_of_str(ptr, &ptr_count);
		if (ptr)
		{
			free(environment_variabl);
			return (&ptr[ptr_count]);
		}
		free(environment_variabl);
	}
	return (NULL);
}

//cuenta la longitud de argv si es una variable y tiene espacios
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

// cuenta la longitud del argumento
static int	count_tam_argv(t_shell *shell, char *input, int *c)
{
	int	size;

	size = 0;
	while (input[*c] != ' ' && input[*c] != '\t' && input[*c] != '>'
		&& input[*c] != '\0' && input[*c] != '|' && input[*c] != '<')
	{
		if (input[*c] == '\"' || input[*c] == '\'')
			*c += argv_with_qm(shell, &input[*c], input[*c], &size);
		if (input[*c] == '$'
			&& !ft_isalnum(input[*c + 1]) && input[*c + 1] != '?')
		{
			size++;
			*c += 1;
		}
		else if (input[*c] == '$')
			*c += manage_count_env_with_space(shell, &input[*c], &size);
		else if (input[*c] != ' ' && input[*c] != '\t' && input[*c] != '\0'
			&& input[*c] != '>' && input[*c] != '|' && input[*c] != '<'
			&& input[*c] != '\"' && input[*c] != '\'' && input[*c] != '$')
		{
			size++;
			*c += 1;
		}
	}
	return (size);
}

//cuenta la longitud y copia cada argumento
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

//llena el nodo copiandolos comandos argumentos y redirecciones
void	copy_cmd_token(t_shell *shell, t_cmd *new_cmd, char *input)
{
	int	count;

	count = 0;
	shell->s_i.ctoken = 0;
	while (input[count] != '|' && input[count] != '\0')
	{
		space_tab(input, &count);
		if (input[count] == '<' || input[count] == '>')
			count += this_is_redirection(shell, new_cmd, &input[count]);
		if (input[count] != '\0' && input[count] != '|'
			&& input[count] != '<' && input[count] != '>')
			count += this_is_argv(shell, new_cmd, &input[count]);	}
	if (new_cmd->argv[0])
		ft_path(shell, new_cmd);
}
