/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:02 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/13 16:31:10 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Dado un cmd, lo convierte en un nodo y lo añade al final de una lista, en caso
de no existir la lista lo coloca como primer elemento de esta.
@param cmd Estructura con el cmd a guardar en la lista
@param mng Lista con mng donde guardamos el cmd
@return True si todo va bien, False si falla la reserva de memoria
*/
t_bool	ft_storecmd(t_cmd *cmd, t_lstmng *mng)
{
	t_list	*node;

	node = ft_lstnew(cmd);
	if (node)
	{
		if (!(mng->lst_head))
		{
			mng->lst_head = node;
			mng->current = node;
			mng->tail = node;
			mng->size = 1;
			return (true);
		}
		mng->tail->next = node;
		mng->tail = mng->tail->next;
		mng->size++;
		return (true);
	}
	return (false);
}
