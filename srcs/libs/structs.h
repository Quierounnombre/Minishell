/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:55:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/16 15:42:21 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../minishell.h"

/*
Estructura general
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
Estruct general para la redireciones.
@param file Es el archivo el cual queremos abrir/usar.
@param tipe Como vamos a usarlo, es un heredoc? es un append, etc.
@param fd El fd al cual se redirije;
*/
typedef struct s_red
{
	char	*file;
	int		tipe;
	int		fd;
}	t_red;

/*
Estructura con la información relativa a 1 comando.
@param filepath es la ruta del archivo.
@param argv son los argumentos del comando.
@param redir_in redirección de entrada.
@param redir_in redirección de salida.
*/
typedef struct s_cmd
{
	char	*filepath;
	char	**argv;
	t_red	*redir_in;
	t_red	*redir_out;
}	t_cmd;

#endif