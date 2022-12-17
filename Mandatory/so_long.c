/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:10:24 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/17 01:16:36 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int input_key_down(int keycode, t_GAME_Input *inputs)
{
	if (keycode == ESC)
	{
		inputs->exit = 1;
		return (0);
	}
	if (keycode == LEFT)
		inputs->left = 1;
	if (keycode == RIGHT)
		inputs->right = 1;
	if (keycode == UP)
		inputs->up = 1;
	if (keycode == DOWN)
		inputs->down = 1;
	return (0);
}

int input_key_up(int keycode, t_GAME_Input *inputs)
{
	if (keycode == LEFT)
		inputs->left = 0;
	if (keycode == RIGHT)
		inputs->right = 0;
	if (keycode == UP)
		inputs->up = 0;
	if (keycode == DOWN)
		inputs->down = 0;
}