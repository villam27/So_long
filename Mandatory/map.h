/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:45:11 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/22 22:57:43 by alboudje         ###   ########.fr       */
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
	int			walls;
	int			objects;
	int			player;
	int			exit;
	t_ilx_point	player_pos;
	t_ilx_point	exit_pos;
}	t_map_data;

typedef struct s_map
{
	t_map_data	*data;
	t_ilx_rect	*exit;
	t_ilx_rect	**boxs;
	t_ilx_rect	**objects;
	char		**map;
}	t_map;

t_map		*open_map(char *path);
t_map		*create_map(int fd, t_map_data *data);
t_map_data	*get_map_data(int fd);
void		get_row_data(char *row, t_map_data **data);
void		destroy_map(t_map *map);
int			create_map_objects(t_map **map, t_map_data *data);
int			check_rect(t_map *map);
int			check_walls(t_map *map);
int			check_path(int *objs, char ***temp_map, int x, int y);
int			check_map(t_map *map);
char		**map_dup(t_map *map);

#endif