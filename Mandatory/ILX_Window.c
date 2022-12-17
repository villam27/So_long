/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:25:18 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 14:42:53 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ILX_Window.h"

t_ILX_Window	*ilx_create_window(int size_x, int size_y, char *title)
{
	t_ILX_Window	*window;

	window = malloc(sizeof(t_ILX_Window));
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, size_x, size_y, title);
	window->size_x = size_x;
	window->size_y = size_y;
	return (window);
}

void	ilx_destroy_window(t_ILX_Window *window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	free(window);
}

t_ILX_Renderer	*ilx_create_renderer(t_ILX_Window *window)
{
	t_ILX_Renderer	*renderer;

	renderer = malloc(sizeof(t_ILX_Renderer));
	if (!renderer)
		return (NULL);
	renderer->img = mlx_new_image(window->mlx, window->size_x, window->size_y);
	renderer->addr = mlx_get_data_addr(renderer->img, &renderer->bits_per_px,
									&renderer->line_len, &renderer->endian);
	return (renderer);
}

void	ilx_destroy_renderer(t_ILX_Window *win, t_ILX_Renderer *renderer)
{
	mlx_destroy_image(win->mlx, renderer->img);
	free(renderer);	
}

void	ilx_clear_renderer(t_ILX_Renderer *rend)
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