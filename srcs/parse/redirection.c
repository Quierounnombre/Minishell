/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:35:26 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/19 19:02:19 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function count_size_red cuenta el tamaño del nombre de archivo de redireccion
@function copy_red copia el nombre del archivo de redireccion
@function lstnew_red crea el nodo y lo rellena de informacion
@function lstadd_back_nodo crea la lista de redirecciones
@function ft_input_output indica que tipo de redireccion es
@function this_is_redirection gestiona las redirecciones y las copia
*/
static int	count_size_red(char *my_input)
{
	int	count;
	int	count_size;

	count = 0;
	count_size = 0;
	while (my_input[count] != ' ' && my_input[count] != '\t' &&
		/*my_input[count] != '$' && */my_input[count] != '\0' &&
		my_input[count] != '|' && my_input[count] != '<' &&
		my_input[count] != '>')
	{
		count_size++;
		count++;
	}
	return (count_size);
}

static void copy_red(char *my_input, char *file)
{
	int	count;

	count = 0;
	while (my_input[count] != ' ' && my_input[count] != '\t' &&
		my_input[count] != '\0' && my_input[count] != '|' &&
		my_input[count] != '<' && my_input[count] != '>')
	{
		file[count] = my_input[count];
		count++;
	}
	file[count] = '\0';
}

static t_red	*lstnew_red(t_cmd *new_cmd, char *input, int *coun_red, int red)
{
	t_red	*lst;
	int		count;

	count = 1;
	(void) new_cmd;
	lst = malloc(sizeof(*lst));
	if (!lst)
		exit (1);
	lst->tipe = red;
	lst->next = NULL;
	if (input[count] == '<' || input[count] == '>')
		count++;
	space_tab(input, &count);
	lst->file = malloc(sizeof(char) * (count_size_red(&input[count]) + 1));
	if (!lst->file)
		exit (1);
	copy_red(&input[count], lst->file);
	printf("%s\n", lst->file);
	*coun_red += 1;
	//abrir fd;
	return (lst);
}

static void	lstadd_back_nodo(t_red **lst, t_red *new)
{
	t_red	*tmp;

	if (!lst)
		return ;
	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

static void	ft_input_output(t_shell *shell, t_cmd *new_cmd, char *input)
{
	t_red	*tmp;

	if (input[0] == '<' && input[1] != '<')
	{
		tmp = lstnew_red(new_cmd, input, &shell->size_input.size_in, RED_INPUT);
		lstadd_back_nodo(&new_cmd->redir_in, tmp);
	}
	if (input[0] == '<' && input[1] == '<')
	{
		tmp = lstnew_red(new_cmd, input, &shell->size_input.size_in, HERE_DOC);
		lstadd_back_nodo(&new_cmd->redir_in, tmp);
	}
		if (input[0] == '>' && input[1] != '>')
	{
		tmp = lstnew_red(new_cmd, input, &shell->size_input.size_out, RED_OUT);
		lstadd_back_nodo(&new_cmd->redir_out, tmp);
	}
	if (input[0] == '>' && input[1] == '>')
	{
		tmp = lstnew_red(new_cmd, input, &shell->size_input.size_out, APPEND);
		lstadd_back_nodo(&new_cmd->redir_out, tmp);
	}
}

int	this_is_redirection(t_shell *shell, t_cmd *new_cmd, char *my_input)
{
	int	count;

	count = 1;
	ft_input_output(shell, new_cmd, my_input);
	if (my_input[count] == my_input[count - 1])
		count++;
	space_tab(my_input, &count);
	while (my_input[count] != ' ' && my_input[count] != '\t' &&
		my_input[count] != '\0' && my_input[count] != '|' &&
		my_input[count] != '<' && my_input[count] != '>')
		count++;
	space_tab(my_input, &count);
	return (count);
}
