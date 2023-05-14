/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/14 20:01:19 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libs/define.h"
# include "../libft_def/libft.h"
# include "libs/structs.h"
# include "readline/readline.h"

/*-----STARUP-----*/

t_bool	start(t_shell **shell);
t_bool	init_shell_struct(t_shell **shell);

/*-----CMD-----*/

char	*await_cmd(void);
char	*search_for_path(char *raw_path);
void	cmd_manager(t_cmd *cmd, t_shell *shell);

/*-----PROCESS-----*/

t_bool	add_pid_to_lst(t_lstmng *mng, pid_t pid);
t_bool	do_fork(t_shell *shell);

/*-----ERRORMNG-----*/

void	ft_error(t_shell *shell, errno_t error_code);
void	ft_cleanshell(t_shell *shell);

/*-----UTILS-----*/

t_bool	store_child(pid_t pid, t_list **lst);
void	ft_cleanchild(void *node);
void	ft_cleancmd(void *node);

/*-----PARSE-----*/

void	path_function(char **env, t_shell main_struct);
void	separation(t_shell main_struct, char *my_input);
void	check_size(t_shell main_struct, char *my_input);
void	check_size_pipe(t_shell main_struct, char *my_input);
void	check_size_token(t_shell main_struct, char *my_input);
void	entrecomillada(char *my_input, int *count);
void	check_pipe(t_shell main_struct, char *my_input, int *count);
void	redirects(t_shell main_struct, char *my_input, int *count);
void	space_tab(char *my_input, int *count);
void	token_entrecomillada(t_shell main_struct, char *my_input, int *count);
void	copy_token(t_shell main_struct, char *my_input, char *content, int *count);

#endif