/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:53:59 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 14:19:13 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "ILX.h"

typedef struct	s_GAME_Input
{
	int	left;
	int	right;
	int	up;
	int	down;
	int exit;
}	t_GAME_Input;

typedef struct s_player
{
	t_ILX_Rect	*player;
	int			speed;
	int			lifes;
	int			dead;
}	t_player;

typedef struct	s_Game_data
{
	t_ILX_Window	*win;
	t_ILX_Renderer	*ren;
	t_ILX_Rect		*rect;
	t_GAME_Input	*inputs;
	t_player		*player;
}	t_Game_data;

int 	input_key_down(int keycode, t_GAME_Input *inputs);
int 	input_key_up(int keycode, t_GAME_Input *inputs);

void	input(t_Game_data *game);
void	update(t_Game_data *game);
void	render(t_Game_data *game);
int		win_close(t_Game_data *game);
#endif