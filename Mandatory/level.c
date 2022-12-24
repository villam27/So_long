/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:27:27 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/24 17:56:01 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"
#include "map.h"

t_lvl_data	*create_level(char *path, t_ilx_window *win)
{
	t_lvl_data	*level;

	level = malloc(sizeof(t_lvl_data));
	if (!level)
		return (NULL);
	level->map = NULL;
	level->update = 1;
	level->camera_offsets.x = 0;
	level->camera_offsets.y = 0;
	level->tiles = ilx_create_texture(win, "assets/tiles.xpm");
	if (!level->tiles)
		return (free(level), NULL);
	level->object = ilx_create_texture(win, "assets/object.xpm");
	if (!level->object)
		return (ilx_destroy_texture(win, level->tiles), free(level), NULL);
	level->map = open_map(path);
	if (!level->map)
		return (ilx_destroy_texture(win, level->tiles), ilx_destroy_texture(win, level->object), free(level), NULL);
	level->pts.x = 0;
	level->pts.y = 0;
	level->rect.x = 64 * 1;
	level->rect.y = 64 * 1;
	level->rect.h = 64; 
	level->rect.w = 64;
	level->anim = 0;
	level->anim_i = 1;
	return (level);
}

void	level_update(t_game_data *game)
{
	int	i;
	int	j;
	int	b;
	int	o;

	if (game->levels->update)
	{
		i = 0;
		b = 0;
		o = 0;
		while (i < game->levels->map->data->cols)
		{
			j = 0;
			while (j < game->levels->map->data->rows)
			{
				update_map_box(game, &b, i, j);
				update_map_obj(game, &o, i, j);
				j++;
			}
			i++;
		}
		game->levels->update = 0;
	}
}

void	level_render(t_game_data *game)
{
	int	i;
	int	j;
	int	b;
	int	o;

	i = 0;
	b = 0;
	o = 0;
	if (game->levels->anim >= 10)
		game->levels->anim_i = -1;
	if (game->levels->anim <= -10)
		game->levels->anim_i = 1;
	while (i < game->levels->map->data->cols)
	{
		j = 0;
		while (j < game->levels->map->data->rows)
		{
			render_map_box(game, &b, i, j);
			render_map_obj(game, &o, i, j);
			if (game->levels->map->map[j][i] == 'E')
				ilx_draw_rect(game->ren, *game->levels->map->exit, 0x777777);
			j++;
		}
		i++;
	}
	game->levels->anim += game->levels->anim_i;
}

void	free_level(t_game_data *game)
{
	destroy_map(game->levels->map);
	ilx_destroy_texture(game->win, game->levels->tiles);
	ilx_destroy_texture(game->win, game->levels->object);
	free(game->levels);
}
