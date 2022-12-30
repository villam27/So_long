/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:37:14 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/30 16:02:48 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_hud	*init_hud(t_ilx_window *win)
{
	t_hud	*hud;

	hud = malloc(sizeof(t_hud));
	if (!hud)
		return (NULL);
	hud->dst_r = ilx_new_rect(0, 0, 28, 28);
	hud->life = ilx_create_texture(win, "assets/lifes.xpm");
	if (!hud->life)
		return (free(hud), NULL);
	return (hud);
}

void	destroy_hud(t_ilx_window *win, t_hud *hud)
{
	ilx_destroy_texture(win, hud->life);
	free(hud);
}

static void	life_render(t_game_data *data)
{
	t_hud		*hud;
	static int	frames;

	hud = data->hud;
	hud->pts.x = 750 - data->levels->camera_offsets.x;
	hud->pts.y = 10 - data->levels->camera_offsets.y;
	if (frames > 5)
	{
		frames = 0;
		hud->dst_r.x += 28;
		if (hud->dst_r.x > 28 * 5)
			hud->dst_r.x = 0;
	}
	frames++;
}

void	hud_render(t_game_data *data)
{
	int	i;

	i = 0;
	life_render(data);
	while (i < data->player->lifes)
	{
		ilx_render_copy(data->ren, data->hud->life,
			&data->hud->pts, &data->hud->dst_r);
		data->hud->pts.x -= 30;
		i++;
	}
}

void	hud_update(t_hud *hud)
{
	(void)hud;
}
