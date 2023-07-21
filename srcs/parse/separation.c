/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:40:40 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/21 18:34:48 by lyandriy         ###   ########.fr       */
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
//cuenta los argumentos de cada comando
static int	count_command_token(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	while (my_input[count] != '\0' && !ft_strchr("| \t><", my_input[count]))
	{
		if (my_input[count] == '\"' || my_input[count] == '\'')
			count += count_quotation_marks(shell, &my_input[count]);
		if (my_input[count] == '$')
			count_dollar(shell, my_input, &count);
		if (my_input[count] != '\0' && !ft_strchr("| \t><", my_input[count]))
			count++;
	}
	space_tab(my_input, &count);
	shell->s_i.size_token++;
	return (count);
}

//cuenta la cantidad de reedirecciones que hay en cada comando
int	count_redirects(t_shell *shell, char *my_input)
{
	int	count;

	count = 0;
	if (my_input[count] == '<')
		shell->s_i.size_in += 1;
	if (my_input[count] == '>')
		shell->s_i.size_out += 1;
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

void	is_exit_code(t_shell *shell, int *count, char *input)
{
	*count += 1;
	if (*count == 1 && (input[*count + 1] == '\t'
			|| input[*count + 1] == '|' || input[*count + 1] == ' '
			|| input[*count + 1] == '<' || input[*count + 1] == '>'))
	{
		shell->s_i.size_token++;
		*count += 1;
	}
	else if ((input[*count - 2] == '|' || input[*count - 2] == ' '
			|| input[*count - 2] == '<' || input[*count - 2] == '>'
			|| input[*count - 2] == '\t') && (input[*count + 1] == '\t'
			|| input[*count + 1] == '|' || input[*count + 1] == ' '
			|| input[*count + 1] == '<' || input[*count + 1] == '>'))
	{
		shell->s_i.size_token++;
		*count += 1;
	}
	else
		*count += 1;
}


//cuenta la cantidad de argumentos de cada comando y las redirecciones
static void	count_size(t_shell *shell, char *input, int *count)
{
	int	flag;

	flag = 0;
	space_tab(input, count);
	if (input[*count] == '<' || input[*count] == '>')
		*count += count_redirects(shell, &input[*count]);
	if (input[*count] != '\0' && input[*count] != '|'
		&& input[*count] != '<' && input[*count] != '>')
		*count += count_command_token(shell, &input[*count]);
}

//separa el input en comandos, argumentos y redirecciones
void	separation(t_shell *shell, char *my_input)
{
	int		count;
	int		start;
	t_cmd	*new_cmd;

	count = 0;
	start_new_nodo(shell);
	while (my_input[count] != '\0')
	{
		start = count;
		while (my_input[count] != '|' && my_input[count] != '\0')
			count_size(shell, my_input, &count);
		if (my_input[count] == '|' || my_input[count] == '\0')
		{
			new_cmd = NULL;
			create_node(shell, new_cmd, &my_input[start]);
			if (my_input[count] == '|')
				count++;
			start_new_nodo(shell);
		}
	}
}
