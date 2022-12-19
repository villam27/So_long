/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:45:11 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/19 23:13:14 by alboudje         ###   ########.fr       */
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
}	t_map_data;

typedef struct s_map
{
	t_map_data	*data;
	char		**map;
}	t_map;

t_map		*open_map(char *path);
t_map_data	*get_map_data(int fd);
void		get_row_data(char *row, *walls, *objects);
t_map		*create_map(int fd, t_map_data *data);
int			check_map(t_map *map);
void		destroy_map(t_map *map);

#endif