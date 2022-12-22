/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:27:27 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/22 22:36:16 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"
#include "map.h"

t_lvl_data	*create_level(char *path)
{
	t_lvl_data	*level;

	level = malloc(sizeof(t_lvl_data));
	if (!level)
		return (NULL);
	level->map = NULL;
	level->update = 1;
	level->map = open_map(path);
	if (!level->map)
		return (free(level), NULL);
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
}

void	free_level(t_lvl_data *level)
{
	destroy_map(level->map);
	free(level);
}
