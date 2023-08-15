/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:57:17 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/15 14:37:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "../minishell.h"

//------------------------------------------------------------
//Redirections

# ifndef FT_RED_STD
#  define FT_RED_STD 5
# endif

# ifndef FT_RED_IN
#  define FT_RED_IN 21
# endif

# ifndef FT_RED_OUT
#  define FT_RED_OUT 42
# endif

# ifndef FT_RED_APPEND
#  define FT_RED_APPEND 84
# endif

# ifndef FT_RED_HEREDOC
#  define FT_RED_HEREDOC 260
# endif

//------------------------------------------------------------
//Redefine for compatibility

# ifndef RED_INPUT
#  define RED_INPUT 21
# endif

# ifndef RED_OUT
#  define RED_OUT 42
# endif

# ifndef HERE_DOC
#  define HERE_DOC 260
# endif

# ifndef APPEND
#  define APPEND 84
# endif

# ifndef NO_REDIR
#  define NO_REDIR 5
# endif

//------------------------------------------------------------
//Pipes

# ifndef READ
#  define READ 0
# endif

# ifndef WRITE
#  define WRITE 1
# endif

# ifndef PIPE_OG
#  define PIPE_OG 0
# endif

# ifndef PIPE_NEW
#  define PIPE_NEW 1
# endif

//------------------------------------------------------------
//find_string

# ifndef FT_INVALID_POS
#  define FT_INVALID_POS -1
# endif

//------------------------------------------------------------
//ENV DEFAULTS

# ifndef PWD_DEFAULT
#  define PWD_DEFAULT "PWD=/"
# endif

# ifndef OLDPWD_DEFAULT
#  define OLDPWD_DEFAULT "OLDPWD=/"
# endif

# ifndef HOME_DEFAULT
#  define HOME_DEFAULT "HOME=/"
# endif

# ifndef DEFAULT_ROOT
#  define DEFAULT_ROOT "/"
# endif

//------------------------------------------------------------
//strings

# ifndef PROMPT
#  define PROMPT "Minishell-> "
# endif

# ifndef CMD_NOT_FOUND
#  define CMD_NOT_FOUND "command not found"
# endif

# ifndef UNEXPECTED_TOKEN
#  define UNEXPECTED_TOKEN "Minishell syntax error near unexpected token"
# endif

# ifndef EXPORT_STR
#  define EXPORT_STR "The shell shall give the export attribute to the\
variables\n\
corresponding to the specified names, which shall cause them to\n\
be in the environment of subsequently executed commands. If the\n\
name of a variable is followed by =word, then the value of that\n\
variable shall be set to word.\n\
\n\
The export special built-in shall support the Base Definitions\n\
volume of POSIX.1-2017, Section 12.2, Utility Syntax Guidelines.\n\
\n\
When -p is specified, export shall write to the standard output\n\
the names and values of all exported variables, in the following\n\
format:\n\
\n\
	\"export %s=%s\\n\", <name>, <value>\n\
\n\
if name is set, and:\n\
\n\
	\"export %s\\n\", <name>\n\
\n\
if name is unset.\n\
\n\
The shell shall format the output, including the proper use of\n\
quoting, so that it is suitable for reinput to the shell as\n\
commands that achieve the same exporting results, except:\n\
\n\
1. Read-only variables with values cannot be reset.\n\
\n\
2. Variables that were unset at the time they were output need\n\
   not be reset to the unset state if a value is assigned to the\n\
   variable between the time the state was saved and the time at\n\
   which the saved output is reinput to the shell.\n\
\n\
When no arguments are given, the results are unspecified.\n\
\n\n\n\
"
# endif

#endif
