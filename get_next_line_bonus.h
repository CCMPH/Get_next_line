/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 11:15:42 by chartema      #+#    #+#                 */
/*   Updated: 2021/11/19 11:10:33 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

int		check_newline(char *storage);
int		ft_strlen(char *s);
char	*join_storage_and_buff(char *storage, char *buff);
char	*get_next_line(int fd);

#endif