/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_qm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:16:12 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/19 18:03:43 by vicgarci         ###   ########.fr       */
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
void	expand_env_qm(char *ptr, char *argv, int *count_copy)
{
	int	count_ptr;

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

void	ft_aux(t_shell *shell, char *argv, int *count_copy)
{
	int	len;

	len = ft_calclen2(shell->child_status);
	len += *count_copy;
	if (shell->child_status == 0)
	{
		argv[*count_copy] = '0';
		*count_copy += 1;
	}
	else
	{
		*count_copy = len;
		while (shell->child_status > 0)
		{
			argv[--len] = (shell->child_status % 10) + '0';
			shell->child_status = shell->child_status / 10;
		}
	}
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
	char	*ptr;

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
	{
		*size += ft_calclen2(shell->child_status);
		count++;
	}
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
