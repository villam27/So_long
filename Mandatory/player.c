/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:35:58 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 15:45:11 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	*create_player()
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->player = ilx_create_rect(100, 100, 50, 50);
	player->x = 100;
	player->y = 100;
	player->last_x = player->x;
	player->last_y = player->y;
	player->speed = 3;
	player->lifes = 3;
	player->dead = 0;
	return (player);
}

void	destroy_player(t_player *player)
{
	ilx_free_rect(player->player);
	free(player);
}

void	player_collision(t_player *player, t_ILX_Rect *box)
{
		if (ilx_intersection_rect(player->player, box))
		{
			if (ilx_vertical_align_rect(player->player, box))
				ft_printf("from vert\n");
			else if (ilx_horizont_align_rect(player->player, box))
				ft_printf("from hori\n");
		}
}

void	player_input(t_Game_data *data)
{
	data->player->last_x = data->player->x;
	data->player->last_y = data->player->y;
	if (data->inputs->left == 1)
		data->player->x -= data->player->speed;
	if (data->inputs->right == 1)
		data->player->x += data->player->speed;
	if (data->inputs->up == 1)
		data->player->y -= data->player->speed;
	if (data->inputs->down == 1)
		data->player->y += data->player->speed;
}

void	player_update(t_Game_data *data)
{
	data->player->player->x = data->player->x;
	data->player->player->y = data->player->y;
	player_collision(data->player, data->rect);
}

void	player_render(t_Game_data *data)
{
	ILX_draw_rect(data->ren, *data->player->player, 0xff7777);
}
