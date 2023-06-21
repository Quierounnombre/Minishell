/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:15:21 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/25 11:59:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "../minishell.h"

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

//Redefinidos sus valores para el que codigo sea compatible

# ifndef REDIRECT_INPUT
#  define REDIRECT_INPUT 21
# endif

# ifndef REDIRECT_OUTPUT
#  define REDIRECT_OUTPUT 42
# endif

# ifndef HERE_DOC
#  define HERE_DOC 260
# endif

# ifndef MODO_APPEND
#  define MODO_APPEND 84
# endif

# ifndef NO_REDIRECT
#  define NO_REDIRECT 5
# endif

#endif
