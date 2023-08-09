/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_is_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:35:26 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/09 10:51:43 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function count_size_red cuenta el tamaño del nombre de archivo de redireccion
@function copy_red copia el nombre del archivo de redireccion
@function lstnew_red crea el nodo y lo rellena de informacion
@function ft_input_output indica que tipo de redireccion es
@function this_is_redirection gestiona las redirecciones y las copia
*/
//cuenta el tamaño del nombre de la redireccion
static int	count_size_red(t_shell *shell, char *input)//19
{
	int	count;
	int	size;

	count = 0;
	size = 0;
	while (input[count] != ' ' && input[count] != '\t'
		&& input[count] != '\0' && input[count] != '|'
		&& input[count] != '<' && input[count] != '>')
	{
		if (input[count] == '\"' || input[count] == '\'')
			count += argv_with_qm(shell, &input[count], input[count], &size);
		if (input[count] == '$')
			count += manage_count_env_qm(shell, &input[count], &size);
		if (input[count] != ' ' && input[count] != '\t'
			&& input[count] != '\0' && input[count] != '|'
			&& input[count] != '<' && input[count] != '>'
			&& input[count] != '\"' && input[count] != '\''
			&& input[count] != '$')
		{
			size++;
			count++;
		}
	}
	return (size);
}

//copia el nombre de redireccion
static void	copy_red(t_shell *shell, char *my_input, char *file)
{
	int	count;
	int	count_copy;

	count = 0;
	count_copy = 0;
	while (my_input[count] != ' ' && my_input[count] != '\t'
		&& my_input[count] != '\0' && my_input[count] != '|'
		&& my_input[count] != '<' && my_input[count] != '>')
	{
		if (my_input[count] == '\"' || my_input[count] == '\'')
			count += copy_qm(shell, file, &my_input[count], &count_copy);
		if (my_input[count] == '$')
				count += exp_var_qm(shell, &my_input[count], file, &count_copy);
		if (my_input[count] != ' ' && my_input[count] != '\t'
			&& my_input[count] != '\0' && my_input[count] != '|'
			&& my_input[count] != '<' && my_input[count] != '>'
			&& my_input[count] != '\"' && my_input[count] != '\''
			&& my_input[count] != '$')
		{
			file[count_copy] = my_input[count];
			count++;
			count_copy++;
		}
	}
	file[count_copy] = '\0';
}

//copia el nombre de la redireccion
static t_red	*lstnewred(t_shell *shell, t_cmd *new_cmd, char *input, int red)
{
	t_red	*lst;
	int		count;

	count = 1;
	(void) new_cmd;
	lst = malloc(sizeof(t_red));
	if (!lst)
		exit (1);
	lst->tipe = red;
	lst->next = NULL;
	if (input[count] == input[0])
		count++;
	space_tab(input, &count);
	lst->file = malloc(sizeof(char)
			* (count_size_red(shell, &input[count]) + 1));
	if (!lst->file)
		exit (1);
	copy_red(shell, &input[count], lst->file);
	shell->s_i.size_in += 1;
	return (lst);
}

//copia las redirecciones e indica que tipo de redirecion es
static void	ft_input_output(t_shell *shell, t_cmd *new_cmd, char *input)
{
	t_red	*tmp;

	if (input[0] == '<' && input[1] != '<')
	{
		tmp = lstnewred(shell, new_cmd, input, RED_INPUT);
		lstadd_back_nodo(&new_cmd->redir_in, tmp);
	}
	if (input[0] == '<' && input[1] == '<')
	{
		tmp = lstnewred(shell, new_cmd, input, HERE_DOC);
		heredoc(tmp);
		lstadd_back_nodo(&new_cmd->redir_in, tmp);
	}
	if (input[0] == '>' && input[1] != '>')
	{
		tmp = lstnewred(shell, new_cmd, input, RED_OUT);
		lstadd_back_nodo(&new_cmd->redir_out, tmp);
	}
	if (input[0] == '>' && input[1] == '>')
	{
		tmp = lstnewred(shell, new_cmd, input, APPEND);
		lstadd_back_nodo(&new_cmd->redir_out, tmp);
	}
}

//copia las redirecciones e indica que tipo de redirecion es
int	this_is_redirection(t_shell *shell, t_cmd *new_cmd, char *my_input)
{
	int	count;

	count = 1;
	ft_input_output(shell, new_cmd, my_input);
	if (my_input[count] == my_input[count - 1])
		count++;
	space_tab(my_input, &count);
	while (my_input[count] != ' ' && my_input[count] != '\t'
		&& my_input[count] != '\0' && my_input[count] != '|'
		&& my_input[count] != '<' && my_input[count] != '>')
		count++;
	space_tab(my_input, &count);
	return (count);
}
