/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:55:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/11 19:16:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../minishell.h"

/*
@param childs lista con manager que almacena los hijos
@param self_pid pid propio, sera 0 en caso de ser hijo
*/
typedef struct s_shell
{
	t_lstmng	*childs;
	t_lstmng	*cmds;
	pid_t		self_pid;
}	t_shell;

/*
@param filepath es la ruta del archivo
@param argv son los argumentos del comando
@param env es la variable env
*/
typedef struct s_cmd
{
	char	*filepath;
	char	**argv;
	char	**env;
}	t_cmd;

#endif