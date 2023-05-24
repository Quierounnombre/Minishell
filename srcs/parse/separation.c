/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:45:19 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/22 17:18:47 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
separation separa los comandos con argumentos creando una lista enlazada
special_token reccorre los token especiales ("", '', $, <)
redirects indica el tipo de redireccion y copia el nombre
copy_redirection copy el nombre de la redireccion
this_is_size_command_token cuenta la cantidad de comandos y argumentos
*/
static void	this_is_size_command_token(t_shell *shell, char *my_input, int *count)
{
	space_tab(my_input, count);
	while(my_input[*count] != ' ' && my_input[*count] != '\t' && my_input[*count] != '\0')
	{
		if (my_input[*count] == '<' || my_input[*count] == '>')
			return ;
		*count += 1;
	}
	shell->size_input.size_token++;
}

static int	copy_redirection(char *my_input, t_cmd *new_cmd, int *count_redirections, int *tam_red_str)
{
	int	count;

	count = 0;
	while (my_input[count] != ' ' && my_input[count] != '\t' && my_input[count] != '\0')
	{
		*tam_red_str += 1;
		count++;
	}
	new_cmd->type[*count_redirections] = malloc(sizeof(char) * (*tam_red_str + 1));
	if (!new_cmd->type)
	{
		write (1, "hola\n", 5);
		//ft_error();
	}
	new_cmd->type[*count_redirections][*tam_red_str] = '\0';
	count -= *tam_red_str;
	*tam_red_str = 0;
	while (my_input[count] != ' ' && my_input[count] != '\t' && my_input[count] != '\0')
	{
		new_cmd->type[*count_redirections][*tam_red_str] = my_input[count];
		count++;
		tam_red_str++;
	}
	return (count);
}

static int	redirects(char *my_input, t_cmd *new_cmd, int *count_redirections)
{
	int	count;
	int	tam_red_str;

	count = 0;
	tam_red_str = 0;
	if (my_input[count] == '<' && my_input[count + 1] != '<')
		new_cmd->redirections[*count_redirections] = REDIRECT_INPUT;
	if (my_input[count] == '>' && my_input[count + 1] != '>')
		new_cmd->redirections[*count_redirections] = REDIRECT_OUTPUT;
	if (my_input[count] == '<' && my_input[count + 1] == '<')
		new_cmd->redirections[*count_redirections] = HERE_DOC;
	if (my_input[count] == '>' && my_input[count + 1] == '>')
		new_cmd->redirections[*count_redirections] = MODO_APPEND;
	count++;
	space_tab(my_input, &count);
	count += copy_redirection(&my_input[count], new_cmd, count_redirections, &tam_red_str);
	*count_redirections += 1;
	return (count);
}

static int	special_token(t_shell *shell, char *my_input, t_cmd *new_cmd, int *count_redirections)
{
	int	count;

	count = 0;
	space_tab(my_input, &count);
	if (my_input[count] == '\"' || my_input[count] == '\'')
	{
		quotation_marks(my_input, &count);
		shell->size_input.size_token++;
	}
	if (my_input[count] == '<' || my_input[count] == '>')
		count += redirects(&my_input[count], new_cmd, count_redirections);
	if (my_input[count] == '$')
	{
		if (my_input[count + 1] == '?')
		{
			write (1, "hola\n", 5);
			//pipe_exit_code();
		}
		if (my_input[count + 1] != '\0' && my_input[count + 1] != ' ' &&
			my_input[count + 1] != '\t' && (my_input[count - 1] == '\t' ||
			my_input[count - 1] != '\0') && count != 0)
		{
			shell->size_input.size_token++;
			//this_is_environment_variabl(shell, my_input, &count);
		}
	}
	return (count);
}

int	separation(t_shell *shell, char *my_input, char **env)
{
	int		count;
	int		count_redirections;
	t_cmd	*new_cmd;

	count = 0;
	count_redirections = 0;
	new_cmd = NULL;
	shell->cmds->current = NULL;
	if (start_nodo(new_cmd))
	{
		while (my_input[count] != '\0')
		{
			space_tab(my_input, &count);
			count += special_token(shell, &my_input[count], new_cmd, &count_redirections);
			if (my_input[count] != '|' && my_input[count] != '\0')
				this_is_size_command_token(shell, my_input, &count);
			if (my_input[count] == '|' || my_input[count] == '\0')
			{
				create_node(shell, my_input, &count, new_cmd);
				if (my_input[count] == '|')
					count++;
			}
		}
	}
	return(0);
}
