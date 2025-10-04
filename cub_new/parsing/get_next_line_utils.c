/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:13:02 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/09/10 18:13:23 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// size_t	ft_strlen(char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }

char	*ft_strchr(char *s, int c)
{
	char	s1;
	char	*s2;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	s2 = (char *)s;
	s1 = (char)c;
	while (s2[i] != s1)
	{
		if (s2[i] == '\0')
			return (NULL);
		i++;
	}
	return (s2 + i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	arr = malloc(1 + ft_strlen(s1) + ft_strlen(s2) * sizeof(char));
	if (!arr)
		return (NULL);
	arr = ft_join(arr, s1, s2);
	free(s1);
	return (arr);
}

char	*ft_join(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
