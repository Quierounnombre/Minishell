/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calclen2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:44:03 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 16:44:21 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_calclen2(int temp)
{
	int	len;

	len = 0;
	if (temp == 0)
		return (1);
	while (temp)
	{
		temp /= 10;
		len++;
	}
	return (len);
}
