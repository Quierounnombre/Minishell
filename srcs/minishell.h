/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/12 17:41:56 by vicgarci         ###   ########.fr       */
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

/*-----PARSE-----*/

int		copy_env(t_shell *shell, char *input, char **environment_variabl);
char	*get_ptr(t_shell *shell, char *ev);
void	find_start_of_str(char *ptr, int *ptr_count);
void	ptr_exists(char *ptr, int *size);
int		argv_with_qm(t_shell *shell, char *my_input, char skip, int *size);
void	ft_path(t_shell *shell, t_cmd *new_cmd);
int		copy_env(t_shell *shell, char *input, char **environment_variabl);
void	space_tab(char *my_input, int *count);
int		this_is_redirection(t_shell *shell, t_cmd *new_cmd, char *my_input);
void	copy_argv(t_shell *shell, t_cmd *new_cmd, char *input);
char	*find_env(t_shell *shell, char *input, int *count);
int		exp_var_qm(t_shell *shell, char *my_input, char *argv, int *count_copy);
void	copy_cmd_token(t_shell *shell, t_cmd *new_cmd, char *input);
void	create_node(t_shell *shell, t_cmd *new_cmd, char *my_input);
void	start_nodo(t_cmd *new_cmd);
void	start_new_nodo(t_shell *shell);
void	count_dollar(t_shell *shell, char *my_input, int *count);
int		count_quotation_marks(t_shell *shell, char *my_input);
int		ft_calclen2(int temp);
void	expand_env_qm(char *ptr, char *argv, int *count_copy);
void	ft_aux(t_shell *shell, char *argv, int *count_copy);
int		manage_count_env(t_shell *shell, char *my_input, int *flag);
char	*copy_tex_argv(char *input, int *c);
void	expand_env(char *ptr, t_cmd *new_cmd, int *i, int *copy);
char	*copy_text_qm(t_shell *shell, char *my_input, int *count);
int		manage_count_env_qm(t_shell *shell, char *my_input, int *size);
void	argv_alnum(char *argv, int *count_copy, int *count);
int		this_is_env(t_shell *shell, t_cmd *new_cmd, char *input, int *count_t);
void	copy_variable(t_shell *shell, t_cmd *new_cmd, char *input, int *c);
int		copy_qm(t_shell *shell, char *argv, char *my_input, int *count_copy);
void	check_argv(t_shell *shell, t_cmd *new_cmd);
void	else_variable(t_shell *shell, t_cmd *new_cmd, char *input, int *c);


#endif