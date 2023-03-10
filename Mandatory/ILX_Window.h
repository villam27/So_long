/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:13:28 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/27 14:48:42 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILX_WINDOW_H
# define ILX_WINDOW_H
# define MAX_MAP 6000
# include <mlx.h>
# include "stdlib.h"

typedef struct s_game_data	t_game_data;

typedef struct s_ilx_renderer
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
void			ilx_destroy_renderer(t_ilx_window *win, t_ilx_renderer *ren);

void			ilx_clear_renderer(t_ilx_renderer *ren, int c_x, int c_y);
#endif