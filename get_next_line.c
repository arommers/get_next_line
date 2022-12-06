/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 14:54:16 by arommers      #+#    #+#                 */
/*   Updated: 2022/12/06 15:47:46 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_str_cut(char *str)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	if (str == 0)
		return (NULL);
	while ((str[i]) && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\n';
	new[i + 1] = '\0';
	return (new);
}

char	*update_stash(char *str)
{
	int		i;
	int		j;

	i = ft_strchr(str, '\n');
	j = 0;
	while (str[i + 1])
	{
		str[j++] = str[i + 1];
		i++;
	}
	while (str[j] != '\0')
	{
		str[j] = '\0';
		j++;
	}
	return (str);
}

char	*read_to_stash(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	cursor;

	cursor = 1;
	if (!str)
		str = ft_calloc(1, 1);
	while (!ft_strchr(str, '\n') && cursor != 0)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor < 0)
			return (NULL);
		buffer[cursor] = '\0';
		str = ft_strjoin(str, buffer);
	}
	if (cursor == 0)
		return (NULL);
	return (str);
}

char	*stash_to_line(char *str)
{
	char	*line;
	size_t	len;

	len = ft_strlen(str);
	line = ft_calloc (sizeof(char), len + 1);
	if (!line)
		return (NULL);
	line = ft_strjoin(line, str);
	return (ft_str_cut(line));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if ((fd < 0) || read(fd, NULL, 0))
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = stash_to_line(stash);
	stash = update_stash(stash);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*nxt;

	fd = open("sw.txt", O_RDONLY);
	while ((nxt = get_next_line(fd)))
		printf("%s", nxt);
	return (0);
}
