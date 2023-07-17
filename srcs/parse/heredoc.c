/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:30:14 by lyandriy          #+#    #+#             */
/*   Updated: 2023/07/17 18:14:27 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	strcmpare(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if ((ft_strlen(s1) - 1) == ft_strlen(s2))
	{
		while (s1[i] != '\n' && s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (-1);
			i++;
		}
		return (0);
	}
	return (-1);
}

static char	*create_name(void)
{
	int		numb;
	char	*name;
	char	*name_file;

	numb = 0;
	name = ft_itoa(numb);
	name_file = ft_strjoin("/tmp/.here_doc", name);
	free(name);
	while (!(access(name_file, F_OK)))
	{
		free(name_file);
		numb++;
		name = ft_itoa(numb);
		name_file = ft_strjoin("/tmp/.here_doc", name);
		free(name);
	}
	return (name_file);
}

void	heredoc(t_red *tmp)
{
	char	*line;
	char	*name;
	int		fd;

	name = create_name();
	fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd != -1)
	{
		while (true)
		{
			write (1, "> ", 2);
			line = ft_get_next_line(0);
			if (line == NULL || strcmpare(line, tmp->file) == 0)
			{
				free(tmp->file);
				tmp->file = name;
				fprintf(stderr, "heredoc %s\n", tmp->file);
				close(fd);
				free(line);
				return ;
			}
			write (fd, line, ft_strlen(line));
			free(line);
		}
	}
}

void	heredoc_unlink(t_shell *shell)
{
	t_cmd	*ptr_cmd;

	shell->cmds->current = shell->cmds->lst_head;
	while (shell->cmds->current)
	{
		ptr_cmd = shell->cmds->current->content;
		if (ptr_cmd->redir_in)
		{
			while (ptr_cmd->redir_in
				&& ptr_cmd->redir_in->tipe == FT_RED_HEREDOC)
			{
				unlink(ptr_cmd->redir_in->file);
				ptr_cmd->redir_in = ptr_cmd->redir_in->next;
			}
		}
		shell->cmds->current = shell->cmds->current->next;
	}
}