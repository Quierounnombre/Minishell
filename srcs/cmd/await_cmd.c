/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   await_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:04 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/03 15:00:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*The idea is just a wrapper to await for the user input, eventually it would/
should be improve in order to accept quotes and other user inputs.*/
char	*await_cmd(int fd)
{
	char	*s;

	s = ft_get_next_line(fd);
	return (s);
}
