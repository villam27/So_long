/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:10:24 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/22 22:15:19 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"

void	input(t_game_data *game)
{
	player_input(game);
}

void	update(t_game_data *game)
{
	player_update(game);
	level_update(game);
}

void	render(t_game_data *game)
{	
	ilx_clear_renderer(game->ren);
	ilx_draw_px(game->ren, 10, 10, 0xff0000);
	level_render(game);
	player_render(game);
	mlx_put_image_to_window(game->win->mlx, game->win->mlx_win,
		game->ren->img, 0, 0);
}

int	win_close(t_game_data *game)
{
	close_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
