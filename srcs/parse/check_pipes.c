/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:21:07 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/02 14:53:13 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function check_pipe_end revisa si el pipe esta escrito bien
@function check_redirection revisa las redirecciones
@function quotation_marks recorre y revisa si son par o inpar
@function check_special checkea caracteres especiales
@function check_pipes revisa las comillas y si los pipes estan bien y la
cantidad de comandos
*/
//revisa si los pipes estan bien escritas
static t_bool	check_pipe_end(t_shell *shell, char *my_input, int *count)
{
	int	check_pipe;

	*count += 1;
	space_tab(my_input, count);
	check_pipe = *count;
	if (my_input[check_pipe] == '\0')
		return (false);
	space_tab(my_input, count);
	if (my_input[check_pipe] == '|' || my_input[check_pipe] == '<'
		|| my_input[check_pipe] == '>')
		return (false);
	else
		shell->s_i.size_pipe++;
	return (true);
}

//revisa si las comillas estan cerradas
static t_bool	quotation_marks(char *my_input, int *count)
{
	char	skip;

	skip = my_input[*count];
	*count += 1;
	while (my_input[*count] != skip && my_input[*count] != '\0')
		*count += 1;
	if (my_input[*count] == skip)
	{
		*count += 1;
		return (true);
	}
	return (false);
}

//revisa las comillas pipe y redirecciones
static t_bool	check_special(t_shell *shell, char *my_input, int *count)
{
	if (my_input[*count] == '\"' || my_input[*count] == '\'')
	{
		if (!(quotation_marks(my_input, count)))
			return (print_err("Minishell syntax error near unexpected token"));
		space_tab(my_input, count);
	}
	if (my_input[*count] == '>' || my_input[*count] == '<')
	{
		if (!check_redirection(shell, my_input, count))
			return (false);
		space_tab(my_input, count);
	}
	if (my_input[*count] == '|')
	{
		if (!check_pipe_end(shell, my_input, count))
			return (print_err("Minishell syntax error near unexpected token"));
		space_tab(my_input, count);
	}
	return (true);
}

//revisa si la entrada esta bien escrita
t_bool	check_pipes(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	shell->s_i.size_pipe = 1;
	space_tab(my_input, &count);
	if (my_input[count] == '|')
		return (print_err("Minishell syntax error near unexpected token `|'"));
	while (my_input[count] != '\0')
	{
		space_tab(my_input, &count);
		if (!check_special(shell, my_input, &count))
			return (false);
		if (my_input[count] != '|' && my_input[count] != '\"'
			&& my_input[count] != '\'' && my_input[count] != '>'
			&& my_input[count] != '<')
			count++;
	}
	return (true);
}
