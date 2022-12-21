/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:27:27 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/21 14:06:03 by alboudje         ###   ########.fr       */
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
	level->player = NULL;
	level->map = open_map(path);
	if (!level->map)
		return (free(level), NULL);
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
				game->levels->map->boxs[k]->x = 64 * i;
				game->levels->map->boxs[k]->y = 64 * j;
				ilx_draw_rect(game->ren, *game->levels->map->boxs[k], 0xf11111 + (i + j) * 100);
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
	destroy_map(level->map);
	//destroy_player(level->player);
	free(level);
}
