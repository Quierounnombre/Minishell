/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_34_or_39.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:41:47 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/03 11:43:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_bool	is_34_or_39(int c)
{
	if (c == '\"' || c == '\'')
		return (true);
	return (false);
}
