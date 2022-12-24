/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:19:18 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/24 12:58:51 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ILX_Texture.h"

t_ilx_texture	*ilx_create_texture(t_ilx_window *window, char *path)
{
	t_ilx_texture	*sprite;

	sprite = malloc(sizeof(t_ilx_texture));
	if (!sprite)
		return (NULL);
	sprite->img = mlx_xpm_file_to_image(window->mlx, path,
			&sprite->w, &sprite->h);
	if (!sprite->img)
		return (free(sprite), NULL);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bits_per_px,
			&sprite->line_len, &sprite->endian);
	if (!sprite->addr)
		return ((void)mlx_destroy_image(window->mlx, sprite->img), NULL);
	return (sprite);
}

void	ilx_draw_texture(t_ilx_renderer *rend, int x, int y,
			t_ilx_texture *tex)
{
	char	*dst;
	char	*src;
	int		i;
	int		j;

	i = 0;
	while (i < tex->h)
	{
		j = 0;
		while (j < tex->w)
		{
			if (x < 800 * 10 && x > 0 && y < 600 * 10 && y > 0)
			{
				dst = (rend->addr + ((y + i) * rend->line_len + (x + j)
							*(rend->bits_per_px >> 3)));
				src = (tex->addr + (i * tex->line_len + j
							*(tex->bits_per_px >> 3)));
				if (*(unsigned *)src != 0xff000000)
						*(unsigned long *)dst = *(unsigned long *)src;
			}
			j++;
		}
		i++;
	}
}

void	ilx_render_copy(t_ilx_renderer *rend, t_ilx_texture *tex,
			t_ilx_point *pos, t_ilx_rect *rec)
{
	char		*dst;
	char		*src;
	int			i;
	int			j;

	i = 0;
	while (i < rec->h)
	{
		j = 0;
		while (j < rec->w)
		{
			if ((pos->x < 800 * 10 && pos->x > 0 && pos->y < 600 * 10 && pos->y > 0)
				&& (rec->x + j < tex->w && rec->x + j > 0
					&& rec->y + i < tex->h && rec->y + i > 0))
			{
				dst = (rend->addr + ((pos->y + i) * rend->line_len + (pos->x + j)
							*(rend->bits_per_px >> 3)));
				src = (tex->addr + ((rec->y + i) * tex->line_len + (rec->x + j)
							*(tex->bits_per_px >> 3)));
				if (*(unsigned *)src != 0xff000000)
						*(unsigned long *)dst = *(unsigned long *)src;
			}
			j++;
		}
		i++;
	}
}

void	ilx_destroy_texture(t_ilx_window *win, t_ilx_texture *texture)
{
	mlx_destroy_image(win->mlx, texture->img);
	free(texture);
}
