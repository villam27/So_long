/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:25:18 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 01:25:41 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ILX_Window.h"

int	win_close(t_ILX_Window	*window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	exit(0);
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