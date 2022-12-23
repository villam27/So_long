/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:57:48 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/23 14:27:37 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ILX_Rect.h"

t_ilx_rect	*ilx_create_rect(int x, int y, int w, int h)
{
	t_ilx_rect	*rect;

	rect = malloc(sizeof(t_ilx_rect));
	if (!rect)
		return (NULL);
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
	return (rect);
}

void	ilx_free_rect(t_ilx_rect *rect)
{
	free(rect);
}

void	ilx_draw_px(t_ilx_renderer *rend, int x, int y, int color)
{
	char	*dst;

	if (x < 800 * 10 && x > 0 && y < 600 * 10 && y > 0)
	{
		dst = rend->addr + (y * rend->line_len + x * (rend->bits_per_px >> 3));
		*(unsigned int *)dst = color;
	}
}

void	ilx_draw_rect(t_ilx_renderer *rend, t_ilx_rect rect, int color)
{
	int	w;
	int	h;

	h = 0;
	while (h < rect.h)
	{
		w = 0;
		while (w < rect.w)
		{
			ilx_draw_px(rend, rect.x + w, rect.y + h, color);
			w++;
		}
		h++;
	}
}
