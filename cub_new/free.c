/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:07:53 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/10/05 01:36:41 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	free_all(void *p, int flag)
// {
// 	static void	*list[INT_MAX];
// 	static int	i;

// 	if (flag)
// 	{
// 		list[i] = p;
// 		i++;
// 	}
// 	else
// 	{
// 		while (list[i])
// 		{
// 			free(list[i]);
// 			i--;
// 		}
// 	}
// }

// void	ft_done(size_t i)
// {
// 	free_all(NULL, 0);
// 	exit (i);
// }

// void	*ft_alloc(size_t i)
// {
// 	void	*res;

// 	res = malloc(i);
// 	if (!res)
// 		ft_done(0);
// 	free_all(res, 1);
// 	return (res);
// }

#include <stdio.h>
#include <stdlib.h>

void free_all(void *p, int flag)
{
    static void **list = NULL;
    static size_t i = 0;
    static size_t capacity = 0;

    if (flag == 1) /* register pointer */
    {
        if (!p) return;

        /* 1) Avoid duplicates: check if already tracked */
        for (size_t j = 0; j < i; ++j)
            if (list[j] == p)
            {
                fprintf(stderr, "free_all: pointer %p already tracked (idx %zu)\n", p, j);
                return;
            }

        /* 2) Grow array if needed */
        if (i >= capacity)
        {
            size_t newcap = capacity ? capacity * 2 : 1024;
            void **tmp = realloc(list, newcap * sizeof(void *));
            if (!tmp)
            {
                /* catastrophic: free tracked memory and exit */
                for (size_t k = 0; k < i; ++k)
                    if (list[k]) free(list[k]);
                free(list);
                exit(1);
            }
            list = tmp;
            capacity = newcap;
        }

        list[i++] = p;
        return;
    }

    if (flag == 0) /* free all tracked pointers */
    {
        if (!list) {
            fprintf(stderr, "free_all: called but list already freed or never allocated\n");
            return;
        }

        /* Free each unique pointer once. After freeing set slot to NULL so duplicates (if any)
           will be skipped safely. */
        for (ssize_t idx = (ssize_t)i - 1; idx >= 0; --idx)
        {
            void *ptr = list[idx];
            if (ptr)
            {
                fprintf(stderr, "free_all: freeing %p (index %zd)\n", ptr, idx);
                free(ptr);
                list[idx] = NULL; /* mark consumed */
            } else {
                fprintf(stderr, "free_all: skip NULL slot at index %zd\n", idx);
            }
        }

        free(list);
        list = NULL;
        i = 0;
        capacity = 0;
        fprintf(stderr, "free_all: done\n");
        return;
    }
}



void	ft_done(size_t i)
{
	free_all(NULL, 0);
	exit(i);
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
