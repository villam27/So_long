/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_physics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:45:32 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/22 22:10:22 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_collision(t_player *player, t_ilx_rect *box)
{
	if (ilx_intersection_rect(player->box, box))
	{
		if (ilx_vertical_align_rect(player->lastp, box))
		{
			if (player->x + player->box->w / 2 < box->x + box->w / 2)
				player->x -= player->x + player->box->w - box->x;
			else
				player->x += box->x + box->w - player->x;
		}
		else if (ilx_horizont_align_rect(player->lastp, box))
		{
			if (player->box->y + player->box->h / 2 < box->y + box->h / 2)
			{
				player->y -= player->y + player->box->h - box->y;
				player->gravity = 0;
				player->fall = 0;
			}
			else
			{
				player->y += box->y + box->h - player->y;
				player->gravity = 0;
			}
		}
	}
}

void	player_get_obj(t_game_data *data, t_player *player, t_ilx_rect *obj)
{
	int	x;
	int	y;

	if (ilx_intersection_rect(player->box, obj))
	{
		x = (obj->x - 16) / 64;
		y = (obj->y - 16) / 64;
		if (data->levels->map->map[y][x] == 'C')
		{
			data->levels->map->map[y][x] = '0';
			data->levels->map->data->objects--;
			data->levels->update = 1;
		}
	}
}

void	player_fall(t_player *player)
{
	if (player->gravity > 2)
		player->fall = 1;
	if (player->gravity < 17)
		player->gravity += 1;
	player->y += player->gravity;
}
