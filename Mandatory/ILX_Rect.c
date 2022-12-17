/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:57:48 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 14:57:59 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ILX_Rect.h"

t_ILX_Rect	*ilx_create_rect(int x, int y, int w, int h)
{
	t_ILX_Rect	*rect;

	rect = malloc(sizeof(t_ILX_Point));
	if (!rect)
		return (NULL);
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;

	return (rect);
}

void	ilx_free_rect(t_ILX_Rect *rect)
{
	free(rect);
}

int	ilx_intersection_rect(t_ILX_Rect *r1, t_ILX_Rect *r2)
{
	if (r1->x < r2->x + r2->w && r2->x < r1->x + r1->w &&
		r1->y < r2->y + r2->h && r2->y < r1->y + r1->h)
		return (1);
	return (0);
}

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