/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/16 18:32:24 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft_def/libft.h"
# include "sys/ioctl.h"
# include <sys/wait.h>
# include "libs/structs.h"
# include "libs/define.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <errno.h>
# include "libs/define.h"

t_shell	*g_shell;

/*-----STARUP-----*/

t_bool	start(t_shell **shell, char **env);
t_bool	init_shell_struct(t_shell **shell);
t_bool	clone_env_init(char **env, t_shell *shell);
t_bool	init_signals(struct sigaction *sact);
t_bool	start_env(char **env, t_shell *shell);
t_bool	update_shell_lvl(t_shell *shell);

/*-----SIGNAL-----*/

void	sig_handler(int sig);
void	sig_d(t_shell *shell);

/*-----CMD-----*/

void	cmd_executer(t_cmd *cmd, t_shell *shell);
t_bool	is_built_in(t_cmd *cmd);
void	do_build_in(t_cmd *cmd, t_shell *shell);
void	echo(t_cmd *cmd);
void	ft_pwd(char **env);
void	ft_env(char **env);
void	ft_cd(const char *dir, t_shell *shell);
void	ft_export(t_shell *shell, char	*s);
void	ft_unset(t_shell *shell, char *s);
void	ft_exit(t_shell *shell);
void	do_export(t_cmd *cmd, t_shell *shell);
void	do_unset(t_cmd *cmd, t_shell *shell);
void	sort_export(t_shell *shell);

//CD
void	change_dir(t_shell *shell, char *dir);
void	ft_reset_to_default(t_shell *shell);
char	*set_pwd_str(t_shell *shell, char *pwd);

/*-----PROCESS-----*/

t_bool	add_pid_to_lst(t_lstmng *mng, pid_t pid);
void	input_redirect(t_cmd *cmd, t_shell *shell);
void	mng_redirections(t_cmd *cmd, t_shell *shell);
void	output_redirection(t_cmd *cmd, t_shell *shell);
void	output_append(t_cmd *cmd, t_shell *shell);
t_bool	make_childs(t_shell *shell);
void	ft_child(t_shell *shell, t_child *child);
void	fork_child(t_shell *shell);
void	process_executer(t_shell *shell);
void	reset_shell(t_shell *shell);
void	fix_the_stdred_struct(t_child	*child, t_red *red);
void	wait_for_all(t_shell *shell);

/*-----ERRORMNG-----*/

void	ft_error(t_shell *shell, errno_t error_code);
void	ft_cleanshell(t_shell *shell);

/*-----UTILS-----*/

t_bool	store_child(pid_t pid, t_shell *shell);
t_bool	ft_storecmd(t_cmd *cmd, t_lstmng *mng);
void	ft_cleanchild(void *node);
void	ft_cleancmd(void *node);
char	*ft_open_file(t_shell *shell);
void	ft_delete_file(t_shell *shell, char *file);
int		find_string(char **env, char *target);
void	space_tab(char *my_input, int *count);
void	find_start_of_str(char *ptr, int *ptr_count);
void	lstadd_back_nodo(t_red **lst, t_red *new);
void	ft_path(t_shell *shell, t_cmd *new_cmd);
t_bool	should_be_close(int fd);
t_bool	should_be_env(char *s);
t_bool	clone_env(char **env, t_shell *shell);
void	make_new_env(t_shell *shell, char *s, int size);
void	save_memory_dir(unsigned long long dir);

/*-----PARSE-----*/

void	heredoc(t_red *tmp);
void	heredoc_unlink(t_shell *shell);
void	else_variable(t_shell *shell, t_cmd *new_cmd, char *input, int *c);
void	separation(t_shell *shell, char *my_input);
void	check_argv(t_shell *shell, t_cmd *new_cmd);
int		this_is_env(t_shell *shell, t_cmd *new_cmd, char *input, int *count_t);
void	argv_alnum(char *argv, int *count_copy, int *count);
int		copy_qm(t_shell *shell, char *argv, char *my_input, int *count_copy);
int		manage_count_env_qm(t_shell *shell, char *my_input, int *size);
char	*copy_text_qm(t_shell *shell, char *my_input, int *count);
char	*copy_tex_argv(char *input, int *c);
int		manage_count_env(t_shell *shell, char *my_input, int *flag);
void	ft_aux(t_shell *shell, char *argv, int *count_copy);
void	expand_env_qm(char *ptr, char *argv, int *count_copy);
int		ft_calclen2(int temp);
void	create_node(t_shell *shell, t_cmd *new_cmd, char *my_input);
int		exp_var_qm(t_shell *shell, char *my_input, char *argv, int *count_copy);
int		argv_with_qm(t_shell *shell, char *my_input, char skip, int *size);
t_bool	check_pipes(t_shell *shell, char *my_input);
t_bool	check_redirection(t_shell *shell, char *my_input, int *count);
t_bool	parse(t_shell *shell, char *input);
t_bool	check_redirect_env(t_shell *shell, char *input, int *count);
t_bool	print_err(char *text);
int		copy_env(t_shell *shell, char *input, char **environment_variabl);
char	*get_ptr(t_shell *shell, char *ev);
int		count_quotation_marks(char *my_input);
void	count_dollar(t_shell *shell, char *my_input, int *count);
void	set_s_i(t_shell *shell);
void	start_nodo(t_cmd *new_cmd);
void	ptr_exists(char *ptr, int *size);
void	expand_env(char *ptr, t_cmd *new_cmd, int *i, int *copy);
void	copy_argv(t_shell *shell, t_cmd *new_cmd, char *input);
char	*find_env(t_shell *shell, char *input, int *count);
void	copy_cmd_token(t_shell *shell, t_cmd *new_cmd, char *input);
int		this_is_redirection(t_shell *shell, t_cmd *new_cmd, char *my_input);

/*-----CONDITIONS-----*/

t_bool	is_greater_or_smaller(int c);
t_bool	is_34_or_39(int c);
t_bool	is_pipe(int c);

#endif