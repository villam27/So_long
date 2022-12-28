/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:30:43 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/28 16:35:46 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	get_row_data(char *row, t_map_data **data)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] == '1')
			(*data)->walls++;
		else if (row[i] == 'C')
			(*data)->objects++;
		else if (row[i] == 'A')
			(*data)->enemies++;
		else if (row[i] == 'P')
		{
			(*data)->player++;
			(*data)->player_pos.x = i;
			(*data)->player_pos.y = (*data)->rows;
		}
		else if (row[i] == 'E')
		{
			(*data)->exit++;
			(*data)->exit_pos.x = i;
			(*data)->exit_pos.y = (*data)->rows;
		}
		else if (row[i] != '0' && row[i] != '\n')
			(*data)->error = 1;
		i++;
	}
}

int	check_rect(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->data->rows)
	{
		if (i == map->data->rows - 1
			&& ft_strlen(map->map[i]) != (size_t)map->data->cols)
			return (1);
		if (i < map->data->rows - 1
			&& ft_strlen(map->map[i]) - 1 != (size_t)map->data->cols)
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->data->cols)
	{
		if (map->map[0][i] != '1' || map->map[map->data->rows - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < map->data->rows)
	{
		if (map->map[i][0] != '1' || map->map[i][map->data->cols - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_path(int *objs, char ***temp_map, int x, int y)
{
	if ((*temp_map)[y][x] == 'C' || (*temp_map)[y][x] == 'E')
	{
		(*temp_map)[y][x] = '0';
		(*objs)++;
	}
	if ((*temp_map)[y][x] == '1')
		return (1);
	(*temp_map)[y][x] = '1';
	if (!check_path(objs, temp_map, x + 1, y)
		|| !check_path(objs, temp_map, x - 1, y)
		|| !check_path(objs, temp_map, x, y + 1)
		|| !check_path(objs, temp_map, x, y - 1))
		return (0);
	return (1);
}

char	**map_dup(t_map *map)
{
	char	**temp_map;
	int		i;

	i = 0;
	temp_map = malloc(sizeof(char *) * (map->data->rows + 1));
	if (!temp_map)
		return (NULL);
	while (i < map->data->rows)
	{
		temp_map[i] = ft_strdup(map->map[i]);
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
}
