/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:55:04 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/21 18:34:56 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function recorre espacios y tabulaciones
@function start_new_nodo crea nuevo t_lstmng y reinicializa los contadores
@function start_nodo inicializa el nuevo nodo t_lstmng
@function lstadd_back_nodo crea la lista de redirecciones
*/
void	space_tab(char *my_input, int *count)
{
	while (my_input[*count] == ' ' || my_input[*count] == '\t')
		*count += 1;
}

void	find_start_of_str(char *ptr, int *ptr_count)
{
	while (ptr[*ptr_count] != '=')
		*ptr_count += 1;
	if (ptr[*ptr_count] == '=')
		*ptr_count += 1;
}

//crea lista enlazada para las redirecciones
void	lstadd_back_nodo(t_red **lst, t_red *new)
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
