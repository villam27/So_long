/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:19:46 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/27 14:09:56 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	load_textures(t_lvl_data *level, t_ilx_window *win)
{	
	level->tiles = ilx_create_texture(win, "assets/tiles.xpm");
	if (!level->tiles)
		return (1);
	level->object = ilx_create_texture(win, "assets/object.xpm");
	if (!level->object)
		return (ilx_destroy_texture(win, level->tiles), 1);
	level->rocket = ilx_create_texture(win, "assets/rocket.xpm");
	if (!level->rocket)
		return (ilx_destroy_texture(win, level->tiles),
			ilx_destroy_texture(win, level->object), 1);
	return (0);
}

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
		ilx_render_copy(game->ren, lvl->tiles, &lvl->pts, &lvl->rect);
		(*b)++;
	}
}

void	render_map_obj(t_game_data *game, int *o, int i, int j)
{
	int	x;
	int	y;

	if (game->levels->map->map[j][i] == 'C')
	{
		x = game->levels->map->objects[*o]->x;
		y = game->levels->map->objects[*o]->y + game->levels->anim;
		ilx_draw_texture(game->ren, x, y, game->levels->object);
		(*o)++;
	}
}
