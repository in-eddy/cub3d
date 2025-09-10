/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:42:55 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/09/10 20:18:44 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int main(int ac, char **av)
{
	t_bmap	map;
	char	**lines;

	if (ac < 2)
	{
		write(2, "few arguments\n", 15);
		exit(1);
	}
	lines = NULL;
	init_map(&map);
	if (!check_map(av[1], lines))
		exit(1);
	int i = 0;
	while (lines[i])
	{
		printf("%s\n",lines[i]);
		i++;
	}

}