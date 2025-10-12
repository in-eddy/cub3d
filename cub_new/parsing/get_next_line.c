/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:17:15 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/10/11 17:43:51 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_backup(int fd, char *backup)
{
	char	*buffer;
	int		l;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(backup), backup = NULL, NULL);
	l = 1;
	while (l > 0 && !ft_strchr(backup, '\n'))
	{
		l = read(fd, buffer, BUFFER_SIZE);
		if (l == -1)
		{
			free(buffer);
			free(backup);
			return (NULL);
		}
		buffer[l] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

char	*get_l(char *backup)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	if (!*backup)
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i++;
	// rest = ft_alloc(sizeof(char) * i + 1);
	rest = malloc(sizeof(char) * i + 1);
	if (!rest)
		return (NULL);
	while (j < i)
	{
		rest[j] = backup[j];
		j++;
	}
	rest[i] = '\0';
	return (rest);
}

char	*update(char *backup)
{
	int		i;
	int		j;
	char	*new_ba;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		return (NULL);
	}
	i += (backup[i] == '\n');
	new_ba = (char *)malloc(ft_strlen(backup) - i + 1);
	if (!new_ba)
		return (NULL);
	j = 0;
	while (backup[i + j] != '\0')
	{
		new_ba[j] = backup[i + j];
		j++;
	}
	new_ba[j] = '\0';
	free(backup);
	return (new_ba);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	backup = get_backup(fd, backup);
	if (!backup)
		return (free(backup), backup = NULL, NULL);
	line = get_l(backup);
	if (!line)
		return (free(backup), backup = NULL, NULL);
	backup = update(backup);
	return (line);
}
