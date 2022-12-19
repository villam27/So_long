/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:45:18 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/19 11:23:44 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>

t_map	*open_map(char *path)
{
	int			map_fd;
	t_game_data	*map_data;
	t_map		*map;

	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
	{
		perror(path);
		return (NULL);
	}
	map_data = get_map_data(map_fd);
	close(map_fd);
	map_fd = open(path, O_RDONLY);
	map = create_map(map_fd, map_data);
	if (!check_map(map))
		return (map);
	if (map)
		destroy_map(map);
	return (NULL);
}

t_map_data	*get_map_data(int fd)
{
}

t_map	*create_map(int fd, t_map_data *data)
{
}

int	check_map(t_map *map)
{	
}

void	destroy_map(t_map *map)
{
}
