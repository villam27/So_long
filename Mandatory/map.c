/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:45:18 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/19 12:25:58by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>

t_map	*open_map(char *path)
{
	int			map_fd;
	t_map_data	*map_data;
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
	ft_printf(">>>>>>>>%p\n", map_data);
	map = create_map(map_fd, map_data);
	if (!check_map(map))
		return (map);
	//if (map)
	//	destroy_map(map);
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
	map->cols = ft_strlen(map_line) - 1;
	map->rows = 0;
	map->objects = 0;
	while (map_line && map->cols > 0)
	{
		//if (ft_strlen(map_line) != map->cols)
		//	map->cols = -1;
		map_line = get_next_line(fd);
		map->rows++;
		free(map_line);
		ft_printf("%p", map);
		ft_putstr_fd(">\n", 2);
	}
	//if (map->cols = -1)
	//	free(map);
	return (map);
}

t_map	*create_map(int fd, t_map_data *data)
{
	t_map	*map;
	int		i;

	i = 0;
	printf(">>>>>%p<<<<<\n", data);
	map = malloc(sizeof(t_map));
	if (!data || !map)
		return (NULL);
	map->map = malloc(sizeof(char *) * (data->rows + 1));
	map->map[i] = get_next_line(fd);
	while (map->map[i])
	{
		i++;
		map->map[i] = get_next_line(fd);
	}
	map->data = data;
	return (map);	
}

int	check_map(t_map *map)
{

}

void	destroy_map(t_map *map)
{
	free_all(map->map);
	free(map->data);
	free(map);
}
