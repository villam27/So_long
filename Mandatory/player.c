/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:35:58 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 14:10:43 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	*create_player()
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->player = ilx_create_rect(60, 60, 50, 50);
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

void	player_input(t_Game_data *data)
{

}

void	player_update(t_Game_data *data)
{

}

void	player_render(t_Game_data *data)
{
	ILX_draw_rect(data->ren, *data->player->player, 0xff7777);
}