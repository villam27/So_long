/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:53:59 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/18 16:58:21 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "ILX.h"

typedef struct	s_game_input
{
	int	left;
	int	right;
	int	up;
	int	down;
	int exit;
}	t_game_input;

typedef struct s_player
{
	t_ilx_rect	*player;
	int			x;
	int			y;
	t_ilx_rect	*lastp;
	int			fall;
	int			gravity;
	int			speed;
	int			lifes;
}	t_player;


typedef struct	s_level_data
{
	char		**map;
	int			objects;
	t_player	*player;
	t_ilx_rect	*rects;
	t_ilx_rect	**boxs;
}	t_level_data;

typedef struct	s_game_data
{
	t_ilx_window	*win;
	t_ilx_renderer	*ren;
	t_game_input	*inputs;
	t_level_data	*levels;
	t_player		*player;
}	t_game_data;

int 	input_key_down(int keycode, t_game_input *inputs);
int 	input_key_up(int keycode, t_game_input *inputs);

void	input(t_game_data *game);
void	update(t_game_data *game);
void	render(t_game_data *game);
int		win_close(t_game_data *game);

t_game_data	*ini_game(t_ilx_window *w, t_ilx_renderer *r, t_game_input *i);
void		close_game(t_game_data *game);
void		addlevel_game(t_game_data **game, t_level_data *level);

t_level_data	*create_level();
void			render_level(t_game_data *game);
void			free_level(t_level_data *level);
#endif