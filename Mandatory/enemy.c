/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:32:42 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/28 16:20:18 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	*create_enemy(int x, int y, t_ilx_window *win)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->box = ilx_create_rect(x, y, 50, 50);
	if (!enemy->box)
		return (free(enemy), NULL);
	enemy->sprite = ilx_create_texture(win, "assets/rock.xpm");
	enemy->direction = 1;
	enemy->speed = 6;
	return (enemy);
}

void	destroy_enemy(t_enemy *enemy, t_ilx_window *win)
{
	ilx_free_rect(enemy->box);
	ilx_destroy_texture(win, enemy->sprite);
	free(enemy);
}

void	enemy_render(t_game_data *data)
{
	if (data->enemies->direction == 1)
	{
		data->enemies->box->y += data->enemies->speed;
		data->enemies->box->x -= data->enemies->speed;
	}
	if (data->enemies->direction == 2)
	{
		data->enemies->box->y += data->enemies->speed;
		data->enemies->box->x += data->enemies->speed;
	}
	if (data->enemies->direction == 3)
	{
		data->enemies->box->y -= data->enemies->speed;
		data->enemies->box->x += data->enemies->speed;
	}
	if (data->enemies->direction == 4)
	{
		data->enemies->box->y -= data->enemies->speed;
		data->enemies->box->x -= data->enemies->speed;
	}
	ilx_draw_texture(data->ren, data->enemies->box->x - 5,
		data->enemies->box->y - 5, data->enemies->sprite);
}

void	enemy_update(t_game_data *data)
{
	int	i;
	
	i = 0;
	while (data->levels->map->boxs[i])
	{
		if (ilx_intersection_rect(data->enemies->box, data->levels->map->boxs[i]))
		{
			data->enemies->direction++;
			if (data->enemies->direction > 4)
				data->enemies->direction = 1;
			return ;
		}
		i++;
	}
}
