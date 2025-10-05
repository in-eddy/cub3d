/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:42:55 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/10/05 01:49:05 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int main(int ac, char **av)
{
	t_map	*map;
	char	**lines;
	
	if (ac < 2)
	{
		write(2, "few arguments\n", 15);
		exit(1);
	}
	lines = check_map(av[1]);
	// 	int i = 0;
	// while (lines[i])
	// {
	// 	printf("%s",lines[i]);
	// 	i++;
	// }
	if (!lines)
		ft_done(1);
	map = init_map();
	map = pars_map(lines, map);
	if (!map)
		ft_done(1);
	int i = 0;
	while (map->map[i])
	{
		printf("%s\n",map->map[i]);
		i++;
	}
	
	
}