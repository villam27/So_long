/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:41:23 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/22 22:58:44 by alboudje         ###   ########.fr       */
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
