/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 11:15:13 by chartema      #+#    #+#                 */
/*   Updated: 2021/11/19 11:10:11 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *storage)
{
	int	i;

	i = 0;
	if (!storage)
		return (0);
	while (storage[i] != '\0')
	{
		if (storage[i] == '\n')
			return (1);
		i++;
	}
	return (0);
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

	if (!storage)
	{
		storage = (char *)malloc(1 * sizeof(char));
		storage[0] = '\0';
	}
	if (!storage)
		return (NULL);
	str = malloc((ft_strlen(storage) + ft_strlen(buff) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (storage[++i] != '\0')
		str[i] = storage[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(storage);
	return (str);
}
