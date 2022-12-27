/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:44:50 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/27 23:55:47 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	render_particle(t_game_data *data)
{
	static int	frame = 0;

	data->player->pts_p.y = data->player->y + 20;
	data->player->pts_p.x = data->player->x - 14;
	if (frame >= 4)
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

int	player_load_texture(t_player *player, t_ilx_window *win)
{
	player->sprite = ilx_create_texture(win, "assets/player.xpm");
	if (!player->sprite)
		return (1);
	player->particle = ilx_create_texture(win, "assets/particles.xpm");
	if (!player->particle)
		return (ilx_destroy_texture(win, player->sprite), 1);
	return (0);
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
	{
		data->player->lifes--;
		data->player->dst_s.x = 64 * 5;
	}
}
