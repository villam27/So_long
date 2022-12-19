/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:27:27 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/19 22:25:04 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"
#include "map.h"

t_lvl_data	*create_level(void)
{
	t_lvl_data	*level;
	int			i;

	level = malloc(sizeof(t_lvl_data));
	if (!level)
		return (NULL);
	level->map = NULL;
	level->objects = 0;
	level->player = NULL;
	level->rects = NULL;
	level->boxs = malloc(sizeof(t_ilx_rect) * (50 + 1));
	i = 0;
	while (i < 50)
	{
		level->boxs[i] = ilx_create_rect(64 * i, 64 * i, 64, 64);
		i++;
	}
	level->boxs[i] = NULL;
	level->map = open_map("map/map_01.ber");
	return (level);
}

void	render_level(t_game_data *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < game->levels->map->data->cols)
	{
		j = 0;
		while (j < game->levels->map->data->rows)
		{
			if (game->levels->map->map[j][i] == 1 + '0')
			{
				game->levels->boxs[k]->x = 64 * i;
				game->levels->boxs[k]->y = 64 * j;
				ilx_draw_rect(game->ren, *game->levels->boxs[k], 0xff0000);
				k++;
			}
			j++;
		}
		i++;
	}	
}

/*
*	!!! DONT FORGET TO FREE THE MAP AND THE PLAYER !!!
*/
void	free_level(t_lvl_data *level)
{
	int	i;

	i = 0;
	while (level->boxs[i])
	{
		free(level->boxs[i]);
		i++;
	}
	free(level->boxs);
	free(level);
}
