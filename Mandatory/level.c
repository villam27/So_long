/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:27:27 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/18 14:23:56 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"

t_level_data	*create_level()
{
	return (NULL);
}

void	render_level(t_game_data *game)
{
	int	i;
	int	j;
	t_ilx_rect rect = {0, 0, 64, 64};

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j <= 13)
		{
			ilx_draw_rect(game->ren, rect, 0x470F40 + (j * 50));
			rect.y = i * 8 * 64;
			rect.x = j * 64;
			j++;
		}
		i++;
	}	
	rect.x = 0;
	rect.y = 0;
	j = 0;
	while (j < 2)
	{
		i = 0;
		while (i < 9)
		{
			ilx_draw_rect(game->ren, rect, 0x470F40 + (i * 50));
			rect.x = j * 12 * 64;
			rect.y = i * 64;
			i++;
		}
		j++;
	}
}

void	free_level(t_level_data *level)
{
	free_all(level->map);
	destroy_player(level->player);
	free(level);
}