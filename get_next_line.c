/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 14:54:16 by arommers      #+#    #+#                 */
/*   Updated: 2022/12/05 13:59:11 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_cut(char *str)
{
	char	*new;
	char	*printline;
	int		i;
	int		len;
	
	i = 0;
	len = ft_strlen(str);
	new = (!(char *)malloc(sizeof(char) * (len + 1)));
		return (NULL);
	if (str == 0)
		return (NULL);
	while ((str[i]) && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\n';
	new[i + 1] = '\0'
	printline = ft_strjoin(printline, new);
	free (new);
	return (printline);
}

char	*update_stash (char *str)
{
	int		i;
	int		j;
	int		len;
	
	i = ft_strchr(str, '\n');
	j = 0;
	while (str[i + 1])
	{
		str[j++] = str[i + 1];
		i++;
	}
	while (str[j] != '\0')
	{
		str[j] = '\0'
		j++;
	}
	return (str);
}

char	*read_to_stash(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	cursor;

	while (!ft_strchr(str, '\n'))
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
			if (cursor < 0)
				return (NULL);
		buffer[cursor] = '\0';
		str = ft_strjoin(str, buffer));
	}
	free(buffer);
	return (str);
}

char	*stash_to_line(char *str)
{
	char	*line;
	size_t	len;

	len = ft_strlen(str);
	line = (char *)malloc (sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line = ft_strjoin(line, str);
	if (ft_strchr(line, '\n' );
		return (ft_strcut(line));
	else
		return ()
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	stash = read_to_stash(fd, stash);
	line = stash_to_line(stash);
	stash = update_stash(stash);
	return(line);
}

int	main()
{
	open
}
