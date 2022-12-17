/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:57:48 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 00:58:17 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ILX_Rect.h"

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