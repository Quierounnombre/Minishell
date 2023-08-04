/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:45:47 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 16:46:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_aux(t_shell *shell, char *argv, int *count_copy)
{
	int	len;

	len = ft_calclen2(shell->child_status);
	len += *count_copy;
	if (shell->child_status == 0)
	{
		argv[*count_copy] = '0';
		*count_copy += 1;
	}
	else
	{
		*count_copy = len;
		while (shell->child_status > 0)
		{
			argv[--len] = (shell->child_status % 10) + '0';
			shell->child_status = shell->child_status / 10;
		}
	}
}
