/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:13:28 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/18 00:54:02 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILX_WINDOW_H
# define ILX_WINDOW_H
# include <mlx.h>
# include "stdlib.h"

typedef struct	s_ilx_renderer
{
	void	*img;
	char	*addr;
	int		bits_per_px;
	int		line_len;
	int		endian;
}	t_ilx_renderer;

typedef struct s_ilx_window
{
	void	*mlx;
	void	*mlx_win;
	int		size_x;
	int		size_y;
}	t_ilx_window;

t_ilx_window	*ilx_create_window(int size_x, int size_y, char *title);
void			ilx_destroy_window(t_ilx_window *window);

t_ilx_renderer	*ilx_create_renderer(t_ilx_window *window);
void			ilx_destroy_renderer(t_ilx_window *win, t_ilx_renderer *renderer);

void			ilx_clear_renderer(t_ilx_renderer *rend);
#endif