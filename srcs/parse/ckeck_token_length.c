/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_token_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:47:04 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/22 20:22:40 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
copy_cmd_token gestiona los comandos y los argumentos
this_is_dollar gestiona $
this_is_redirection gestiona redirecciones
this_is_quotation_marks gestiona comillas
copy_token copia los comandos y argumentos
*/
static int	this_is_redirection(char *my_input, int *count)
{
	*count += 1;
	space_tab(my_input, count);
	while(my_input[*count] != ' ' && my_input[*count] != '\t' && my_input[*count] != '\0')
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

static int	this_is_quotation_marks(char *my_input, int *count, char *content)
{
	*count += 1;
	if (my_input[*count - 1] == '\'')
		copy_simple_quotation_marks(my_input, count, content);
	if (my_input[*count - 1] == '\"')
		copy_doble_quotation_marks(my_input, count, content);
	*count += 1;
	return (1);
}

static int	this_is_dollar(char *my_input, int *count, t_cmd *new_cmd, int count_token)
{
	(void)new_cmd, (void)count_token;
		if (my_input[*count + 1] == '?')
		{
			write (1, "hola\n", 5);
			//pipe_exit_code();
		}
		if (my_input[*count + 1] != '\0' && my_input[*count + 1] != ' ' &&
			my_input[*count + 1] != '\t' && (my_input[*count - 1] == '\t' ||
			my_input[*count - 1] != '\0') && *count != 0)
		{
			//variabl_function(my_input, count, new_cmd, count_token);
		//	this_is_environment_variabl();
		}
	return (1);
}

void	copy_cmd_token(char *my_input, int count, t_cmd *new_cmd)
{
	int	count_token;
	int	lenght_token;
	int	flag;

	count_token = 0;
	lenght_token = 0;
	while (count > 0 && my_input[count - 1] != '|')
		count--;
	space_tab(my_input, &count);
	while (my_input[count] != '|' && my_input[count] != '\0')
	{
		flag = 0;
		if (my_input[count] == '$')
		{
			flag = this_is_dollar(my_input, &count, new_cmd, count_token);
			count_token++;
			lenght_token = 0;
		}
		if (my_input[count] == '<' || my_input[count] == '>')
			flag = this_is_redirection(my_input, &count);
		if (my_input[count] == '\"' || my_input[count] == '\'')
		{
			flag = this_is_quotation_marks(my_input, &count, new_cmd->argv[count_token]);
			count_token++;
			lenght_token = 0;
		}
		if ((my_input[count] == ' ' || my_input[count] == '\t' ||
			my_input[count] == '|' || my_input[count] == '\0') && flag == 0)
		{
			new_cmd->argv[count_token] = malloc(sizeof(char) * (lenght_token + 1));
			copy_token(&my_input[count - lenght_token], new_cmd->argv[count_token]);
			count_token++;
			lenght_token = 0;
		}
		if (my_input[count] != ' ' && my_input[count] != '\t')
			lenght_token++;
		count++;
	}
}
