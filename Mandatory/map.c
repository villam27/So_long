/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:45:18 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/20 23:47:10 by alboudje         ###   ########.fr       */
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
	{
		perror(path);
		return (NULL);
	}
	map_data = get_map_data(map_fd);
	close(map_fd);
	map_fd = open(path, O_RDONLY);
	map = create_map(map_fd, map_data);
	close(map_fd);
	if (!map)
		return (free(map_data), NULL);
	if (!check_map(map))
		return (destroy_map(map), NULL);
	return (map);
}

void	get_row_data(char *row, int *walls, int *objects)
{
	int	i;

	if (!row)
		return ;
	i = 0;
	while (row[i])
	{
		if (row[i] == '1')
			(*walls)++;
		else if (row[i] == 'C')
			(*objects)++;
		i++;
	}
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
	while (map_line)
	{
		get_row_data(map_line, &map->walls, &map->objects);
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
	map->boxs = malloc(sizeof(t_ilx_rect *) * (data->walls + 1));
	if (!map->boxs)
		return (free_all(map->map), free(map), NULL);
	i = 0;
	while (i < data->walls)
	{
		map->boxs[i] = ilx_create_rect(-64, -64, 64, 64);
		i++;
	}
	map->boxs[i] = NULL;
	map->data = data;
	return (map);
}

int	check_map(t_map *map)
{
	return (1);
}

void	destroy_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map->boxs[i])
		{
			if (map->boxs[i])
			{
				ilx_free_rect(map->boxs[i]);
				i++;
			}
		}
		free(map->boxs);
		if (map->map)
			free_all(map->map);
		if (map->data)
			free(map->data);
		free(map);
	}
}
