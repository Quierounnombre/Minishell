/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:51:00 by lyandriy          #+#    #+#             */
/*   Updated: 2023/06/21 16:45:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int i = 0;
				shell->cmds->current = shell->cmds->lst_head;
				while (((t_cmd *)(shell->cmds->current->content)))
				{
					while (((t_cmd *)(shell->cmds->current->content))->argv[i] != NULL)
					{
						//shell->cmds->current->co
						printf("filepath: %s\n", ((t_cmd *)(shell->cmds->current->content))->filepath);
						printf("%s\n", ((t_cmd *)(shell->cmds->current->content))->argv[i]);
						if (((t_cmd *)(shell->cmds->current->content))->redir_in)
							printf("%s\n", ((t_cmd *)(shell->cmds->current->content))->redir_in->file);
						i++;
					}
					//shell->cmds->current = shell->cmds->current->next;
					i = 0;
				}