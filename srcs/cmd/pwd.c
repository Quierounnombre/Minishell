/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:44:42 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/16 11:55:36 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(char **env)
{
	int		pos_pwd;
	char	*pwd;

	pos_pwd = find_string(env, "PWD");
	if (pos_pwd == FT_INVALID_POS)
		pwd = getcwd(NULL, 0);
	else
	{
		pwd = env[pos_pwd];
		pwd += 4;
	}
	if (pwd)
	{
		printf("%s\n", pwd);
		if (pos_pwd == FT_INVALID_POS)
			free(pwd);
	}
}
