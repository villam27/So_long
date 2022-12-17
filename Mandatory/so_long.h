/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:53:59 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 01:28:03 by alboudje         ###   ########.fr       */
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

typedef struct	s_Update
{
	t_ILX_Window	*win;
	t_ILX_Renderer	*ren;
	t_ILX_Rect		*rect;
	t_GAME_Input	*inputs;
}	t_Update;

int input_key_down(int keycode, t_GAME_Input *inputs);
int input_key_up(int keycode, t_GAME_Input *inputs);
#endif