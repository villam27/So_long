/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:13:28 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 12:30:32 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILX_WINDOW_H
# define ILX_WINDOW_H
# include <mlx.h>
# include "stdlib.h"

typedef struct	s_ILX_Renderer
{
	void	*img;
	char	*addr;
	int		bits_per_px;
	int		line_len;
	int		endian;
}	t_ILX_Renderer;

typedef struct s_ILX_Window
{
	void	*mlx;
	void	*mlx_win;
	int		size_x;
	int		size_y;
}	t_ILX_Window;

t_ILX_Window	*ilx_create_window(int size_x, int size_y, char *title);
void			ilx_destroy_window(t_ILX_Window *window);

t_ILX_Renderer	*ilx_create_renderer(t_ILX_Window *window);
void			ilx_destroy_renderer(t_ILX_Window *win, t_ILX_Renderer *renderer);

void			ilx_clear_renderer(t_ILX_Renderer *rend);
#endif