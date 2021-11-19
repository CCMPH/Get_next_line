/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 11:14:14 by chartema      #+#    #+#                 */
/*   Updated: 2021/11/19 11:08:51 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (!storage || !storage[i])
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

	if (!storage)
		return (NULL);
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
	while (storage[i] != '\0')
		str[j++] = storage[i++];
	str[j] = '\0';
	free(storage);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*rline;
	static char		*storage[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = read_to_storage(fd, storage[fd]);
	rline = get_one_line(storage[fd]);
	storage[fd] = get_new_storage(storage[fd]);
	return (rline);
}
