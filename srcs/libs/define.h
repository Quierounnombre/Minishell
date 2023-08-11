/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:57:17 by lyandriy          #+#    #+#             */
/*   Updated: 2023/08/11 12:38:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "../minishell.h"

/*
Redirections
*/

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
//strings

# ifndef PROMPT
#  define PROMPT "Minishell-> "
# endif

#endif
