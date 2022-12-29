/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:20:30 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/29 16:00:11 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	**create_enemies(int number, t_ilx_window *win)
{
	t_enemy	**enemies;
	int		i;

	i = 0;
	enemies = malloc(sizeof(t_enemy *) * (number + 1));
	if (!enemies)
		return (NULL);
	while (i < number)
	{
		enemies[i] = create_enemy(64 + (i * 5), 64 + (i * 10), win);
		if (!enemies)
			return (destroy_enemies(enemies, win), NULL);
		i++;
	}
	enemies[i] = NULL;
	return (enemies);
}

void	destroy_enemies(t_enemy **enemies, t_ilx_window *win)
{
	int	i;

	i = 0;
	while (enemies[i])
	{
		destroy_enemy(enemies[i], win);
		i++;
	}
	free(enemies);
}

void	set_all_pos(t_game_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < data->levels->map->data->cols)
	{
		j = 0;
		while (j < data->levels->map->data->rows)
		{
			if (data->levels->map->map[j][i] == 'A')
			{
				enemy_set_position(data->enemies[k], i * 64, j * 64);
				k++;
			}
			j++;
		}
		i++;
	}
}
