/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:55:09 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 14:22:45 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"

static int next_frame(t_Game_data *data)
{
	if (data->inputs->exit)
		win_close(data);
	input(data);
	render(data);
	update(data);
	return (0);
}

int	main(void)
{
	t_ILX_Window	*window;
	t_ILX_Renderer	*renderer;
	t_ILX_Rect		rect = {20, 20, 50, 50};
	t_GAME_Input	inputs = {0, 0, 0, 0, 0};
	t_Game_data		update_data;

	window = ilx_create_window(800, 600, "so_long");
	renderer = ilx_create_renderer(window);
	update_data.win = window;
	update_data.ren = renderer;
	update_data.rect = &rect;
	update_data.inputs = &inputs;
	update_data.player = create_player();
	mlx_hook(window->mlx_win, 17, 0, win_close, &update_data);
	mlx_hook(window->mlx_win, 2, 1L<<0, input_key_down, &inputs);
	mlx_hook(window->mlx_win, 3, 1L<<1, input_key_up, &inputs);
	mlx_loop_hook(window->mlx, next_frame, &update_data);
	mlx_loop(window->mlx);
	return (EXIT_SUCCESS);
}
