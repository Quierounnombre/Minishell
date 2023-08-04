/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_alnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:50:20 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/04 16:50:38 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//copia $ seguido de caracter alfanumerico
void	argv_alnum(char *argv, int *count_copy, int *count)
{
	argv[*count_copy] = '$';
	*count += 2;
	*count_copy += 1;
}
