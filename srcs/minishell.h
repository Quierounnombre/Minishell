/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/19 17:13:18 by lyandriy         ###   ########.fr       */
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
void	separation(t_shell *shell, char *my_input);
void	space_tab(char *my_input, int *count);
void	create_node(t_shell *shell, t_cmd *new_cmd, char *my_input);
void	copy_cmd_token(t_shell *shell, t_cmd *new_cmd, char *my_input);
int		this_is_env(t_shell *shell, t_cmd *new_cmd, char *input, int *count_token);
char	*copy_token_env(char *ptr, int *count);
int		count_quotation_marks(t_shell *shell, char *my_input);
int		manage_count_env(t_shell *shell, char *my_input);
int		count_redirects(t_shell *shell, char *my_input);
int		copy_env(t_shell *shell, char *my_input, char **environment_variabl);
int		this_is_qm(t_shell *shell, t_cmd *new_cmd, char *my_input, int *count_token);
int		this_is_redirection(t_shell *shell, t_cmd *new_cmd, char *my_input);
void	pass_evn(char *input, int *count);
int		manage_count_env_qw(t_shell *shell, char *my_input, int *size);
int		exp_var_qm(t_shell *shell, char *my_input, char *argv, int *count_copy);
char	*get_ptr(t_shell *shell, char *ev);
int		strncmp_qm(const char *s1, const char *s2);
void	start_new_nodo(t_shell *shell);
void	start_nodo(t_cmd *new_cmd);

#endif