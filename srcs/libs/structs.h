/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:55:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/21 16:45:26 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../minishell.h"

//Necesita documentación
typedef struct s_size
{
	int	size_pipe;
	int	size_token;
	int	size_str;
	int	size_in;
	int	size_out;
}				t_size;

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
	int		fd;//???
	struct s_red	*next;
}	t_red;

/*
@param filepath es la ruta del archivo
@param argv son los argumentos del comando
@param env es la variable env
*/
typedef struct s_cmd
{
	char	*filepath;
	char	**argv;
	t_red	*redir_in;
	t_red	*redir_out;
}	t_cmd;

/*
@param separate_path path_separado?
@param childs lista con manager que almacena los hijos
@param cmds lista con los comandos
@param size_input cantidad de pipe y comandos
@param red_struct estructura para redirecciones
@param self_pid pid propio, sera 0 en caso de ser hijo
*/
typedef struct s_shell
{
	char		**separate_path;
	char		**env;
	t_lstmng	*cmds;
	t_size		size_input;
	t_lstmng	childs;
	pid_t		self_pid;
}	t_shell;

#endif
