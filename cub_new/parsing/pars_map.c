/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:29:02 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/10/05 01:48:44 by ieddaoud         ###   ########.fr       */
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

	map = ft_alloc(sizeof(t_map));
	if (!map)
		return (NULL);

	map->x = 0;
	map->y = 0;
	map->map_h = 0;
	map->map_w = 0;
	map->flag = ft_alloc(sizeof(t_flag));
	if (!map->flag)
		return (NULL);
	map->flag->no = 0;
	map->flag->so = 0;
	map->flag->we = 0;
	map->flag->ea = 0;
	map->flag->f = 0;
	map->flag->c = 0;
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
	lines = ft_alloc(sizeof(char *) * (i + 1));
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
		str = ft_strtrim(lines[i], " \t");
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

char	**pars_s_map(char **lines, int *i, int max)
{
	char	*str;
	char	**map;
	int		j;
	int		k;

	k = *i;
	j = 0;
	while (lines[*i])
		(*i)++;
	map = ft_alloc(sizeof(char *) * ((*i) - k + 1));
	*i = k;
	k = 0;
	while (lines[*i])
	{
		str = ft_strtrim(lines[*i], " \t");
		if (!ft_strcmp(str, "\n"))
			return (write(2, "empty line\n", 12), NULL);
		map[k] = ft_alloc(sizeof(char) * (max + 1));
		j = 0;
		while (str[j] && j <= max)
		{
			// if (!str[j + 1] && (j + 1) <= max)
			// {
			// 	j++;
			// 	while (j < max)
			// 	map[k][j++] = '1';
			// }
			map[k][j] = str[j];
			j++;
		}
		map[k][j] = '\0';
		(*i)++;
		k++;
	}
	map[k] = NULL;
	return (map);
}

t_map	*pars_map(char **lines, t_map *map)
{
	char	*str;
	int		max;
	int		i;

	i = 0;
	max = find_max(lines);
	while (lines[i])
	{
		str = ft_strtrim(lines[i], " \t");
		if (str && str[0] != '1')
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
		else if (str && str[0] == '1')
		{
			puts("1");
			if (!check_flag(map))
				return (ft_done(1), NULL);
			map->map = pars_s_map(lines, &i, max);
			if (!map->map)
                return (NULL);
		}
		i++;
	}
	return (map);
}
