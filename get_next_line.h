/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:22:14 by chartema      #+#    #+#                 */
/*   Updated: 2021/11/19 10:00:41 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		check_newline(char *storage);
int		ft_strlen(char *s);
char	*join_storage_and_buff(char *storage, char *buff);
char	*get_next_line(int fd);

#endif