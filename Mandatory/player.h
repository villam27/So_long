/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:10 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 14:06:20 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H
#include "so_long.h"

t_player	*create_player();
void		destroy_player(t_player *player);

void		player_input(t_Game_data *data);
void		player_update(t_Game_data *data);
void		player_render(t_Game_data *data);
#endif