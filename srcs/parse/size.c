/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:53:41 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/13 21:24:31 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_size(t_main main_struct, char *my_input)
{
	check_size_pipe(main_struct, my_input);
	check_size_token(main_struct, my_input);
}
