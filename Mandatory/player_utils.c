/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:44:50 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/25 16:46:59 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	render_animation(t_game_data *data)
{
	static frames = 0;
	data->player->pts.y = data->player->y - 14;
	data->player->pts.x = data->player->x - 14;
	if (data->inputs->left || data->inputs->right)
	{
		if (frames >= 5)
		{
			data->player->dst_r.x += 64;
			frames = 0;
		}
		if (data->player->dst_r.x > 64 * 3)
			data->player->dst_r.x = 0;
		frames++;
	}
	else
		data->player->dst_r.x = 0;
	if (data->player->gravity || data->player->fall)
		data->player->dst_r.x = 64 * 4;
	if (data->player->lifes <= 0)
		data->player->dst_r.x = 64 * 5;
}
