/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:25:18 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/22 15:40:16 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ILX_Window.h"

t_ilx_window	*ilx_create_window(int size_x, int size_y, char *title)
{
	t_ilx_window	*window;

	window = malloc(sizeof(t_ilx_window));
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	if (!window->mlx)
		return (free(window), NULL);
	window->mlx_win = mlx_new_window(window->mlx, size_x, size_y, title);
	if (!window->mlx_win)
		return (free(window->mlx), free(window), NULL);
	window->size_x = size_x;
	window->size_y = size_y;
	return (window);
}

void	ilx_destroy_window(t_ilx_window *window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	free(window);
}

t_ilx_renderer	*ilx_create_renderer(t_ilx_window *window)
{
	t_ilx_renderer	*renderer;

	renderer = malloc(sizeof(t_ilx_renderer));
	if (!renderer)
		return (NULL);
	renderer->img = mlx_new_image(window->mlx, window->size_x, window->size_y);
	if (!renderer->img)
		return (free(renderer), NULL);
	renderer->addr = mlx_get_data_addr(renderer->img, &renderer->bits_per_px,
			&renderer->line_len, &renderer->endian);
	if (!renderer->addr)
		return ((void)mlx_destroy_image(window->mlx, renderer->img), NULL);
	return (renderer);
}

void	ilx_destroy_renderer(t_ilx_window *win, t_ilx_renderer *renderer)
{
	mlx_destroy_image(win->mlx, renderer->img);
	free(renderer);
}

void	ilx_clear_renderer(t_ilx_renderer *rend)
{
	int	w;
	int	h;

	h = 0;
	while (h < 600)
	{
		w = 0;
		while (w < 800)
		{
			ilx_draw_px(rend, w, h, 0);
			w++;
		}
		h++;
	}
}
