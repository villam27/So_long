/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:55:09 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/21 00:04:33 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"
#include "map.h"

static int	next_frame(t_game_data *data)
{
	if (data->inputs->exit)
		win_close(data);
	input(data);
	update(data);
	render(data);
	return (0);
}

static int	init_all(t_game_data **game, t_game_input *in)
{
	t_ilx_window	*win;
	t_ilx_renderer	*ren;
	win = ilx_create_window(800, 600, "so_long");
	if (!(win))
		return (1);
	ren = ilx_create_renderer(win);
	if (!(ren))
	{
		ilx_destroy_window(win);
		return (1);
	}
	*game = ini_game(win, ren, in);
	if (!(*game))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game_input	inputs = {0, 0, 0, 0, 0};
	t_game_data		*game;

	if (!init_all(&game, &inputs))
	{
		mlx_hook(game->win->mlx_win, 17, 0, win_close, game);
		mlx_hook(game->win->mlx_win, 2, 1L << 0, input_key_down, &inputs);
		mlx_hook(game->win->mlx_win, 3, 1L << 1, input_key_up, &inputs);
		mlx_loop_hook(game->win->mlx, next_frame, game);
		mlx_loop(game->win->mlx);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
