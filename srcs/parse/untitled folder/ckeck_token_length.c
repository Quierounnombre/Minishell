/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_token_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:47:04 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/15 19:31:09 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ckeck_token_length(t_shell *shell, char *my_input, int count, int count_pipe)
{
	int	count_token;
	int	lenght_token;
	t_cmd *cmd;

	cmd = shell->cmds->current->content;
	count_token = 0;
	lenght_token = 0;
	while (count > 0 && my_input[count] != '|')
		count--;
	if (my_input[count] == '|')
		count++;
	while (my_input[count] != '|')
	{
		space_tab(my_input, &count);
		lenght_token++;
		count++;
		if (my_input[count] == ' ' || my_input[count] == '\t' || my_input[count] == '|' || my_input[count] == '\0')
		{
			cmd[count_pipe].argv[count_token] = malloc(sizeof(char) * (lenght_token + 1));
			count -= lenght_token;
			copy_token(shell, my_input, cmd[count_pipe].argv[count_token], &count);
			lenght_token = 0;
			count_token++;
		}
	}
}

void	copy_token(t_shell *shell, char *my_input, char *content, int *count)
{
	int	lenght_token;

	lenght_token = 0;
	while (my_input[*count] != ' ' && my_input[*count] != '\t' && my_input[*count] != '|' && my_input[*count] != '\0')
	{
		while
		 (my_input[*count] == '\"' || my_input[*count] == '\'')
			*count += 1;
		content[lenght_token] = my_input[*count];
		*count += 1;
		lenght_token++;
	}
	content[lenght_token] = '\0';
}
