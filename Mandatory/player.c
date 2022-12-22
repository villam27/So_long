/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:35:58 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/22 23:37:56 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	*create_player(int x, int y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = x * 64;
	player->y = y * 64;
	player->box = ilx_create_rect(player->x, player->y, 50, 50);
	if (!player->box)
		return (free(player), NULL);
	player->lastp = ilx_create_rect(player->x, player->y, 50, 50);
	if (!player->lastp)
		return (ilx_free_rect(player->box), free(player), NULL);
	player->fall = 1;
	player->gravity = 3;
	player->speed = 6;
	player->lifes = 3;
	return (player);
}

void	destroy_player(t_player *player)
{
	ilx_free_rect(player->box);
	ilx_free_rect(player->lastp);
	free(player);
}

void	player_input(t_game_data *data)
{
	data->player->lastp->x = data->player->x;
	data->player->lastp->y = data->player->y;
	if (data->inputs->left == 1)
		data->player->x -= data->player->speed;
	if (data->inputs->right == 1)
		data->player->x += data->player->speed;
	if (data->inputs->up == 1 && !data->player->fall)
	{
		data->player->fall = 1;
		data->player->gravity -= 17;
		data->inputs->up = 0;
	}
	if (data->inputs->jetpack == 1)
		player_jetpack(data->player);
}

void	player_update(t_game_data *data)
{
	int	i;

	i = 0;
	player_fall(data->player);
	data->player->box->y = data->player->y;
	data->player->box->x = data->player->x;
	while (data->levels->map->boxs[i])
	{
		player_collision(data->player, data->levels->map->boxs[i]);
		i++;
	}
	i = 0;
	while (data->levels->map->objects[i])
	{
		player_get_obj(data, data->player, data->levels->map->objects[i]);
		i++;
	}
	if (ilx_intersection_rect(data->player->box, data->levels->map->exit)
		&& data->levels->map->data->objects == 0)
		data->inputs->exit = 1;
	data->player->box->x = data->player->x;
	data->player->box->y = data->player->y;
}

void	player_render(t_game_data *data)
{
	ilx_draw_rect(data->ren, *data->player->box, 0xff7777);
}
