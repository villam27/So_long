/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:55:09 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/16 17:40:30 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ILX_draw_px(t_ILX_Renderer *rend, int x, int y, int color)
{
	char	*dst;

	dst = rend->addr + (y * rend->line_len + x * (rend->bits_per_px >> 3));
	*(unsigned int*)dst = color;
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

int	win_close(t_ILX_Window	*window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	exit(0);
}

int	main(void)
{
	t_ILX_Window	window;
	t_ILX_Renderer	renderer;
	t_ILX_Rect		rect = {20, 20, 100, 60};

	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, 800, 600, "MLX");
	renderer.img = mlx_new_image(window.mlx, 800, 600);
	renderer.addr = mlx_get_data_addr(renderer.img, &renderer.bits_per_px, 
							&renderer.line_len, &renderer.endian);
	ILX_draw_px(&renderer, 10, 10, 0xff0000);
	ILX_draw_rect(&renderer, rect, 0xff4444);
	mlx_put_image_to_window(window.mlx, window.mlx_win, renderer.img, 0, 0);
	mlx_hook(window.mlx_win, 17, 0, win_close, &window);
	mlx_loop(window.mlx);
	return (EXIT_SUCCESS);
}
