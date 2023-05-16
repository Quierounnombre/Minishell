/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:55:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/16 12:40:58 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../minishell.h"

/*
@param childs lista con manager que almacena los hijos
@param cmds lista con los comandos
@param self_pid pid propio, sera 0 en caso de ser hijo
@param env es el enviroment
@param tube[2] es el fd de la tuberia;
*/
typedef struct s_shell
{
	t_lstmng	*childs;
	t_lstmng	*cmds;
	pid_t		self_pid;
	char		**env;
	int			tube[2];
}	t_shell;

/*
@param filepath es la ruta del archivo
@param argv son los argumentos del comando
*/
typedef struct s_cmd
{
	char	*filepath;
	char	**argv;
}	t_cmd;

#endif