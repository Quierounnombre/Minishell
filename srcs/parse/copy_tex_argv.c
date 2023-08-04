/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tex_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:11:36 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 16:11:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*copy_tex_argv(char *input, int *c)
{
	int		size;
	char	*str;

	size = 0;
	while (input[*c + size] != ' ' && input[*c + size] != '\t'
		&& input[*c + size] != '$' && input[*c + size] != '\0'
		&& input[*c + size] != '>' && input[*c + size] != '\"'
		&& input[*c + size] != '|' && input[*c + size] != '<'
		&& input[*c + size] != '\'')
		size++;
	str = malloc (sizeof(char) * (size + 1));
	if (!str)
		exit (1);
	size = 0;
	while (input[*c] != ' ' && input[*c] != '\t' && input[*c] != '$'
		&& input[*c] != '\0' && input[*c] != '>' && input[*c] != '\"'
		&& input[*c] != '|' && input[*c] != '<' && input[*c] != '\'')
	{
		str[size] = input[*c];
		size++;
		*c += 1;
	}
	str[size] = '\0';
	return (str);
}
