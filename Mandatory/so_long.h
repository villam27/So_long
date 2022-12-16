/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:53:59 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/16 17:17:55 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"

typedef struct	s_ILX_Renderer {
	void	*img;
	char	*addr;
	int		bits_per_px;
	int		line_len;
	int		endian;
}	t_ILX_Renderer;

typedef struct	s_ILX_Rect
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_ILX_Rect;


void	ILX_draw_px(t_ILX_Renderer *rend, int x, int y, int color);
void	ILX_draw_rect(t_ILX_Renderer *rend, t_ILX_Rect rect, int color);

#endif