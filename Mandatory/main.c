/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:55:09 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/18 12:15:49 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"

static int next_frame(t_game_data *data)
{
	if (data->inputs->exit)
		win_close(data);
	input(data);
	update(data);
	render(data);
	return (0);
}

int	main(void)
{
	t_ilx_window	*window;
	t_ilx_renderer	*renderer;
	t_ilx_rect		rect = {20, 500, 600, 50};
	t_game_input	inputs = {0, 0, 0, 0, 0};
	t_game_data		*game;

	window = ilx_create_window(800, 600, "so_long");
	renderer = ilx_create_renderer(window);
	game = ini_game(window, renderer, &inputs);
//	update_data.win = window;
//	update_data.ren = renderer;
//	update_data.rect = &rect;
//	update_data.inputs = &inputs;
//	update_data.player = create_player();
	mlx_hook(window->mlx_win, 17, 0, win_close, game);
	mlx_hook(window->mlx_win, 2, 1L<<0, input_key_down, &inputs);
	mlx_hook(window->mlx_win, 3, 1L<<1, input_key_up, &inputs);
	mlx_loop_hook(window->mlx, next_frame, game);
	mlx_loop(window->mlx);
	return (EXIT_SUCCESS);
}
