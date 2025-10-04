/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:42:55 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/10/04 18:13:11 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int main(int ac, char **av)
{
	t_map	map;
	char	**lines;
	
	if (ac < 2)
	{
		write(2, "few arguments\n", 15);
		exit(1);
	}
	lines = check_map(av[1]);
	if (!lines)
		ft_done(1);
	map = *pars_map(lines, &map);
	int i = 0;
	while (map.map[i])
	{
		printf("%s\n",map.map[i]);
		i++;
	}
	
	
}