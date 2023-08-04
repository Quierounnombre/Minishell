/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_text_qm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:13:25 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 16:13:55 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	copy_text_qm2(t_shell *shell, char *my_input, char *str, int *count)
{
	int		size;
	char	skip;

	size = 0;
	skip = my_input[*count - 1];
	if (my_input[*count] == '$' && skip == '\"')
	{
		if (!ft_isalnum(my_input[*count + 1]) && my_input[*count + 1] != '?'
			&& my_input[*count] != skip)
			argv_alnum(str, &size, count);
		else
			*count += exp_var_qm(shell, &my_input[*count], str, &size);
	}
	else
	{
		str[size] = my_input[*count];
		*count += 1;
		size++;
	}
	return (size);
}

char	*copy_text_qm(t_shell *shell, char *my_input, int *count)
{
	char	skip;
	char	*str;
	int		size;

	str = NULL;
	size = 0;
	skip = my_input[*count];
	argv_with_qm(shell, &my_input[*count], my_input[*count], &size);
	str = malloc (sizeof(char) * (size + 1));
	if (!str)
		exit(1);
	*count += 1;
	while (my_input[*count] != skip && my_input[*count] != '\0')
		size = copy_text_qm2(shell, my_input, str, count);
	str[size] = '\0';
	if (my_input[*count] == skip)
		*count += 1;
	return (str);
}
