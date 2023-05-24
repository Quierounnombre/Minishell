/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_token_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:47:04 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/24 19:13:59 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
copy_cmd_token gestiona los comandos y los argumentos
this_is_redirection gestiona redirecciones
copy_token copia los comandos y argumentos
*/
static int	this_is_redirection(char *my_input, int *count)
{
	*count += 1;
	space_tab(my_input, count);
	while(my_input[*count] != ' ' && my_input[*count] != '\t' &&
		my_input[*count] != '\0')
		*count += 1;
	space_tab(my_input, count);
	return (1);
}

static void	copy_token(char *my_input, char *content)
{
	int	lenght_token;
	int count;

	lenght_token = 0;
	count = 0;
	while (my_input[count] != ' ' && my_input[count] != '\t' &&
		my_input[count] != '|' && my_input[count] != '\0')
	{
		content[lenght_token] = my_input[count];
		count++;
		lenght_token++;
	}
	content[lenght_token] = '\0';
}

void	this_is_cmd_argv(t_cmd *new_cmd, char *my_input, int *count, int *count_token)
{
	int	lenght_token;

	lenght_token = 0;
	while (my_input[*count] != ' ' || my_input[*count] != '\t' ||
			my_input[*count] != '|' || my_input[*count] != '\0')
	{
		*count += 1;
		lenght_token++;
	}
	new_cmd->argv[*count_token] = malloc(sizeof(char) * (lenght_token + 1));
	copy_token(&my_input[*count - lenght_token], new_cmd->argv[*count_token]);
	*count_token++;
	space_tab(my_input, count);
}

void	copy_cmd_token(char *my_input, int count, t_cmd *new_cmd)
{
	int	count_token;
	int	lenght_token;

	count_token = 0;
	lenght_token = 0;
	while (count > 0 && my_input[count - 1] != '|')
		count--;
	space_tab(my_input, &count);
	while (my_input[count] != '|' && my_input[count] != '\0')
	{
		if (my_input[count] == '$')
			this_is_dollar(my_input, &count, new_cmd, &count_token);
		if (my_input[count] == '<' || my_input[count] == '>')
			this_is_redirection(my_input, &count);
		if (my_input[count] == '\"' || my_input[count] == '\'')
			this_is_quotation_marks(my_input, &count, new_cmd, &count_token);
		else
			this_is_cmd_argv(new_cmd, my_input, &count, &count_token);
	}
}
