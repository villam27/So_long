/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:35:58 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/29 16:03:16 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	*create_player(t_game_data *game, int x, int y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = x * 64;
	player->y = y * 64;
	player->box = ilx_create_rect(player->x, player->y, 40, 50);
	if (!player->box)
		return (free(player), NULL);
	player->lastp = ilx_create_rect(player->x, player->y, 40, 50);
	if (!player->lastp)
		return (ilx_free_rect(player->box), free(player), NULL);
	if (player_load_texture(player, game->win))
		return (ilx_free_rect(player->box),
			ilx_free_rect(player->lastp), free(player), NULL);
	player->fall = 1;
	player->gravity = 5;
	player->speed = 6;
	player->lifes = 5;
	player->steps = 0;
	player->inv_frames = 0;
	player->dst_s = ilx_new_rect(0, 0, 64, 64);
	player->dst_p = ilx_new_rect(0, 0, 64, 64);
	return (player);
}

void	destroy_player(t_player *player, t_ilx_window *window)
{
	ilx_free_rect(player->box);
	ilx_free_rect(player->lastp);
	ilx_destroy_texture(window, player->sprite);
	ilx_destroy_texture(window, player->particle);
	free(player);
}

void	player_input(t_game_data *data)
{
	data->player->lastp->x = data->player->x;
	data->player->lastp->y = data->player->y;
	if (data->inputs->left == 1)
	{
		data->player->x -= data->player->speed;
		data->player->sprite->flip = 1;
	}
	if (data->inputs->right == 1)
	{
		data->player->x += data->player->speed;
		data->player->sprite->flip = 0;
	}
	if (data->inputs->up == 1 && !data->player->fall)
	{
		data->player->fall = 1;
		data->player->gravity -= 17;
		data->inputs->up = 0;
		data->player->steps++;
	}
	if (data->inputs->jetpack == 1)
		player_jetpack(data->player);
}

void	player_update(t_game_data *data)
{
	player_fall(data->player);
	data->player->box->y = data->player->y;
	data->player->box->x = data->player->x;
	player_interation(data);
	if (data->player->inv_frames > 0)
		data->player->inv_frames--;
	if (ilx_intersection_rect(data->player->box, data->levels->map->exit)
		&& data->levels->map->data->objects == 0 && data->player->lifes > 0)
		data->inputs->exit = 1;
	player_camera(data);
}

void	player_render(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	render_animation(data);
	if (data->player->inv_frames % 2 == 0)
		ilx_render_copy(data->ren, player->sprite,
			&player->pts, &player->dst_s);
}
