/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:55:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:39:05 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../minishell.h"

typedef struct s_size
{
	int	size_pipe;
	int	size_token;
	int	size_str;
	int	size_in;
	int	size_out;
	int	ctoken;
	int	copy;
}				t_size;

typedef struct s_red
{
	char			*file;
	int				tipe;
	int				fd;
	struct s_red	*next;
}	t_red;

typedef struct s_cmd
{
	char	*filepath;
	char	**argv;
	t_red	*redir_in;
	t_red	*redir_out;
}	t_cmd;

typedef struct s_child
{
	t_bool	is_limit_end;
	t_bool	is_limit_sta;
	t_cmd	*cmd;
	pid_t	pid;
}	t_child;

typedef struct s_shell
{
	char				**separate_path;
	t_lstmng			*childs;
	t_lstmng			*cmds;
	char				**env;
	int					fd[2][2];
	t_size				s_i;
	pid_t				self_pid;
	int					child_status;
	struct sigaction	sact;
}	t_shell;

#endif
