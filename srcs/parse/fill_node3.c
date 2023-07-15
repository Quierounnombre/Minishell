/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:33:32 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/15 16:19:32 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*copy_tex_argv(char *input, int *c)
{
	int		size;
	char	*str;

	size = 0;
	while (input[*c + size] != ' ' && input[*c + size] != '\t'
		&& input[*c + size] != '$' && input[*c + size] != '\0'
		&& input[*c + size] != '>' && input[*c + size] != '\"'
		&& input[*c + size] != '|' && input[*c + size] != '<'
		&& input[*c + size] != '\'')
		size++;
	str = malloc (sizeof(char) * (size + 1));
	if (!str)
		exit (1);
	size = 0;
	while (input[*c] != ' ' && input[*c] != '\t' && input[*c] != '$'
		&& input[*c] != '\0' && input[*c] != '>' && input[*c] != '\"'
		&& input[*c] != '|' && input[*c] != '<' && input[*c] != '\'')
	{
		str[size] = input[*c];
		size++;
		*c += 1;
	}
	str[size] = '\0';
	return (str);
}

int	argv_with_qm(t_shell *shell, char *my_input, char skip, int *size)
{
	int	count;

	count = 1;
	while (my_input[count] != skip && my_input[count] != '\0')
	{
		if (my_input[count] == '$' && my_input[0] == '\"')
		{
			if (!ft_isalnum(my_input[count + 1]) && my_input[count + 1] != '?'
				&& my_input[count] != skip)
			{
				*size += 1;
				count += 2;
			}
			else
				count += manage_count_env_qm(shell, &my_input[count], size);
		}
		else
		{
			*size += 1;
			count++;
		}
	}
	if (my_input[count] == skip)
		count++;
	return (count);
}

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

void	check_argv(t_shell *shell, t_cmd *new_cmd)
{
	if (shell->s_i.copy == 0)
		new_cmd->argv[shell->s_i.ctoken] = NULL;
	else if (new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] != '\0')
		new_cmd->argv[shell->s_i.ctoken][shell->s_i.copy] = '\0';
}
