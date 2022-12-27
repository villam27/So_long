/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:10 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/27 16:23:39 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "so_long.h"

t_player	*create_player(t_game_data *game, int x, int y);
int			player_load_texture(t_player *player, t_ilx_window *win);
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