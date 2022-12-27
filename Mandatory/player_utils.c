/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:44:50 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/27 15:23:05 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	render_particle(t_game_data *data)
{
	static int	frame = 0;

	data->player->pts_p.y = data->player->y + 20;
	data->player->pts_p.x = data->player->x - 14;
	if (frame >= 5)
	{
		data->player->dst_p.x += 64;
		frame = 0;
	}
	if (data->player->dst_p.x > 64 * 2)
		data->player->dst_p.x = 0;
	ilx_render_copy(data->ren, data->player->particle,
		&data->player->pts_p, &data->player->dst_p);
	frame++;
}

void	render_animation(t_game_data *data)
{
	static int	frames = 0;

	data->player->pts.y = data->player->y - 14;
	data->player->pts.x = data->player->x - 14;
	if ((data->inputs->left || data->inputs->right) && !data->inputs->jetpack)
	{
		if (frames >= 5)
		{
			data->player->dst_s.x += 64;
			frames = 0;
			data->player->steps++;
		}
		if (data->player->dst_s.x > 64 * 3)
			data->player->dst_s.x = 0;
		frames++;
	}
	else
		data->player->dst_s.x = 0;
	if (data->player->gravity || data->player->fall)
		data->player->dst_s.x = 64 * 4;
	if (data->inputs->jetpack)
		render_particle(data);
	if (data->player->lifes <= 0)
		data->player->dst_s.x = 64 * 5;
}
