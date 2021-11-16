/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 08:30:43 by chartema      #+#    #+#                 */
/*   Updated: 2021/11/16 15:38:15 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_storage(int fd, char *storage)
{
	int		reader;
	char	*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	reader = 1;
	while (reader != 0 && !check_newline(storage))
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[reader] = '\0';
		storage = join_storage_and_buff(storage, buff);
	}
	free(buff);
	return (storage);
}

char	*get_one_line(char *storage)
{
	char	*rline;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	rline = (char *)malloc((i + 1) * sizeof(char));
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
	rline[i] = '\0';
	return (rline);
}

char	*get_new_storage(char *storage)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(storage) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (storage[i + j] != '\0')
	{
		str[j] = storage[i + j];
		j++;
	}
	str[j] = '\0';
	free(storage);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*rline;
	static char		*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
	{
		storage = (char *)malloc(1 * sizeof(char));
		storage[0] = '\0';
	}
	if (!storage)
		return (NULL);
	storage = read_to_storage(fd, storage);
	rline = get_one_line(storage);
	storage = get_new_storage(storage);
	return (rline);
}
