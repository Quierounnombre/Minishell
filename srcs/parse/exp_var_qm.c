/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_var_qm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:28:46 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/11 12:36:16 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exp_var_qm(t_shell *shell, char *my_input, char *argv, int *count_copy)
{
	char	*environment_variabl;
	char	*ptr;
	int		count;

	count = 1;
	ptr = NULL;
	environment_variabl = NULL;
	if (my_input[count] == '?')
	{
		ft_aux(shell, argv, count_copy);
		return (count + 1);
	}
	count += copy_env(shell, &my_input[count], &environment_variabl);
	if (environment_variabl)
	{
		ptr = get_ptr(shell, environment_variabl);
		if (ptr)
			expand_env_qm(ptr, argv, count_copy);
		free (environment_variabl);
	}
	return (count);
}
