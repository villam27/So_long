/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:10 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/25 16:45:37 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "so_long.h"

t_player	*create_player(t_game_data *game, int x, int y);
void		destroy_player(t_player *player, t_ilx_window *win);

void		player_fall(t_player *player);
void		player_jetpack(t_player *player);
void		player_collision(t_player *player, t_ilx_rect *box);
void		render_animation(t_game_data *data);
void		player_input(t_game_data *data);
void		player_update(t_game_data *data);
void		player_render(t_game_data *data);
void		player_camera(t_game_data *data);
void		player_get_obj(t_game_data *data, t_player *play, t_ilx_rect *obj);
#endif