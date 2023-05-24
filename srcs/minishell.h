/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/22 20:22:58 by lyandriy         ###   ########.fr       */
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

int		parse(t_shell *shell, char *input, char **env);
int		check_pipes(t_shell *shell, char *my_input);
void	quotation_marks(char *my_input, int *count);
int		separation(t_shell *shell, char *my_input, char **env);
int		start_nodo(t_cmd *new_cmd);
void	space_tab(char *my_input, int *count);
void	create_node(t_shell *shell, char *my_input, int *count, t_cmd *new_cmd);
void	copy_cmd_token(char *my_input, int count, t_cmd *new_cmd);
void	copy_doble_quotation_marks(char *my_input, int *count, char *content);
void	copy_simple_quotation_marks(char *my_input, int *count, char *content);

#endif