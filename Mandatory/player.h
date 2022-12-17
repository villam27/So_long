/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:10 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 15:12:35 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H
#include "so_long.h"

t_player	*create_player();
void		destroy_player(t_player *player);

void		player_collision(t_player *player, t_ILX_Rect *box);
void		player_input(t_Game_data *data);
void		player_update(t_Game_data *data);
void		player_render(t_Game_data *data);
#endif