/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_token_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:19:08 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/19 17:08:41 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@function copy copia variable
@function copy_token_env centa tam de variable y la copia
@function
@function
*/
/*static void	env_quoted(char *ptr, int *count, int *count_char, char skip)
{
	*count += 1;
	while (ptr[*count] != skip)
	{
		*count_char += 1;
		*count += 1;
	}
	*count += 1;
}*/

/*static int	copy_env_quoted(char *ptr, char *argv, int *copy_count, char skip)
{
	int	count_char;

	count_char = 0;
	*copy_count += 1;
	while (ptr[*copy_count] != skip)
	{
		printf("ptr %c\n", ptr[*copy_count]);
		argv[count_char] = ptr[*copy_count];
		count_char++;
		*copy_count += 1;
	}
	if (ptr[*copy_count] == skip)
		*copy_count += 1;
	return (count_char);
}*/

static void	copy(char *ptr, char *argv, int *copy)//copy copy_count
{
	int	count_char;

	count_char = 0;
	while (ptr[*copy] != ' ' && ptr[*copy] != '\t' && ptr[*copy] != '\0')
	{
		argv[count_char] = ptr[*copy];
		count_char++;
		*copy += 1;
	}
}

char	*copy_token_env(char *ptr, int *count)
{
	int		count_char;
	int		copy_count;
	char	*argv;

	count_char = 0;
	copy_count = *count;
	while (ptr[*count] != ' ' && ptr[*count] != '\t' && ptr[*count] != '\0')
	{
		count_char++;
		*count += 1;
	}
	argv = malloc(sizeof(char) * (count_char + 1));
	if (!argv)
		exit (1);
	argv[count_char] = '\0';
	copy(ptr, argv, &copy_count);
	return (argv);
}
