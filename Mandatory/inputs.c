/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:42:27 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/27 16:24:29 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_key_down(int keycode, t_game_input *inputs)
{
	if (keycode == ESC)
	{
		inputs->exit = 1;
		return (0);
	}
	if (keycode == LEFT || keycode == A)
		inputs->left = 1;
	if (keycode == RIGHT || keycode == D)
		inputs->right = 1;
	if (keycode == UP || keycode == W)
		inputs->up = 1;
	if (keycode == DOWN || keycode == X)
		inputs->down = 1;
	if (keycode == SPACE)
		inputs->jetpack = 1;
	return (0);
}

int	input_key_up(int keycode, t_game_input *inputs)
{
	if (keycode == LEFT || keycode == A)
		inputs->left = 0;
	if (keycode == RIGHT || keycode == D)
		inputs->right = 0;
	if (keycode == UP || keycode == W)
		inputs->up = 0;
	if (keycode == DOWN || keycode == X)
		inputs->down = 0;
	if (keycode == SPACE)
		inputs->jetpack = 0;
	return (0);
}
