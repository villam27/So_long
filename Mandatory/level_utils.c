/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:19:46 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/22 22:36:03 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	update_map_box(t_game_data *game, int *b, int i, int j)
{
	if (game->levels->map->map[j][i] == '1')
	{
		game->levels->map->boxs[*b]->x = 64 * i;
		game->levels->map->boxs[*b]->y = 64 * j;
		(*b)++;
	}
}

void	update_map_obj(t_game_data *game, int *o, int i, int j)
{
	if (game->levels->map->map[j][i] == 'C')
	{
		game->levels->map->objects[*o]->x = 64 * i + 16;
		game->levels->map->objects[*o]->y = 64 * j + 16;
		(*o)++;
	}
}

void	render_map_box(t_game_data *game, int *b, int i, int j)
{
	if (game->levels->map->map[j][i] == '1')
	{
		ilx_draw_rect(game->ren, *game->levels->map->boxs[*b],
			0xf11111 + (i + j) * 100);
		(*b)++;
	}
}

void	render_map_obj(t_game_data *game, int *o, int i, int j)
{
	if (game->levels->map->map[j][i] == 'C')
	{
		ilx_draw_rect(game->ren, *game->levels->map->objects[*o],
			0x99cc44);
		(*o)++;
	}
}
