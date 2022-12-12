/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 14:54:16 by arommers      #+#    #+#                 */
/*   Updated: 2022/12/12 16:08:34 by arommers      ########   odam.nl         */
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
		return (free(str), NULL);
	if (str == 0)
		return (NULL);
	while ((str[i]) && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	free(str);
	return (new);
}

char	*update_stash(char *str)
{
	int		i;
	int		j;

	i = ft_strchr(str, '\n');
	if (!ft_strchr(str, '\n') && str[i] != '\n')
		return (free(str), NULL);
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
	char	*buffer;
	int		cursor;

	cursor = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && cursor != 0)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[cursor] = 0;
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
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
	if (line[0] == 0)
		return (free(line), NULL);
	return (ft_str_cut(line));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if ((fd < 0) || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	stash = read_to_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = stash_to_line(stash);
	stash = update_stash(stash);
	return (line);
}

// int	main(void)
// {
// 	char	*lines;
// 	int		i;
// 	int		fd;

// 	i = 1;
// 	fd = open("sw.txt", O_RDONLY);
// 	while (i <= 11)
// 	{
// 		lines = get_next_line(fd);
// 		printf("%s\n", lines);
// 		free (lines);
// 		i++;
// 	}	
// 	close(fd);
// 	return (0);
// }

// 	int		fd;
// 	char	*nxt;

// 	fd = open("sw.txt", O_RDONLY);
// 	while ((nxt = get_next_line(fd)))
// 	{
// 		printf("%s\n", nxt);
// 	}
// 	return (0);
// }