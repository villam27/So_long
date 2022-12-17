/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:55:09 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 01:12:34 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_Update *data)
{
	if (data->inputs->exit)
		win_close(data->win);
	ILX_clear_renderer(data->ren);
	ILX_draw_px(data->ren, 10, 10, 0xff0000);
	ILX_draw_rect(data->ren, *data->rect, 0xff4444);
	mlx_put_image_to_window(data->win->mlx, data->win->mlx_win, data->ren->img, 0, 0);
	if (data->inputs->left == 1)
		data->rect->x -= 1;
	if (data->inputs->right == 1)
		data->rect->x += 1;
	if (data->inputs->up == 1)
		data->rect->y -= 1;
	if (data->inputs->down == 1)
		data->rect->y += 1;
	return (0);
}

int	main(void)
{
	t_ILX_Window	window;
	t_ILX_Renderer	renderer;
	t_ILX_Rect		rect = {20, 20, 50, 50};
	t_GAME_Input	inputs = {0, 0, 0, 0, 0};
	t_Update		update_data;

	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, 800, 600, "MLX");
	renderer.img = mlx_new_image(window.mlx, 800, 600);
	renderer.addr = mlx_get_data_addr(renderer.img, &renderer.bits_per_px, 
							&renderer.line_len, &renderer.endian);
	ILX_draw_px(&renderer, 10, 10, 0xff0000);
	ILX_draw_rect(&renderer, rect, 0xff4444);
	mlx_put_image_to_window(window.mlx, window.mlx_win, renderer.img, 0, 0);
	update_data.win = &window;
	update_data.ren = &renderer;
	update_data.rect = &rect;
	update_data.inputs = &inputs;
	mlx_hook(window.mlx_win, 17, 0, win_close, &window);
	mlx_hook(window.mlx_win, 2, 1L<<0, input_key_down, &inputs);
	mlx_hook(window.mlx_win, 3, 1L<<1, input_key_up, &inputs);
	mlx_loop_hook(window.mlx, render_next_frame, &update_data);
	mlx_loop(window.mlx);
	return (EXIT_SUCCESS);
}
