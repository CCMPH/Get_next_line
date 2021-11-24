/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 08:30:43 by chartema      #+#    #+#                 */
/*   Updated: 2021/11/24 15:42:19 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*read_to_storage(int fd, char *storage)
{
	int		reader;
	char	*buff;

	if (!storage)
		storage = ft_calloc(1, sizeof(char));
	if (!storage)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free_line(storage));
	reader = 1;
	while (reader != 0 && !check_newline(storage))
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{	
			free(storage);
			return (free_line(buff));
		}
		buff[reader] = '\0';
		storage = join_storage_and_buff(storage, buff);
	}
	free(buff);
	return (storage);
}

static char	*get_one_line(char *storage)
{
	char	*rline;
	int		i;

	i = 0;
	if (!storage || !storage[i])
		return (NULL);
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	rline = ft_calloc(i + 2, sizeof(char));
	if (!rline)
		return (NULL);
	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
	{
		rline[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		rline[i] = storage[i];
		i++;
	}
	return (rline);
}

static char	*get_new_storage(char *storage)
{
	int		i;
	int		j;
	char	*str;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
		return (free_line(storage));
	str = ft_calloc((ft_strlen(storage) - i + 1), sizeof(char));
	if (!str)
		return (free_line(storage));
	j = 0;
	i++;
	while (storage[i] != '\0')
	{
		str[j] = storage[i];
		i++;
		j++;
	}
	free(storage);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*rline;
	static char		*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_to_storage(fd, storage);
	rline = get_one_line(storage);
	storage = get_new_storage(storage);
	return (rline);
}
