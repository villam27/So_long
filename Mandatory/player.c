/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:35:58 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/18 18:45:57 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	*create_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->player = ilx_create_rect(300, 100, 50, 50);
	player->x = 300;
	player->y = 100;
	player->lastp = ilx_create_rect(300, 100, 50, 50);
	player->fall = 1;
	player->gravity = 3;
	player->speed = 3;
	player->lifes = 3;
	return (player);
}

void	destroy_player(t_player *player)
{
	ilx_free_rect(player->player);
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
		data->player->gravity += -16;
		data->inputs->up = 0;
	}
}

void	player_update(t_game_data *data)
{
	int	i;

	i = 0;
	player_fall(data->player);
	data->player->player->y = data->player->y;
	data->player->player->x = data->player->x;
	while (data->levels->boxs[i])
	{
		player_collision(data->player, data->levels->boxs[i]);
		i++;
	}
	data->player->player->x = data->player->x;
	data->player->player->y = data->player->y;
}

void	player_render(t_game_data *data)
{
	ilx_draw_rect(data->ren, *data->player->player, 0xff7777);
}
