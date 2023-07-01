/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_qm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:16:12 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/29 20:27:28 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function expand_variable_qw expande la variable entre las " "
@function exp_var_qm copia el nombre lo busca en el env y lo copia
@function count_env_qw cuenta la cantidad de caracteres de la variable expandida
@function check_env_qw busca el puntero de la variable para luego buscarla
@function manage_count_env_qw gestiona las variables dentro del las " "
*/
static void	expand_env_qm(char *ptr, char *argv, int *count_copy)
{
	int	count;
	int	count_ptr;

	count = 0;
	count_ptr = 0;
	while (ptr[count_ptr] != '=')
		count_ptr++;
	if (ptr[count_ptr] == '=')
		count_ptr++;
	while (ptr[count_ptr] != '\0')
	{
		argv[*count_copy] = ptr[count_ptr];
		count_ptr++;
		*count_copy += 1;
	}
}

int	exp_var_qm(t_shell *shell, char *my_input, char *argv, int *count_copy)
{
	char	*environment_variabl;
	char	*ptr;
	int		count;

	count = 1;
	ptr = NULL;
	environment_variabl = NULL;
	if (my_input[count] = '?')
	{
		ptr = argv;
		argv = ft_strjoin(ptr, ft_itoa(shell->child_status));
		free(ptr);//se puede liberar????
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

static void	count_env_qm(char *ptr, int *size)
{
	int	count;

	count = 0;
	while (ptr[count] != '\0')
	{
		count++;
		if (ptr[count] != '\0')
			*size += 1;
	}
}

static void	check_env_qm(t_shell *shell, char *environment_variabl, int *size)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = get_ptr(shell, environment_variabl);
	if (ptr)
		count_env_qm(&ptr[ft_strlen(environment_variabl)], size);
}

int	manage_count_env_qm(t_shell *shell, char *my_input, int *size)
{
	int		count;
	char	*environment_variabl;

	count = 1;
	environment_variabl = NULL;
	if (my_input[count] == '?')
		count++;
	else
	{
		count += copy_env(shell, &my_input[count], &environment_variabl);
		if (environment_variabl)
		{
			check_env_qm(shell, environment_variabl, size);
			free(environment_variabl);
		}
	}
	return (count);
}
