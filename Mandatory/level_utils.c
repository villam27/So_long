/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:19:46 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/24 17:58:31 by alboudje         ###   ########.fr       */
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
	t_lvl_data	*lvl;

	lvl = game->levels;
	if (lvl->map->map[j][i] == '1')
	{
		lvl->pts.x = lvl->map->boxs[*b]->x;
		lvl->pts.y = lvl->map->boxs[*b]->y;
		//ilx_draw_rect(game->ren, *lvl->map->boxs[*b], 0xf11111 + (i + j) * 100);
		ilx_render_copy(game->ren, lvl->tiles, &lvl->pts, &lvl->rect);
		(*b)++;
	}
}

void	render_map_obj(t_game_data *game, int *o, int i, int j)
{
	int x;
	int	y;

	x = game->levels->map->objects[*o]->x;
	y = game->levels->map->objects[*o]->y + game->levels->anim;
	if (game->levels->map->map[j][i] == 'C')
	{
		//ilx_draw_rect(game->ren, *game->levels->map->objects[*o], 0x99cc44);
		ilx_draw_texture(game->ren, x, y, game->levels->object);
		(*o)++;
	}
}
