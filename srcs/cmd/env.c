/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:01:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/14 12:16:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(char	**env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (should_be_env(env[i]))
			ft_printf("%s\n", env[i]);
		i++;
	}
}
