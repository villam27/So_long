/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:13:28 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 01:14:13 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILX_WINDOW_H
# define ILX_WINDOW_H
# include <mlx.h>

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
}	t_ILX_Window;

void	ILX_clear_renderer(t_ILX_Renderer *rend);
int		win_close(t_ILX_Window	*window);
#endif