/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Rect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:43:25 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/25 17:07:51 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILX_RECT_H
# define ILX_RECT_H
# include <mlx.h>
# include "ILX_Window.h"

typedef struct s_ilx_Point
{
	int	x;
	int	y;
}	t_ilx_point;

typedef struct s_ilx_Rect
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_ilx_rect;

t_ilx_rect	*ilx_create_rect(int x, int y, int w, int h);
t_ilx_rect	ilx_new_rect(int x, int y, int w, int h);
t_ilx_rect	**ilx_create_rects(int w, int h, int num);
void		ilx_free_rect(t_ilx_rect *rect);
void		ilx_free_rects(t_ilx_rect **rects);

int			ilx_intersection_rect(t_ilx_rect *r1, t_ilx_rect *r2);
int			ilx_vertical_align_rect(t_ilx_rect *r1, t_ilx_rect *r2);
int			ilx_horizont_align_rect(t_ilx_rect *r1, t_ilx_rect *r2);

void		ilx_draw_rect(t_ilx_renderer *rend, t_ilx_rect rect, int color);
void		ilx_draw_px(t_ilx_renderer *rend, int x, int y, int color);
#endif