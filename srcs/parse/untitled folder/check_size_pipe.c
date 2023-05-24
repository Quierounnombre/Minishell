/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:21:07 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/15 19:29:51 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_pipe(t_shell *shell, char *my_input, int *count);

void	check_size_pipe(t_shell *shell, char *my_input)
{
	int		count;
	t_cmd *cmd;

	cmd = shell->cmds->current->content;
	count = 0;
	shell->size_input.size_pipe = 1;
	shell->size_input.size_redir =  0;
	while (my_input[count] != '\0')
	{
		if (my_input[count] == '\"' || my_input[count] == '\'')
			entrecomillada(my_input, &count);
		if (my_input[count] == '>' || my_input[count] == '<')
		{
			if (my_input[count + 1] == '<' || my_input[count + 1] == '>')
				count++;
			shell->size_input.size_redir++;
		}
		if (my_input[count] == '|')
			check_pipe(shell, my_input, &count);
		count++;
	}
	if (shell->size_input.size_redir)
		cmd->redirections = malloc(sizeof(int) * shell->size_input.size_redir);
	cmd = malloc(sizeof(t_cmd) * (shell->size_input.size_pipe + 1));
	if (!shell->cmds)
	{
		write (1, "hola\n", 5);
		//ft_error();
	}
	cmd->redirections = NO_REDIRECT;
}

void	entrecomillada(char *my_input, int *count)
{
	if (my_input[*count] == '\'')
	{
		*count += 1;
		while (my_input[*count] != '\'' || my_input[*count])
			*count += 1;
		if (!my_input[*count])
		{
			write (1, "hola\n", 5);
			//ft_error();
		}
	}
	if (my_input[*count] == '\"')
	{
		*count += 1;
		while (my_input[*count] != '\"' || my_input[*count])
			*count += 1;
		if (!my_input[*count])
		{
			write (1, "hola\n", 5);
			//ft_error();
		}
	}
}

static void	check_pipe(t_shell *shell, char *my_input, int *count)
{
	int		check_pipe;

	*count += 1;
	space_tab(my_input, count);
	check_pipe = *count;
	if (my_input[check_pipe] == '\0')
	{
		write (1, "hola\n", 5);
		//ft_error();
	}
	if (my_input[check_pipe] == '|')
	{
		write (1, "hola\n", 5);
		//syntax_error_near_unexpected_token();
	}
	shell->size_input.size_pipe++;
}
