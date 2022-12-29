/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:32:42 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/29 15:59:49 by alboudje         ###   ########.fr       */
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

void	enemy_set_position(t_enemy *enemy, int x, int y)
{
	enemy->box->x = x;
	enemy->box->y = y;
}

void	enemy_render(t_game_data *data, t_enemy *enemy)
{
	if (enemy->direction == 1)
	{
		enemy->box->y += enemy->speed;
		enemy->box->x -= enemy->speed;
	}
	if (enemy->direction == 2)
	{
		enemy->box->y += enemy->speed;
		enemy->box->x += enemy->speed;
	}
	if (enemy->direction == 3)
	{
		enemy->box->y -= enemy->speed;
		enemy->box->x += enemy->speed;
	}
	if (enemy->direction == 4)
	{
		enemy->box->y -= enemy->speed;
		enemy->box->x -= enemy->speed;
	}
	ilx_draw_texture(data->ren, enemy->box->x - 5,
		enemy->box->y - 5, enemy->sprite);
}

void	enemy_update(t_game_data *data, t_enemy *enemy)
{
	int	i;

	i = 0;
	while (data->levels->map->boxs[i])
	{
		if (ilx_intersection_rect(enemy->box, data->levels->map->boxs[i]))
		{
			enemy->direction++;
			if (enemy->direction > 4)
				enemy->direction = 1;
			return ;
		}
		i++;
	}
}
