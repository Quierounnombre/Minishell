/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/29 11:45:14 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libs/define.h"
# include "../libft_def/libft.h"
# include <sys/wait.h>
# include "libs/structs.h"
# include "libs/define.h"
# include "readline/readline.h"
# include <sys/stat.h>
# include <errno.h>

/*-----STARUP-----*/

t_bool	start(t_shell **shell, char **env);
t_bool	init_shell_struct(t_shell **shell);
t_bool	clone_env(char **env, t_shell *shell);

/*-----CMD-----*/

void	process_executer(t_shell *shell);
char	*search_for_path(char *raw_path);
void	cmd_executer(t_shell *shell);
t_bool	is_built_in(t_shell *shell);
void	do_build_in(t_shell *shell);
void	echo(t_shell *shell);
void	ft_pwd(char **env);
void	ft_env(char **env);
void	ft_cd(const char *dir, t_shell *shell);
void	ft_export(t_shell *shell, char	*s);
void	ft_unset(t_shell *shell, char *s);
void	ft_exit(t_shell *shell);

/*-----PROCESS-----*/

t_bool	add_pid_to_lst(t_lstmng *mng, pid_t pid);
t_bool	do_fork(t_shell *shell);
void	ft_pipe(t_shell *shell);
void	input_redirect(t_shell *shell);
void	mng_redirections(t_shell *shell);
void	output_redirection(t_shell *shell);
void	output_append(t_shell *shell);

/*-----ERRORMNG-----*/

void	ft_error(t_shell *shell, errno_t error_code);
void	ft_cleanshell(t_shell *shell);

/*-----UTILS-----*/

t_bool	store_child(pid_t pid, t_list **lst, t_shell *shell);
t_bool	ft_storecmd(t_cmd *cmd, t_lstmng *mng);
void	ft_cleanchild(void *node);
void	ft_cleancmd(void *node);
char	*ft_open_file(t_shell *shell);
void	ft_delete_file(t_shell *shell, char *file);
int		find_string(char **env, char *target);

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
int		manage_count_env_qm(t_shell *shell, char *my_input, int *size);
int		exp_var_qm(t_shell *shell, char *my_input, char *argv, int *count_copy);
char	*get_ptr(t_shell *shell, char *ev);
int		strncmp_qm(const char *s1, const char *s2);
void	start_new_nodo(t_shell *shell);
void	start_nodo(t_cmd *new_cmd);
int		copy_qm(t_shell *shell, char *argv, char *my_input, int *count_copy);
int		argv_with_qm(t_shell *shell, char *my_input, char skip, int *size);
void	lstadd_back_nodo(t_red **lst, t_red *new);
void	ft_path(t_shell *shell, t_cmd *new_cmd);
int		copy_qm(t_shell *shell, char *argv, char *my_input, int *count_copy);
int		count_size_red(t_shell *shell, char *input);

#endif