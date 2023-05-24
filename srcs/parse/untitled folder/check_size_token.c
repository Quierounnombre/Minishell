/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:23:22 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/15 19:28:05 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	size_special_token(t_shell *shell, char *my_input, int *count, int *count_redirections);
static void	this_is_size_command_token(t_shell *shell, char *my_input, int *count);
static void	redirects(t_shell *shell, char *my_input, int *count, int *count_redirections);

void	check_size_token(t_shell *shell, char *my_input)
{
	int	count;
	int	start;
	int	count_pipe;
	int	count_redirections;
	t_cmd *cmd;

	cmd = shell->cmds->current->content;
	count = 0;
	count_pipe = 0;
	count_redirections = 0;
	shell->size_input.size_token = 0;
	while (my_input[count] != '\0')
	{
		size_special_token(shell, my_input, &count, &count_redirections);
		if (my_input[count] == '|')
		{
			count++;
			cmd[count_pipe].argv = malloc(sizeof(char *) * (shell->size_input.size_token + 1));
			if (!cmd[count_pipe].argv)
			{
				write (1, "hola\n", 5);
				//ft_error();
			}
			ckeck_token_length(shell, my_input, count, count_pipe);
			count_pipe++;
			shell->size_input.size_token = 0;
		}
		else
			this_is_size_command_token(shell, my_input, &count);
	}
	if (my_input[count] == '\0')
	{
		if (count_redirections == 0)
			cmd->redirections[0] = NO_REDIRECT;
		cmd[count_pipe].argv = malloc(sizeof(char *) * (shell->size_input.size_token + 1));
		if (!cmd[count_pipe].argv)
		{
			write (1, "hola\n", 5);
			//ft_error();
		}
		ckeck_token_length(shell, my_input, count, count_pipe);
	}
}

static void	size_special_token(t_shell *shell, char *my_input, int *count, int *count_redirections)
{
	space_tab(my_input, count);
	if (my_input[*count] == '\"' || my_input[*count] == '\'')
	{
		entrecomillada(my_input, count);
		shell->size_input.size_token++;
	}
	if (my_input[*count] == '<' || my_input[*count] == '>')
		redirects(shell, my_input, count, &count_redirections);
	if (my_input[*count] == '$')
	{
		if (my_input[*count++] == '!')
		{
			write (1, "hola\n", 5);
			//pipe_exit_code();
		}
		if (my_input[*count] != '\0' && my_input[*count] != ' ' &&
			my_input[*count] != '\t')
		{
			write (1, "hola\n", 5);
			//this_is_environment_variabl();
		}
	}
}

static void	this_is_size_command_token(t_shell *shell, char *my_input, int *count)
{
	while(my_input[*count] != ' ' && my_input[*count] != '\t' && my_input[*count] != '\0')
		*count += 1;
	shell->size_input.size_token++;
}

static void	redirects(t_shell *shell, char *my_input, int *count, int *count_redirections)
{
	t_cmd *cmd;

	cmd = shell->cmds->current->content;
	if (my_input[*count] == '<' || my_input[*count + 1] != '<')
		cmd->redirections[*count_redirections] = REDIRECT_INPUT;
	if (my_input[*count] == '>' || my_input[*count + 1] != '>')
		cmd->redirections[*count_redirections] = REDIRECT_OUTPUT;
	if (my_input[*count] == '<' || my_input[*count + 1] == '<')
		cmd->redirections[*count_redirections] = HERE_DOC;
	if (my_input[*count] == '>' || my_input[*count + 1] == '>')
		cmd->redirections[*count_redirections] = MODO_APPEND;
	*count += 1;
	*count_redirections += 1;
	space_tab(my_input, count);
	while (my_input[*count] != ' ' && my_input[*count] != '\t')
	{

		*count++;
	}
}