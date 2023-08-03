/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_s_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:53:31 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/03 14:54:11 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_s_i(t_shell *shell)
{
	shell->s_i.size_in = 0;
	shell->s_i.size_out = 0;
	shell->s_i.size_token = 0;
	shell->s_i.copy = 0;
	shell->s_i.ctoken = 0;
	shell->s_i.size_pipe = 0;
	shell->s_i.size_str = 0;
}
