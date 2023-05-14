/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/14 15:27:08 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft_def/libft.h"
# include "libs/structs.h"
# include "readline/readline.h"

/*-----STARUP-----*/

t_bool	start(t_shell **shell);
t_bool	init_shell_struct(t_shell **shell);

/*-----CMD-----*/

char	*await_cmd(void);

/*-----PROCESS-----*/

t_bool	add_pid_to_lst(t_lstmng *mng, pid_t pid);
t_bool	do_fork(t_shell *shell);

/*-----UTILS-----*/

t_bool	store_node(pid_t pid, t_list **lst);

/*-----PARSE-----*/

void	path_function(char **env, t_main main_struct);
void	separation(t_main main_struct, char *my_input);
void	check_size(t_main main_struct, char *my_input);
void	check_size_pipe(t_main main_struct, char *my_input);
void	check_size_token(t_main main_struct, char *my_input);
void	entrecomillada(char *my_input, int *count);
void	check_pipe(t_main main_struct, char *my_input, int *count);
void	redirects(t_main main_struct, char *my_input, int *count);
void	space_tab(char *my_input, int *count);
void	token_entrecomillada(t_main main_struct, char *my_input, int *count);
void	comando(char *my_input, char **separate_path);

#endif