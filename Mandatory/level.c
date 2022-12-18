/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:27:27 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/18 18:51:54 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"

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
	level->boxs = malloc(sizeof(t_ilx_rect) * (20 + 1));
	i = 0;
	while (i < 20)
	{
		level->boxs[i] = ilx_create_rect(64 * i, 64 * i, 64, 64);
		i++;
	}
	level->boxs[i] = NULL;
	return (level);
}

void	render_level(t_game_data *game)
{
	int	i;

	i = 0;
	while (game->levels->boxs[i])
	{
		ilx_draw_rect(game->ren, *game->levels->boxs[i], 0xff0000);
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
