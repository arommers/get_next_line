/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 14:54:16 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/30 13:42:33 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include

char	*read_to_stash(int fd, char *str)
{
	char	*buffer;
	size_t	cursor;

	buffer = (char *)malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n'))
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
			if (cursor < 0)
				return (NULL);
		buffer[cursor] = '\0';
		str = ft_stcpycatdubwhatever(str, buffer));
	}
	free(buffer);
	return (str);
}

char	*stash_to_line(char *str)
{
	char	*line;
	size_t	len;

	len = ft_strlen(line) + ft_strlen(str);
	line = (char *)malloc (sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line = strcpy(line, str);
	if (ft_strchr(line, '\n' );
		return (strcut(line));
	
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	stash = read_to_stash(fd, stash);
	line = stash_to_line(stash);
	stash = update_stash(stash)
	return();
}

int	main()
{
	open
}
