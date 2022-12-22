/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:10 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/22 23:38:34 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "so_long.h"

t_player	*create_player(int x, int y);
void		destroy_player(t_player *player);

void		player_fall(t_player *player);
void		player_jetpack(t_player *player);
void		player_collision(t_player *player, t_ilx_rect *box);
void		player_input(t_game_data *data);
void		player_update(t_game_data *data);
void		player_render(t_game_data *data);
void		player_get_obj(t_game_data *data, t_player *play, t_ilx_rect *obj);
#endif