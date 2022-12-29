/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:53:59 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/29 17:29:23 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "ILX.h"
# include "map.h"

typedef struct s_map	t_map;

typedef struct s_game_input
{
	int	left;
	int	right;
	int	up;
	int	down;
	int	jetpack;
	int	exit;
}	t_game_input;

typedef struct s_player
{
	t_ilx_rect		*box;
	t_ilx_rect		*lastp;
	t_ilx_rect		dst_s;
	t_ilx_rect		dst_p;
	t_ilx_point		pts;
	t_ilx_point		pts_p;
	t_ilx_texture	*sprite;
	t_ilx_texture	*particle;
	int				x;
	int				y;
	int				fall;
	int				gravity;
	int				speed;
	int				lifes;
	int				steps;
	int				inv_frames;
}	t_player;

typedef struct s_enemy
{
	t_ilx_rect		*box;
	t_ilx_texture	*sprite;	
	int				direction;
	int				speed;
}	t_enemy;

typedef struct s_lvl_data
{
	t_map			*map;
	t_ilx_point		camera_offsets;
	int				update;
	int				anim;
	int				anim_i;
	t_ilx_texture	*tiles;
	t_ilx_texture	*object;
	t_ilx_texture	*rocket;
	t_ilx_rect		rect;
	t_ilx_point		pts;
}	t_lvl_data;

typedef struct s_hud
{
	t_ilx_rect		dst_r;
	t_ilx_point		pts;
	t_ilx_texture	*life;
}	t_hud;

typedef struct s_game_data
{
	t_ilx_window	*win;
	t_ilx_renderer	*ren;
	t_game_input	*inputs;
	t_lvl_data		*levels;
	t_player		*player;
	t_enemy			**enemies;
	t_ilx_texture	*background;
	t_hud			*hud;
}	t_game_data;

int			input_key_down(int keycode, t_game_input *inputs);
int			input_key_up(int keycode, t_game_input *inputs);

void		input(t_game_data *game);
void		update(t_game_data *game);
void		render(t_game_data *game);
int			win_close(t_game_data *game);

t_game_data	*ini_game(t_ilx_window *w, t_ilx_renderer *r, t_game_input *i,
				char *path);
void		close_game(t_game_data *game);

t_lvl_data	*create_level(char *path, t_ilx_window *win);
int			load_textures(t_lvl_data *level, t_ilx_window *win);
void		update_map_box(t_game_data *game, int *b, int i, int j);
void		render_map_box(t_game_data *game, int *b, int i, int j);
void		update_map_obj(t_game_data *data, int *o, int i, int j);
void		render_map_obj(t_game_data *game, int *o, int i, int j);
void		level_update(t_game_data *game);
void		level_render(t_game_data *game);
void		free_level(t_game_data *game);

t_hud		*init_hud(t_ilx_window *win);
void		destroy_hud(t_ilx_window *win, t_hud *hud);
void		hud_render(t_game_data *data);
void		hud_update(t_hud *hud);

t_enemy		*create_enemy(int x, int y, t_ilx_window *win);
void		destroy_enemy(t_enemy *enemy, t_ilx_window *win);
t_enemy		**create_enemies(int number, t_ilx_window *win);
void		destroy_enemies(t_enemy **enemies, t_ilx_window *win);
void		enemy_set_position(t_enemy *enemy, int x, int y);
void		enemy_render(t_game_data *data, t_enemy *enemy);
void		enemy_update(t_game_data *data, t_enemy *enemy);
void		set_all_pos(t_game_data *data);
#endif