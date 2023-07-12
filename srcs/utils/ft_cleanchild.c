/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanchild.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:02:23 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/29 11:48:36 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	libera la memoria reservada por un hijo
	@param node el nodo de la lista con el hijo
*/
void	ft_cleanchild(void *node)
{
	t_list	*lst;

	lst = node;
	free(lst->content);
	free(lst);
}
