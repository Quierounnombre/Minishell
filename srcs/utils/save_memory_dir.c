/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_memory_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:30:38 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/16 16:54:55 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_ptr(uintptr_t num, int fd)
{
	if (num > 15)
	{
		print_ptr(num / 16, fd);
		print_ptr(num % 16, fd);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), fd);
		else
			ft_putchar_fd(((num - 10) + 'a'), fd);
	}
}

void	save_memory_dir(unsigned long long dir)
{
	int		fd;

	fd = 0;
	fd = open("memory_dirs", O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd)
	{
		ft_putstr_fd("0x", fd);
		print_ptr(dir, fd);
		ft_putstr_fd("\n", fd);
		close(fd);
	}
}
