/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:40:40 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/29 19:58:28 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function count_quotation_marks si encuentra comillas recorre el contenido
@function count_command_token recorre el contenido de un argumento normal
@function count_redirects cuenta redirecciones y los recorre
@function count_size cuenta el tamaño de los tokens
@function separation cuenta tamaño de la entrada (los tokens) y crea la lista
con el contenido
*/
int	count_quotation_marks(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	(void) shell;
	while (my_input[count] == my_input[0])
	{
		count++;
		while (my_input[count] != my_input[0])
		{
			if (my_input[count] == '\0')
				break ;
			count++;
		}
		if (my_input[count] == my_input[0])
			count++;
	}
	return (count);
}

static int	count_command_token(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	while (my_input[count] != ' ' && my_input[count] != '\t'
		&& my_input[count] != '\0' && my_input[count] != '|'
		&& my_input[count] != '<' && my_input[count] != '>')
	{
		if (my_input[count] == '\"' || my_input[count] == '\'')
			count += count_quotation_marks(shell, &my_input[count]);
		else
			count++;
	}
	space_tab(my_input, &count);
	shell->size_input.size_token++;
	return (count);
}

int	count_redirects(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	if (my_input[count] == '<')
		shell->size_input.size_in += 1;
	if (my_input[count] == '>')
		shell->size_input.size_out += 1;
	count++;
	if (my_input[count] == '<' || my_input[count] == '>')
		count++;
	space_tab(my_input, &count);
	while (my_input[count] != ' ' && my_input[count] != '\t'
		&& my_input[count] != '\0' && my_input[count] != '|'
		&& my_input[count] != '<' && my_input[count] != '>')
		count++;
	space_tab(my_input, &count);
	return (count);
}

static void	count_size(t_shell *shell, char *my_input, int *count)
{
	int	flag;

	flag = 0;
	space_tab(my_input, count);
	if (my_input[*count] == '$')
	{
		while (my_input[*count] == '$')
		{
			if (!ft_isalnum(my_input[*count + 1]) && my_input[*count + 1] != '?')
			{
				shell->size_input.size_token++;
				*count += 2;
			}
			else
				*count += manage_count_env(shell, &my_input[*count], &flag);
		}
		if(flag)
			shell->size_input.size_token++;
	}
	if (my_input[*count] == '<' || my_input[*count] == '>')
		*count += count_redirects(shell, &my_input[*count]);
	if (my_input[*count] != '\0' && my_input[*count] != '|'
		&& my_input[*count] != '$' && my_input[*count] != '<'
		&& my_input[*count] != '>')
		*count += count_command_token(shell, &my_input[*count]);
}

void	separation(t_shell *shell, char *my_input)
{
	int		count;
	int		start;
	t_cmd	*new_cmd;

	count = 0;
	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		exit (1);
	start_nodo(new_cmd);
	while (my_input[count] != '\0')
	{
		start = count;
		start_new_nodo(shell);
		while (my_input[count] != '|' && my_input[count] != '\0')
			count_size(shell, my_input, &count);
		if (my_input[count] == '|' || my_input[count] == '\0')
		{
			create_node(shell, new_cmd, &my_input[start]);
			if (my_input[count] == '|')
				count++;
		}
	}
}
