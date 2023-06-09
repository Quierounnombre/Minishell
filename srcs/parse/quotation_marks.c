/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotation_marks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:33:59 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/12 16:20:09 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function copy_quotation_marks compia el contenido de las comillas
@function this_is_quotation_marks revisa que comilla es y compia el contenido
@function copy_qm copia el contenido de las comillas
*/
int	count_quotation(char *my_input, int *size, char skip)
{
	int	count;

	count = 0;
	while (my_input[count] == skip)
	{
		count++;
		while (my_input[count] != skip)
		{
			*size += 1;
			count++;
		}
		count++;
	}
	space_tab(my_input, &count);
	return (count);
}

int	this_is_quotation_marks(t_shell *shell, t_cmd *new_cmd,
char *my_input, int *count_token)
{
	int	size;
	int	count;

	size = 0;
	count = 0;
	(void) shell;
	count = count_quotation(my_input, &size, my_input[count]);
	new_cmd->argv[*count_token] = malloc(sizeof(char) * (size + 1));
	if (!new_cmd->argv[*count_token])
		exit (1);
	count = 0;
	while (my_input[count + 1] != my_input[0])
	{
		new_cmd->argv[*count_token][count + 1] = my_input[count];
		count++;
	}
	new_cmd->argv[*count_token][count] = '\0';
	*count_token += 1;
	space_tab(my_input, &count);
	return (count);
}

void	argv_alnum(char *argv, int *count_copy, int *count)
{
	argv[*count_copy] = '$';
	*count += 2;
	*count_copy += 1;
}

int	copy_qm(t_shell *shell, char *argv, char *my_input, int *count_copy)
{
	char	skip;
	int		count;

	count = 1;
	skip = my_input[0];
	while (my_input[count] != skip && my_input[count] != '\0')
	{
		if (my_input[count] == '$' && my_input[0] == '\"')
		{
			if (!ft_isalnum(my_input[count + 1]) && my_input[count + 1] != '?'
				&& my_input[count] != skip)
				argv_alnum(argv, count_copy, &count);
			else
				count += exp_var_qm(shell, &my_input[count], argv, count_copy);
		}
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
