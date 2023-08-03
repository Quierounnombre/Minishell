/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:17:07 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/03 12:17:26 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	copy_env(t_shell *shell, char *input, char **environment_variabl)
{
	int	count;

	count = 0;
	(void) shell;
	while (ft_isalnum(input[count]) && input[count] != '\0')
		count += 1;
	if (count != 0)
	{
		*environment_variabl = malloc(sizeof(char) * (count + 1));
		if (!*environment_variabl)
			exit (1);
		count = 0;
		while (ft_isalnum(input[count]))
		{
			environment_variabl[0][count] = input[count];
			count++;
		}
		environment_variabl[0][count] = '\0';
	}
	return (count);
}
