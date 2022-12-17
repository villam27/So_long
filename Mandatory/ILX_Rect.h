/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Rect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:43:25 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 15:38:41 by alboudje         ###   ########.fr       */
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

t_ILX_Rect	*ilx_create_rect(int x, int y, int w, int h);
void		ilx_free_rect(t_ILX_Rect *rect);

int			ilx_intersection_rect(t_ILX_Rect *r1, t_ILX_Rect *r2);
int			ilx_vertical_align_rect(t_ILX_Rect *r1, t_ILX_Rect *r2);
int			ilx_horizont_align_rect(t_ILX_Rect *r1, t_ILX_Rect *r2);

void		ILX_draw_rect(t_ILX_Renderer *rend, t_ILX_Rect rect, int color);
void		ILX_draw_px(t_ILX_Renderer *rend, int x, int y, int color);
#endif