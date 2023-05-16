/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/16 12:10:45 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft_def/libft.h"
# include <sys/wait.h>
# include "libs/structs.h"
# include "readline/readline.h"

/*-----STARUP-----*/

t_bool	start(t_shell **shell, char **env);
t_bool	init_shell_struct(t_shell **shell, char **env);

/*-----CMD-----*/

char	*await_cmd(void);
char	*search_for_path(char *raw_path);
void	cmd_executer(t_shell *shell);
t_bool	is_built_in(t_shell *shell);
void	do_build_in(t_shell *shell);
void	echo(t_shell *shell);

/*-----PROCESS-----*/

t_bool	add_pid_to_lst(t_lstmng *mng, pid_t pid);
t_bool	do_fork(t_shell *shell);

/*-----ERRORMNG-----*/

void	ft_error(t_shell *shell, errno_t error_code);
void	ft_cleanshell(t_shell *shell);

/*-----UTILS-----*/

t_bool	store_child(pid_t pid, t_list **lst);
t_bool	ft_storecmd(t_cmd *cmd, t_lstmng *mng);
void	ft_cleanchild(void *node);
void	ft_cleancmd(void *node);

#endif