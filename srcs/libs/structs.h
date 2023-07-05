/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:55:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/05 11:44:12 by vicgarci         ###   ########.fr       */
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
	char			*file;
	int				tipe;
	int				fd;
	struct s_red	*next;
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

/*
Estructura con la información que gestionan cada hijo
@param cmd comando que va a ejecutar el hijo
@param pid pid propio del hijo
*/
typedef struct s_child
{
	t_cmd	*cmd;
	pid_t	pid;
}	t_child;

/*
Estructura de uso general con toda la información necesaria
@param separate_path path_separado?
@param childs lista con manager que almacena los hijos
@param cmds lista con los comandos
@param size_input cantidad de pipe y comandos
@param self_pid pid propio, sera 0 en caso de ser hijo
@param env guarda el entorno para la instancia de minishell
@param fd almacena los fd para la gestión de los pipes
*/
typedef struct s_shell
{
	char		**separate_path;
	t_lstmng	*childs;
	t_lstmng	*cmds;
	t_size		size_input;
	pid_t		self_pid;
	char		**env;
	int			fd[2][2];
}	t_shell;

#endif
