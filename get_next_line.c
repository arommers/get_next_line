/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 14:54:16 by arommers      #+#    #+#                 */
/*   Updated: 2022/12/02 11:32:44 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include

char	*ft_str_cut(char *str)
{
	//read the line until the break character. Then cut and return that part.
	char	*dst;
	char	*printline;
	int		i;
	int		len;
	
	i = 0;
	len = ft_strlen(str);
	dst = (!(char *)malloc(sizeof(char) * (len + 1)));
		return (NULL);
	if (str == 0)
		return (NULL);
	while ((str[i]) && str[i] != '\n')
		{
			dst[i] = str[i];
			i++;
		}
	dst[i] = '\n';
	dst[i + 1] = '\0'
	printline = dst;
	free (dst);
	return (printline);
}

char	*update_stash (char *str)
{
	// read the line and cut from the first break character onwards. 
	// Stash becomes the bytes that were read beyond the breakline.
	// What to do when the str contains more breaklines past the first one?
	char	*dst;
	char	*updated_stash;
	int		i;
	int		len;
	
	i = 0;
	len = ft_strlen(str);
	dst = (!(char *)malloc(sizeof(char) * (len + 1)));
		return (NULL);
	if (str[i])
		while (str[i] != '\n')
			i++;
		i++;
		while (str[i])
		{
			dst [i] = str[i];
			i++;
		}
	dst[i] = '\0'
	updated_stash = dst;
	free (dst);
	return (updated_stash);
}

char	*read_to_stash(int fd, char *str)
{
	// read the line into the buffer. Return the line when a portion of the stored bytes contain a '\n'.
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
	return (str);
}

char	*stash_to_line(char *str)
{
	// Copy the buffer into the line and cut the part until annd including the '\n'.
	char	*line;
	size_t	len;

	len = ft_strlen(str);
	line = (char *)malloc (sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line = strcpy(line, str);
	if (ft_strchr(line, '\n' );
		return (ft_strcut(line));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	stash = read_to_stash(fd, stash);
	line = stash_to_line(stash);
	stash = update_stash(stash)
	return(line);
}

int	main()
{
	open
}
