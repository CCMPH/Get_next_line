/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 08:30:43 by chartema      #+#    #+#                 */
/*   Updated: 2021/11/15 15:55:30 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Test comment
int	check_newline(char *storage)
{
	int	i;

	i = 0;
	if (!storage)
		return (0);
	//printf("wat is storage:%s\n", storage);
	while (storage[i] != '\0')
	{
		if (storage[i] == '\n')
			{
			//printf("Joepie gevonden\n");
			return (1);
			}
		i++;
	}
	return (0);
}

char	*get_one_line(char *storage)
{
	char	*rline;
	int		i;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
	{
		i++;
		if (storage[i] == '\n')
		{
			i++;
			break ;
		}
	}
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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*join_storage_and_buff(char *storage, char *buff)
{
	int		i;
	int		j;
	char	*str;

	str = malloc((ft_strlen(storage) + ft_strlen(buff) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (storage[i] != '\0')
	{
		str[i] = storage[i];
		i++;
	}
	while (buff[j] != '\0')
	{
		str[i + j] = buff[j];
		j++;
	}
	str[ft_strlen(storage) + ft_strlen(buff) + 1] = '\0';
	free(storage);
	return (str);
}

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
		//printf("Gaat in de loop\n");
		reader = read(fd, buff, BUFFER_SIZE);
		//printf("Buffer [%s]\n", buff);
		//printf("Reader [%d]\n", reader);
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

char	*get_new_storage(char *storage)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	// if (!storage[i])
	// {
	// 	free(storage);
	// 	return (NULL);
	// }
	str = (char *)malloc((ft_strlen(storage) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	i++;
	//printf("Storage in get_new_storage [%s]\n", storage);
	while (storage[i] != '\0')
	{
		str[j] = storage[i];
		i++;
		j++;
	}
	//printf("str na whileloop get_new_storage [%s]\n", str);
	str[j] = '\0';
	free(storage);
	//printf("str na get_new_storage [%s]\n", str);
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
	//storage = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!storage)
		return (NULL);
	storage = read_to_storage(fd, storage);
	//printf("Storage na read_to_storage [%s]\n", storage);
	rline = get_one_line(storage);
	//printf("Storage na get_one_line [%s]\n", storage);
	storage = get_new_storage(storage);
	//printf("Storage na get_new_storage [%s]\n", storage);
	return (rline);
}

//gcc -Wall -Wextra -Werror -D BUFFER_SIZE=50 *.c
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	i = 0;
	fd1 = open("test2.txt", O_RDONLY);
	while (i < 10)
	{
		line = get_next_line(fd1);
		printf("line %03d: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
