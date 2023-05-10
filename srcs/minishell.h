/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/04 17:26:28 by vicgarci         ###   ########.fr       */
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

#endif