/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:43:14 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/10/04 18:36:16 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>////
// # include <limits.h>
#include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef INT_MAX
#  define INT_MAX 2147483648
# endif

typedef struct s_flag
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int f;
	int	c;
}	t_flag;

typedef struct s_map
{
	int	x;
	int	y;
	char	p;
	int	map_h;
	int	map_w;
	char	*p_no;
	char	*p_so;
	char	*p_we;
	char	*p_ea;
	t_flag	*flag;
	char	**map;
}	t_map;


///-------------parsing-------------///
//----->tools
size_t	ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strtrim(char *s1, char *set);

//------>free
void	free_all(void *p, int flag);
void	ft_done(size_t i);
void	*ft_alloc(size_t i);

//----->get_next_line
char	*ft_join(char *dest, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*get_backup(int fd, char *backup);
char	*get_l(char *backup);
char	*update(char *backup);
char	*get_next_line(int fd);

//----->map
void	init_map(t_map	*map);
int	verify_map(char *name, int *i);
char	**check_map(char *name);
int	find_max(char **lines);
int	check_flag(t_map *map);
char	**pars_s_map(char **lines, int *i, int max);
t_map	*pars_map(char **lines, t_map *map);

#endif