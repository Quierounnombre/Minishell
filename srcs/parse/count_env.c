/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:27:07 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/29 19:47:48 by lyandriy         ###   ########.fr       */
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
static void	count_env(t_shell *shell, char *ptr)
{
	int	count;

	count = 0;
	while (ptr[count] != '\0')
	{
		if (ptr[count] == ' ' || ptr[count] == '\t')
		{
			space_tab(ptr, &count);
			shell->size_input.size_token++;
		}
		count++;
	}
}

static void	check_env(t_shell *shell, char *environment_variabl)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = get_ptr(shell, environment_variabl);
	if (ptr)
		count_env(shell, &ptr[ft_strlen(environment_variabl)]);
}

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

int	manage_count_env(t_shell *shell, char *my_input, int *flag)
{
	int		count;
	char	*environment_variabl;

	count = 1;
	*flag = 0;
	environment_variabl = NULL;
	if (my_input[count] == '?')
		shell->size_input.size_token++;
	else
	{
		count += copy_env(shell, &my_input[count], &environment_variabl);
		if (environment_variabl)
		{
			*flag = 1;
			check_env(shell, environment_variabl);
			free(environment_variabl);
		}
	}
	space_tab(my_input, &count);
	return (count);
}
