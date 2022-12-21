/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_physics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:45:32 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/21 02:25:33 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_collision(t_player *player, t_ilx_rect *box)
{
	if (ilx_intersection_rect(player->player, box))
	{
		if (ilx_vertical_align_rect(player->lastp, box))
		{
			if (player->x + player->player->w / 2 < box->x + box->w / 2)
				player->x -= player->x + player->player->w - box->x;
			else
				player->x += box->x + box->w - player->x;
		}
		else if (ilx_horizont_align_rect(player->lastp, box))
		{
			if (player->player->y + player->player->h / 2 < box->y + box->h / 2)
			{
				player->y -= player->y + player->player->h - box->y;
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

void	player_fall(t_player *player)
{
	if (player->gravity > 2)
		player->fall = 1;
	if (player->gravity < 17)
		player->gravity += 1;
	player->y += player->gravity;
}
