/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 13:18:04 by arommers      #+#    #+#                 */
/*   Updated: 2022/12/06 10:24:17 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (1);
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (s2);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	if (s2 == 0)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	// free(s2);
	return (new);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc (count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (count * size))
	{
		(*(unsigned char *)(ptr + i)) = 0;
			i++;
	}
	return (ptr);
}
