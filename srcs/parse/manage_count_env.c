/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_count_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:27:07 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/09 10:54:16 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function count_env cuenta la cantidad de token que hay en una variable
@function check_env busca la variable dentro de env
@function pass_evn cuenta la cantidad de caracteres que tiene el nombre
de la variable
@function copy_env copia el nombre de variable de entorno
@function manage_count_env copia y busca la variable y cuenta la
cantidad de token que tiene, al final libera el nombre
*/

//cuenta la cantidad de token que tiene la variable
static void	count_env(t_shell *shell, char *ptr)
{
	int	count;

	count = 0;
	while (ptr[count])
	{
		//why not is_space?
		if (ptr[count] == ' ' || ptr[count] == '\t')
		{
			space_tab(ptr, &count);
			shell->s_i.size_token++;
		}
		count++;
	}
}

//busca la variable en env y cuenta la cantidad de token que tiene la variable
static void	check_env(t_shell *shell, char *environment_variabl)
{
	char	*ptr;

	ptr = get_ptr(shell, environment_variabl);
	if (ptr)
		count_env(shell, &ptr[ft_strlen(environment_variabl)]);
}

//expande la variable y cuenta los tokens que tiene
int	manage_count_env(t_shell *shell, char *my_input, int *flag)
{
	int		count;
	char	*environment_variabl;

	count = 1;
	if (my_input[0] == '$')
	{
		*flag = 0;
		environment_variabl = NULL;
		if (my_input[count] != '?')
		{
			count += copy_env(shell, &my_input[count], &environment_variabl);
			if (environment_variabl)
			{
				*flag = 1;
				check_env(shell, environment_variabl);
				free(environment_variabl);
			}
		}
	}
	return (count);
}
