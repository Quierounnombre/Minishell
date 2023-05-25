/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/25 13:11:58 by vicgarci         ###   ########.fr       */
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

t_bool	start(t_shell **shell);
t_bool	init_shell_struct(t_shell **shell);

/*-----CMD-----*/

void	process_executer(t_shell *shell);
char	*await_cmd(void);
char	*search_for_path(char *raw_path);
void	cmd_executer(t_shell *shell);
t_bool	is_built_in(t_shell *shell);
void	do_build_in(t_shell *shell);
void	echo(t_shell *shell);
void	ft_pwd(void);
void	ft_env(char **env);

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

t_bool	store_child(pid_t pid, t_list **lst);
t_bool	ft_storecmd(t_cmd *cmd, t_lstmng *mng);
void	ft_cleanchild(void *node);
void	ft_cleancmd(void *node);
char	*ft_open_file(t_shell *shell);
void	ft_delete_file(t_shell *shell, char *file);

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