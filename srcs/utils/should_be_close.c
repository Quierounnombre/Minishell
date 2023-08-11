/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_be_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:22:15 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 11:26:27 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	should_be_close(int fd)
{
	if (fd == STDIN_FILENO)
		return (false);
	if (fd == STDOUT_FILENO)
		return (false);
	if (fd == STDERR_FILENO)
		return (false);
	return (true);
}
