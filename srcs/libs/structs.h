/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:55:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/24 19:44:23 by lyandriy         ###   ########.fr       */
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
	int	size_redir;
}				t_size;


typedef struct s_red
{
	char	*file;
	int		tipe;
	int		fd;
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
	int		*redirections;
	void	**type;
	char	**env;
	//t_red	*redir_in;
	//t_red	*redir_out;
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
	t_lstmng	*childs;
	t_lstmng	*cmds;
	t_size		size_input;
	t_red		red_struct;
	pid_t		self_pid;
}	t_shell;

#endif
