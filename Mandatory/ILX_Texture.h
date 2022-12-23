/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Texture.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:37:39 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/23 23:56:22 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILX_TEXTURE_H
# define ILX_TEXTURE_H
# include "ILX_Window.h"
# include "ILX_Rect.h"

typedef struct s_ilx_texture
{
	void	*img;
	char	*addr;
	int		bits_per_px;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_ilx_texture;

t_ilx_texture	*ilx_create_texture(t_ilx_window *win, char *path);
void			ilx_draw_texture(t_ilx_renderer *rend, int x, int y,
					t_ilx_texture *tex);
void			ilx_destroy_texture(t_ilx_window *win, t_ilx_texture *texture);

#endif