/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:55:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/14 15:28:09 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../minishell.h"

//NOTA hace falta un limpiador de childs al destruirse trar execve

/*
@param childs lista con manager que almacena los hijos
@param cmds lista con los comandos
@param self_pid pid propio, sera 0 en caso de ser hijo
*/
typedef struct s_shell
{
	t_lstmng	*childs;
	t_lstmng	*cmds;
	pid_t		self_pid;
}	t_shell;


typedef struct s_size
{
	int	size_pipe;
	int	size_token;
	int	size_str;
}				t_size;

typedef struct s_red
{
	int		*redirect_type;
	char	*redrect_file;
}			t_red;

typedef struct s_main
{
	char	**separate_path;//rutas separadas *malloc*
	t_size	size_input;//cantidad de pipe y comandos
	t_list	*input;//comandos con sus argumentos
	t_red	red_struct;//estuctura para redirecciones
}		t_main;

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