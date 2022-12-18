/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:35:58 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/18 17:02:53 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	*create_player()
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

void	player_collision(t_player *player, t_ilx_rect *box)
{
	int	push_back;

	push_back = 0;
	if (ilx_intersection_rect(player->player, box))
	{
		if (ilx_vertical_align_rect(player->lastp, box))
		{
			if (player->x + player->player->w/2 < box->x + box->w / 2)
			{
				push_back = player->x + player->player->w - box->x;
				player->x -= push_back;
			}
			else
			{
				push_back = box->x + box->w - player->x;
				player->x += push_back;
			}
		}
		else if (ilx_horizont_align_rect(player->lastp, box))
		{
			if (player->player->y + player->player->h/2 < box->y + box->h / 2)
			{
				push_back = player->y + player->player->h - box->y;
				player->y -= push_back;
				player->gravity = 0;
				player->fall = 0;
			}
			else
			{
				push_back = box->y + box->h - player->y;
				player->y += push_back;
			}
		}
	}
}

void	player_input(t_game_data *data)
{
	//data->player->vert = ilx_vertical_align_rect(data->player->player, data->rect);
	//data->player->hori = ilx_horizont_align_rect(data->player->player, data->rect);
	data->player->lastp->x = data->player->x;
	data->player->lastp->y = data->player->y;
	if (data->inputs->left == 1)
		data->player->x -= data->player->speed;
	if (data->inputs->right == 1)
		data->player->x += data->player->speed;
	//if (data->inputs->up == 1)
	//	data->player->y -= data->player->speed;
	//if (data->inputs->down == 1)
	//	data->player->y += data->player->speed;	
	if (data->inputs->up == 1 && !data->player->fall)
	{
		data->player->fall = 1;
		data->player->gravity = -20;
		data->inputs->up = 0;
	}
}

void	player_update(t_game_data *data)
{
	player_fall(data->player);
	data->player->player->y = data->player->y;
	data->player->player->x = data->player->x;
	for (int i = 0; i < 20; i++)
		player_collision(data->player, data->levels->boxs[i]);
	data->player->player->x = data->player->x;
	data->player->player->y = data->player->y;
}

void	player_render(t_game_data *data)
{
	ilx_draw_rect(data->ren, *data->player->player, 0xff7777);
}

void	player_fall(t_player *player)
{
	if (player->gravity < 3)
		player->gravity += 1;
	player->y += player->gravity;
}
