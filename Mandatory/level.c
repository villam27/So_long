/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:27:27 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/22 00:10:38 by alboudje         ###   ########.fr       */
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
	level->objects = 0;
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
	int	k;
	int	o;

	if (game->levels->update)
	{
		i = 0;
		k = 0;
		o = 0;
		while (i < game->levels->map->data->cols)
		{
			j = 0;
			while (j < game->levels->map->data->rows)
			{
				if (game->levels->map->map[j][i] == '1')
				{
					game->levels->map->boxs[k]->x = 64 * i;
					game->levels->map->boxs[k]->y = 64 * j;
					k++;
				}
				if (game->levels->map->map[j][i] == 'C')
				{
					game->levels->map->objects[o]->x = 64 * i + 16;
					game->levels->map->objects[o]->y = 64 * j + 16;
					o++;
				}
				j++;
			}
			i++;
		}
		game->levels->update = 0;
		ft_printf("updated\n");
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
			if (game->levels->map->map[j][i] == '1')
			{
				ilx_draw_rect(game->ren, *game->levels->map->boxs[b], 0xf11111 + (i + j) * 100);
				b++;
			}
			if (game->levels->map->map[j][i] == 'C')
			{
				ilx_draw_rect(game->ren, *game->levels->map->objects[o], 0x99cc44);
				o++;
			}
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
