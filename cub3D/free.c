/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:07:53 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/09/10 17:07:47 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(void *p, int flag)
{
	static void	*list[INT_MAX];
	static int	i;

	if (flag)
	{
		list[i] = p;
		i++;
	}
	else
	{
		while (list[i])
		{
			free(list[i]);
			i--;
		}
	}
}

void	ft_done(size_t i)
{
	free_all(NULL, 0);
	exit (i);
}

void	*ft_alloc(size_t i)
{
	void	*res;

	res = malloc(i);
	if (!res)
		ft_done(0);
	free_all(res, 1);
	return (res);
}
