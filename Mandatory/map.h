/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:45:11 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/19 16:20:01 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <fcntl.h>
# include "ILX.h"
# include "so_long.h"

typedef struct s_map_data
{
	int			rows;
	int			cols;
	t_ilx_point	exit_coords;
	t_ilx_point	player_coords;
	int			objects;
}	t_map_data;

typedef struct s_map
{
	t_map_data	*data;
	char		**map;
}	t_map;

t_map		*open_map(char *path);
t_map_data	*get_map_data(int fd);
t_map		*create_map(int fd, t_map_data *data);
int			check_map(t_map *map);
void		destroy_map(t_map *map);

#endif