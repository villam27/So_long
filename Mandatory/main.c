/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:55:09 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 00:17:43 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ILX_draw_px(t_ILX_Renderer *rend, int x, int y, int color)
{
	char	*dst;

	if (x < 800 && x > 0 && y < 600 && y > 0)
	{
		dst = rend->addr + (y * rend->line_len + x * (rend->bits_per_px >> 3));
		*(unsigned int*)dst = color;
	}
}

void	ILX_draw_rect(t_ILX_Renderer *rend, t_ILX_Rect rect, int color)
{
	int	w;
	int	h;

	h = 0;
	while (h < rect.h)
	{
		w = 0;
		while (w < rect.w)
		{
			ILX_draw_px(rend, rect.x + w, rect.y + h, color);
			w++;
		}
		h++;
	}
}

void	ILX_clear_renderer(t_ILX_Renderer *rend)
{
	int	w;
	int	h;

	h = 0;
	while (h < 600)
	{
		w = 0;
		while (w < 800)
		{
			ILX_draw_px(rend, w, h, 0);
			w++;
		}
		h++;
	}
}

int	win_close(t_ILX_Window	*window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	exit(0);
}

int input_key_do(int keycode, t_GAME_Input *inputs)
{
	//printf("%p\n", inputs);
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

int	render_next_frame(t_Update *data)
{
	if (data->inputs->exit)
		win_close(data->win);
	ILX_clear_renderer(data->ren);
	ILX_draw_px(data->ren, 10, 10, 0xff0000);
	ILX_draw_rect(data->ren, *data->rect, 0xff4444);
	mlx_clear_window(data->win->mlx, data->win->mlx_win);
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
	mlx_hook(window.mlx_win, 2, 1L<<0, input_key_do, &inputs);
	mlx_hook(window.mlx_win, 3, 1L<<1, input_key_up, &inputs);
	mlx_loop_hook(window.mlx, render_next_frame, &update_data);

	mlx_loop(window.mlx);
	return (EXIT_SUCCESS);
}
