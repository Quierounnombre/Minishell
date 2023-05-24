/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:53:41 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/15 17:17:46 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_size(t_shell *shell, char *my_input)
{
	check_size_pipe(shell, my_input);
	check_size_token(shell, my_input);
}
