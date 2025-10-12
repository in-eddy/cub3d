/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:29:02 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/10/12 12:04:53 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	init_map(t_map	*map)
// {
// 	map = ft_alloc(sizeof(t_map));
// 	if (!map)
// 		{
// 			printf("^^^^\n");
// 			return ;
// 		}
// 	map->x = 0;
// 	map->y = 0;
// 	map->map_h = 0;
// 	map->map_w = 0;
// 	map->flag = ft_alloc(sizeof(t_flag));
// 	map->flag->no = 0;
// 	map->flag->so = 0;
// 	map->flag->we = 0;
// 	map->flag->ea = 0;
// 	map->flag->f = 0;
// 	map->flag->c = 0;
// 	map->p = '\0';
// 	map->p_ea = NULL;
// 	map->p_no = NULL;
// 	map->p_so = NULL;
// 	map->p_we = NULL;
// }

t_map	*init_map(void)
{
	t_map	*map;

	// map = ft_alloc(sizeof(t_map));
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);

	map->x = 0;
	map->y = 0;
	map->map_h = 0;
	map->map_w = 0;
	// map->flag = ft_alloc(sizeof(t_flag));
	map->flag = malloc(sizeof(t_flag));
	if (!map->flag)
		return (NULL);
	map->flag->no = 0;
	map->flag->so = 0;
	map->flag->we = 0;
	map->flag->ea = 0;
	map->flag->f = 0;
	map->flag->c = 0;
	map->flag->p = 0;
	map->p = '\0';
	map->p_ea = NULL;
	map->p_no = NULL;
	map->p_so = NULL;
	map->p_we = NULL;
	map->map = NULL;

	return (map);
}


int	verify_map(char *name, int *i)
{
	char	*line;
	int		fd;

	if (ft_strcmp(name + (ft_strlen(name) - 4), ".cub"))
		return (write(2, "wrong name\n", 12),0);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (write(2, "failed opening the file\n", 25), 0);
	while((line = get_next_line(fd)))
	{
		(*i)++;
		free(line);
	}
	close (fd);
	return (1);
}

char	**check_map(char *name)
{
	int		fd;
	int		i;
	char	**lines;
	char	*line;

	i = 0;
	if (!verify_map(name, &i))
		return(NULL);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (write(2, "failed opening the file\n", 25), NULL);
	// lines = ft_alloc(sizeof(char *) * (i + 1));
	lines = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while((line = get_next_line(fd)))
	{
		lines[i] = line;
		i++; 
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}

int	find_max(char **lines)
{
	int	i;
	int	j;
	int	max;
	char	*str;

	i = 0;
	max = 0;
	while (lines[i])
	{
		// str = ft_strtrim(lines[i], " \t");
		str = lines[i];
		j = 0;
		while (str[j])
			j++;
		if (max < j)
			max = j;
		i++;
	}
	return (max);
}

int	check_flag(t_map *map)
{
	if (!map->flag->c || !map->flag->f || !map->flag->ea
		|| !map->flag->no || !map->flag->so || !map->flag->we)
		return (write(2, "missing identifier\n", 20), 0);
	else if (map->flag->c > 1 || map->flag->f > 1 || map->flag->ea > 1
		|| map->flag->no > 1 || map->flag->so > 1 || map->flag->we > 1)
		return (write(2, "duplicate identifier\n", 22), 0);
	return (1);
}

char	*ft_strjoin2(char *s1, char *s2)/////
{
	size_t	i;
	size_t	j;
	char	*d;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	// d = ft_alloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	d = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!d)
		return (NULL);
	while (s1 && i < ft_strlen(s1))
		d[j++] = s1[i++];
	i = 0;
	while (s2 && i < ft_strlen(s2))
		d[j++] = s2[i++];
	d[j] = '\0';
	return (d);
}


char	**pars_s_map(char **lines, int *i, int max)
{
	// char	*str;
	char	**map;
	int		j;
	int		k;

	k = *i;
	j = 0;
	while (lines[*i])
		(*i)++;
	// map = ft_alloc(sizeof(char *) * ((*i) - k + 1));
	map = malloc(sizeof(char *) * ((*i) - k + 1));
	*i = k;
	k = 0;
	while (lines[*i])
	{
		if (!ft_strcmp(ft_strtrim(lines[*i], " \t"), "\n"))
			return (write(2, "empty line\n", 12), NULL);
		// map[k] = ft_alloc(sizeof(char) * (max + 1));
		map[k] = malloc(sizeof(char) * (max + 1));
		j = 0;
		while (lines[*i][j] && lines[*i][j] != '\n')
		{
			map[k][j] = lines[*i][j];
			j++;
		}
		if ((lines[*i][j] == '\n' || !lines[*i][j]) && j < max)
		{
			while (j < max - 1)
			{
				map[k][j] = ' ';
				j++;
			}
		}
		map[k][j] = '\n';
		map[k][++j] = '\0';
		(*i)++;
		k++;
	}
	map[k] = NULL;
	return (map);
}

int	find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_valid(map->map[i][j]) && map->map[i][j] != '1' && map->map[i][j] != '0')
				map->flag->p += 1;
			j++;
		}
		i++;
	}
	if (!map->flag->p)
		return (write(2, "missing player\n", 16), 0);
	else if (map->flag->p > 1)
		return (write(2, "duplicate player\n", 18), 0);
	return (1);
}

t_map	*pars_map(char **lines, t_map *map)
{
	char	*str;
	int		max;
	int		i;

	max = 0;
	i = 0;
	while (lines[i])
	{
		str = ft_strtrim(lines[i], " \t");
		if (!ft_strcmp(str, "\n"))
		{
			i++;
			continue;
		}
		if (str && str[0] != '1' && str[0] != '0')
		{
			if (!ft_strncmp(str, "NO", 2))
			map->flag->no++;
			else if (!ft_strncmp(str, "SO", 2))
			map->flag->so++;
			else if (!ft_strncmp(str, "WE", 2))
			map->flag->we++;
			else if (!ft_strncmp(str, "EA", 2))
			map->flag->ea++;
			else if (!ft_strncmp(str, "F", 1))
			map->flag->f++;
			else if (!ft_strncmp(str, "C", 1))
			map->flag->c++;
			else
			return (write(2, "wrong character\n", 17), NULL);
		}
		// else
		// --->stock pic
		else if (str && (str[0] == '1' || str[0] == '0'))
		{
			max = find_max(lines + i);
			if (!check_flag(map))
			// return (ft_done(1), NULL);
				return (exit(1), NULL);
			map->map = pars_s_map(lines, &i, max);
			break;
		}
		i++;
	}
	return (map);
}

int	is_valid(char c)
{
	return ( c == 'N' || c == 'W' || c == 'E' || c == 'S'
		|| c == '1' || c == '0');
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	if (!final_parsing(map)|| !find_player(map))
		return (0);
	j = 0;
	while (map->map[0][j] && map->map[0][j] != '\n')
	{
		if (map->map[0][j] != '1' && map->map[0][j] != ' ' && map->map[0][j] != '\t')
			return (write(2, "open wall\n", 11), 0);
		j++;
	}
	i = 1;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			while (map->map[i][j] == ' ' || map->map[i][j] == '\t')
				j++;
			if (map->map[i][j] != '1' && map->map[i][j] != '\n')
				return (write(2, "open wall\n", 11), 0);
			else
			{
				while (map->map[i][j] != '\n')
					j++;
				while (map->map[i][j] == ' ' || map->map[i][j] == '\t' || map->map[i][j] == '\n')
					j--;
				if (map->map[i][j] != '1')
					return (write(2, "open wall\n", 11), 0);
				else
					break;
			}
			j++;
		}
		i++;
	}
	j = 0;
	while (map->map[i - 1][j])
	{
		if (map->map[i - 1][j] != '1' && map->map[i - 1][j] != ' '
			&& map->map[i - 1][j] != '\t' && map->map[i - 1][j] != '\n')
			return (write(2, "open wall\n", 11), 0);
		j++;
	}
	return (1);
}

// int	check_walls(char **map)
// {
// 	int		i, j;
// 	char	*str;

// 	// Check top wall
// 	str = ft_strtrim(map[0], " \t\n");
// 	if (!str)
// 		return (0);
// 	for (j = 0; str[j]; j++)
// 		if (str[j] != '1')
// 			return (free(str), write(2, "open wall top\n", 15), 0);
// 	free(str);

// 	// Check sides
// 	for (i = 0; map[i]; i++)
// 	{
// 		j = 0;
// 		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
// 			j++;
// 		if (!map[i][j] || map[i][j] != '1')
// 			return (write(2, "open wall left\n", 16), 0);
// 		while (map[i][j])
// 			j++;
// 		j--;
// 		while (j >= 0 && (map[i][j] == ' ' || map[i][j] == '\t'))
// 			j--;
// 		if (map[i][j] != '1')
// 			return (write(2, "open wall right\n", 17), 0);
// 	}

// 	// Check bottom wall
// 	str = ft_strtrim(map[i - 1], " \t\n");
// 	if (!*str)
// 		return (free(str), write(2, "empty last line\n", 16), 0);
// 	for (j = 0; str[j]; j++)
// 		if (str[j] != '1')
// 			return (free(str), write(2, "open wall bottom\n", 18), 0);
// 	free(str);
// 	return (1);
// }


int	final_parsing(t_map *map)
{
	int	i;
	int	j;
	
	// if (!check_walls(map->map) || !find_player(map))
	// 	return (0);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0')
			{
				if (is_valid(map->map[i][j - 1]) && is_valid(map->map[i][j + 1])
					&& is_valid(map->map[i + 1][j]) && is_valid(map->map[i - 1][j]))
					j++;
				else
					return (write(2, "invalid map\n", 13), 0);
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}
