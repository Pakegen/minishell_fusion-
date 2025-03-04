/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:52:41 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:53 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_and_free(char *s1, char *s2)
{
	char	*new_string;

	if (!s1)
		s1 = (char *)ft_calloc(1, 1);
	if (!s2)
		return (free(s1), NULL);
	new_string = ft_strjoin(s1, s2);
	free(s1);
	return (new_string);
}

char	*read_file(int fd, char *buffer)
{
	int		size;
	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	size = 1;
	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (size > 0)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size == -1)
			return (free(temp), NULL);
		temp[size] = '\0';
		buffer = join_and_free(buffer, temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	return (buffer);
}

char	*get_line(char *line)
{
	int		i;
	int		size;
	char	*texte;

	if (line[0] == 0)
		return (NULL);
	size = 0;
	while (line[size] && line[size] != '\n')
		size++;
	texte = (char *)malloc(sizeof(char) * size + 2);
	if (!texte)
		return (NULL);
	i = 0;
	while (i < size)
	{
		texte[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		texte[i++] = '\n';
	texte[i] = '\0';
	return (texte);
}

char	*next(char *line)
{
	int		i;
	int		j;
	char	*texte;

	i = 0;
	if (line[0] == 0)
		return (free(line), NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] && line[i] == '\n')
		i++;
	texte = (char *)malloc((ft_strlen(line) - i) + 1);
	if (!texte)
		return (NULL);
	j = 0;
	while (line[i])
		texte[j++] = line[i++];
	texte[j] = '\0';
	free(line);
	return (texte);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*texte;

	line = read_file(fd, line);
	if (!line)
		return (NULL);
	texte = get_line(line);
	line = next(line);
	return (texte);
}
