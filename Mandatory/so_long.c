/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:10:24 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 14:24:42 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"

int input_key_down(int keycode, t_GAME_Input *inputs)
{
	if (keycode == ESC)
	{
		inputs->exit = 1;
		return (0);
	}
	if (keycode == LEFT)
		inputs->left = 1;
	if (keycode == RIGHT)
		inputs->right = 1;
	if (keycode == UP)
		inputs->up = 1;
	if (keycode == DOWN)
		inputs->down = 1;
	return (0);
}

int input_key_up(int keycode, t_GAME_Input *inputs)
{
	if (keycode == LEFT)
		inputs->left = 0;
	if (keycode == RIGHT)
		inputs->right = 0;
	if (keycode == UP)
		inputs->up = 0;
	if (keycode == DOWN)
		inputs->down = 0;
}

void	input(t_Game_data *game)
{
	player_input(game);
}

void	update(t_Game_data *game)
{
	player_update(game);
	return ;
}

void	render(t_Game_data *game)
{	
	ilx_clear_renderer(game->ren);
	ILX_draw_px(game->ren, 10, 10, 0xff0000);
	ILX_draw_rect(game->ren, *game->rect, 0xff4444);
	player_render(game);
	mlx_put_image_to_window(game->win->mlx, game->win->mlx_win,
							game->ren->img, 0, 0);
}

int		win_close(t_Game_data *game)
{
	destroy_player(game->player);
	ilx_destroy_renderer(game->win, game->ren);
	ilx_destroy_window(game->win);
	exit(EXIT_SUCCESS);
	return (0);
}
