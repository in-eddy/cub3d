/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieddaoud <ieddaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:43:14 by ieddaoud          #+#    #+#             */
/*   Updated: 2025/09/10 20:27:44 by ieddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>////
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_smap
{
	char	position;
	int		p_x;
	int		p_y;
	int		map_h;
	int		map_w;
}	t_smap;

typedef struct s_bmap
{
	t_smap	*smap;
	char	**map;//added
	int		flag;
	int		c;
	int		f;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}	t_bmap;

///-------------parsing-------------///
//----->tools
size_t	ft_strlen(char *s);
// int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);

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
void	init_map(t_bmap *bmap);
// int		check_map(char *name);
char	**check_map(char *name);


#endif