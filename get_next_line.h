/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:22:14 by chartema      #+#    #+#                 */
/*   Updated: 2021/11/24 14:25:24 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

int		check_newline(char *storage);
int		ft_strlen(char *s);
char	*join_storage_and_buff(char *storage, char *buff);
char	*free_line(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif