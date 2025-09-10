/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:29:02 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/09/10 20:34:12 by ieddaoud         ###   ########.fr       */
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

char	**check_map(char *name)
{
	int		fd;
	int		i;
	char	**lines;
	char	*line;

	fd = 0;
	i = 0;
	lines = NULL;
	if (ft_strcmp(name + (ft_strlen(name) - 4), ".cub"))
		return (write(2, "wrong name\n", 12), NULL);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (write(2, "failed opening the file\n", 25), NULL);
	while((line = get_next_line(fd)))
	{
		lines[i] = line;
		i++;
	}
	close(fd);
	return (lines);
}

// char	*pars_map(char	*name)
// {
	
// }