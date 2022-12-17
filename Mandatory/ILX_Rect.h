/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Rect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:43:25 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 01:15:28 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILX_RECT_H
# define ILX_RECT_H
# include <mlx.h>
# include "ILX_Window.h"

typedef struct	s_ILX_Point
{
	int	x;
	int	y;
}	t_ILX_Point;

typedef struct	s_ILX_Rect
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_ILX_Rect;

void	ILX_draw_rect(t_ILX_Renderer *rend, t_ILX_Rect rect, int color);
void	ILX_draw_px(t_ILX_Renderer *rend, int x, int y, int color);
#endif