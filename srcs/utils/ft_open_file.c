/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:07:50 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/23 16:17:27 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Crea un archivo para una S dada
static void	make_file(t_shell *shell, char *s)
{
	int		fd;

	fd = 0;
	fd = open(s, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd < 0)
		ft_error(shell, fd);
	close(fd);
}

//Comprueba si el archivo existe, true en caso de que no exista el archivo
static t_bool	ft_file_exist(char *s)
{
	struct stat	file_info;
	errno_t		error;

	if (stat(s, &file_info) < 0)
	{
		error = errno;
		if (error == ENOENT)
			return (true);
		return (false);
	}
	return (false);
}

/*
Genera un archivo con un nombre aleatorio dado por una dirección de memoria
aleatoria
@param shell Se usa para en caso de ser necesario llamar a la función de error
@return devuelve una string con el filepath del archivo
*/
char	*ft_open_file(t_shell *shell)
{
	int			seed;
	char		*s;

	s = NULL;
	seed = ((((int)&seed) / 4) >> 2) * -1;
	while (true)
	{
		s = ft_itoa(seed);
		if (s)
		{
			if (ft_file_exist(s))
			{
				make_file(shell, s);
				return (s);
			}
			free(s);
			seed++;
		}
		else
			ft_error(shell, -1);
	}
	return (s);
}
