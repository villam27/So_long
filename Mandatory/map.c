/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:45:18 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/25 19:24:59 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>

t_map	*open_map(char *path)
{
	int			map_fd;
	t_map_data	*map_data;
	t_map		*map;

	map == NULL;
	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		return (perror(path), NULL);
	map_data = get_map_data(map_fd);
	close(map_fd);
	map_fd = open(path, O_RDONLY);
	map = create_map(map_fd, map_data);
	close(map_fd);
	if (!map)
		return (free(map_data), NULL);
	if (print_map_error(check_map(map)))
		return (destroy_map(map), NULL);
	return (map);
}

t_map_data	*get_map_data(int fd)
{
	t_map_data	*map;
	char		*map_line;

	map = malloc(sizeof(t_map_data));
	if (!map)
		return (NULL);
	map_line = get_next_line(fd);
	if (!map_line)
		return (free(map), NULL);
	map->cols = ft_strlen(map_line) - 1;
	map->rows = 0;
	map->objects = 0;
	map->walls = 0;
	map->player = 0;
	map->error = 0;
	map->exit = 0;
	while (map_line)
	{
		get_row_data(map_line, &map);
		free(map_line);
		map_line = get_next_line(fd);
		map->rows++;
	}
	return (map);
}

t_map	*create_map(int fd, t_map_data *data)
{
	t_map	*map;
	int		i;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!data || !map)
		return (NULL);
	map->map = malloc(sizeof(char *) * (data->rows + 1));
	if (!map->map)
		return (NULL);
	while (i < data->rows)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	if (create_map_objects(&map, data))
		return (NULL);
	return (map);
}

int	check_map(t_map *map)
{
	char	**temp_map;
	int		objects;

	objects = 0;
	if (map->data->player != 1 || map->data->exit != 1
		|| map->data->error != 0)
		return (1);
	if (check_rect(map))
		return (2);
	if (check_walls(map))
		return (3);
	temp_map = map_dup(map);
	if (!temp_map)
		return (-1);
	check_path(&objects, &temp_map, map->data->player_pos.x,
		map->data->player_pos.y);
	if (objects != map->data->objects + 1)
		return (free_all(temp_map), 4);
	free_all(temp_map);
	return (0);
}

void	destroy_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		ilx_free_rects(map->boxs);
		ilx_free_rects(map->objects);
		ilx_free_rect(map->exit);
		if (map->map)
			free_all(map->map);
		if (map->data)
			free(map->data);
		free(map);
	}
}
