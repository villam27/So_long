/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:41:23 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/25 19:39:18 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	create_map_objects(t_map **map, t_map_data *data)
{	
	(*map)->boxs = ilx_create_rects(64, 64, data->walls);
	if (!(*map)->boxs)
		return (free_all((*map)->map), free(*map), 1);
	(*map)->objects = ilx_create_rects(32, 32, data->objects);
	if (!(*map)->objects)
		return (ilx_free_rects((*map)->boxs), free_all((*map)->map),
			free(*map), 1);
	(*map)->exit = ilx_create_rect(data->exit_pos.x * 64,
			data->exit_pos.y * 64, 64, 64);
	if (!(*map)->exit)
		return (ilx_free_rects((*map)->objects), ilx_free_rects((*map)->boxs),
			free_all((*map)->map), free(*map), 1);
	(*map)->data = data;
	return (0);
}

int	print_map_error(int error)
{
	if (error == 1)
		ft_putstr_fd("Error: Invalid map\n", 2);
	else if (error == 2)
		ft_putstr_fd("Error: The map is not rectangular !\n", 2);
	else if (error == 3)
		ft_putstr_fd("Error: The map is not surrounded by walls !\n", 2);
	else if (error == 4)
		ft_putstr_fd("Error: Player can't reach all objects or exit !\n", 2);
	return (error);
}
