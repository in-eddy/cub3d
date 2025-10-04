/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:29:02 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/10/04 17:17:07 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_map(t_bmap *bmap)
{
	bmap->smap->p_x = 0;
	bmap->smap->p_y = 0;
	bmap->smap->map_h = 0;
	bmap->smap->map_w = 0;
	bmap->smap->position = '\0';
	bmap->flag = 0;
	bmap->c = 0;
	bmap->f = 0;
	bmap->no = NULL;//////
	bmap->so = NULL;
	bmap->we = NULL;
	bmap->ea = NULL;
	bmap->map = NULL;
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
	lines = ft_alloc(8 * (i + 1));
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

int	check_spaces(char *str, int *j)
{
	if (str[(*j) - 1] && str[(*j) - 1] != '1')
		return (0);
	else
	{
		while (str[*j] && (str[*j] == ' ' || str[*j] == '	'))
		{
			(*j)++;
			// if (str[*j] == '0' && (str[(*j) + 1] == ' ' || str[(*j) + 1] == '	'))
			// 	(*j)++;
			// else
			// 	return (0);
		}
		if (str[*j] && str[*j] != '1')
			return (0);
	}
	return (1);
}

int	pars_s_map(char *str)/// as loop ///walls
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	if (str[0] == '1' && str[ft_strlen(str)] == '1')
	{
		while (str[j])
		{
			if (str[j] == '1' || str[j] == '0')
				j++;
			else if ((str[j] == 'N' || str[j] == 'S'
				|| str[j] == 'E' || str[j] == 'w'))
			{
				flag += 1;
				j++;
			}
			else if (!check_spaces(str, &j))
				return (-1);
			else
				return (-1);
			j++;
		}
		return (flag);
	}
	
}

int	check_pars(char *str)///// as loop
{
	int	res;

	res = pars_s_map(str);
	if (!res)
		return (write(2, "missing player\n", 16), 0);
	else if (res > 1)
		return (write(2, "duplicate player\n", 18), 0);
	else if (res == -1)
		return (write(2, "wrong caractere\n", 17), 0);
	return (1);
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
		j = 0;
		str = ft_strtrim(lines[i], " 	\n");
		while (str[j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

// char	*fill_map_2(char *lines, int *i, int max)
// {
// 	int	j;

// 	j = 0;
// 	while ()
// }

t_bmap	*fill_map(char *lines, int *i, t_bmap *my_map, int max)
{
	char	*str;
	int		j;
	int		k;

	k = *i;
	j = 0;
	str = ft_strtrim(lines[*i], " 	\n");
	while (str[j])
	{
		if (str[j] == '1')
			j++;
		else
			return (write(2, "open wall\n", 11), NULL);
	}
	while (lines[*i])
	{
		str = ft_strtrim(lines[*i], " 	\n");
		if (!check_pars(str))
			return (NULL);
		if (!lines[(*i) + 1])
		{
			str = ft_strtrim(lines[*i], " 	\n");
			while (str[j])
			{
				if (str[j] == '1')
					j++;
				else
					return (write(2, "open wall\n", 11), NULL);
			}
		}
		(*i)++;
	}
	my_map->map = ft_alloc(8 * ((*i) - k + 1));
	j= 0;
	while (k <= (*i))
	{
		// my_map->map[j] = ///lmap lm9ada
		j++;
		k++;
	}
	my_map->map[j] = NULL;
}

t_bmap	*pars_map(char	**lines)
{
	int		i;
	char	*str;
	t_bmap	*my_map;

	i = 0;
	init_map(my_map);
	while(lines[i])
	{
		str = ft_strtrim(lines[i], " 	\n");
		if (str[0] != "1")
		{
			if (!ft_strncmp(str, "NO", 2))
				my_map->f += 1;
			else if (!ft_strncmp(str, "SO", 2))
				my_map->f += 1;
			else if (!ft_strncmp(str, "WE", 2))
				my_map->f += 1;
			else if (!ft_strncmp(str, "EA", 2))
				my_map->f += 1;
			else if (!ft_strncmp(str, "F", 1))
				my_map->f += 1;
			else if (!ft_strncmp(str, "C", 1))
				my_map->f += 1;
			else
				return (write(2, "wrong character\n", 17), NULL);
		}
		// else
		// --->stock function
		else if (str[0] == "1")
		{
			if (my_map->f != 6)
			{
				if (my_map->f < 6)
					return (write(2, "missing identifier\n", 20), NULL);
				else
					return (write(2, "duplicate identifier\n", 22), NULL);
			}
			////the small map;//+ max function 
		}
		i++;
	}
}
